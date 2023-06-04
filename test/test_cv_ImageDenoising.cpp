#include <opencv2/opencv.hpp>
#include <string>
#include <vector>
#include <algorithm>
#include "common/log.h"
#include "test.h"

namespace TEST
{

static std::vector<std::vector<unsigned char>> custom_MedianFilter(std::vector<std::vector<unsigned char>>& src_array, int kernel_size){

    int height = src_array.size();
    int width = src_array[0].size();

    int half_kernel_size = kernel_size / 2;

    std::vector<std::vector<unsigned char>> dst_array(height, std::vector<unsigned char>(width, 0));
    for(size_t row = 0; row < height; row++){
        for(size_t col = 0; col < width; col++){
            std::vector<unsigned char> pixels;
            for(int i = row-half_kernel_size; i <= row+half_kernel_size; i++){
                for(int j = col-half_kernel_size; j <= col+half_kernel_size; j++){
                    if(i < 0 || i >= height || j < 0 || j >= width) continue;
                    pixels.push_back(src_array[i][j]);
                }
            }
            std::sort(pixels.begin(), pixels.end());
            dst_array[row][col] = pixels[pixels.size()/2];
        }
    }

    return dst_array;
}

static cv::Mat custom_GaussianFilter(cv::Mat& srcimg, int kernel_size, double sigma){
    // 计算高斯核
    cv::Mat kernel = cv::Mat::zeros(kernel_size, kernel_size, CV_64FC1);
    double sum = 0;
    int center = kernel_size / 2;
    for(int i = 0; i < kernel_size; i++){
        for(int j = 0; j < kernel_size; j++){
            int x = i - center;
            int y = j - center;
            kernel.at<double>(i, j) = exp(-(x*x + y*y)/(2*sigma*sigma));
            sum += kernel.at<double>(i, j);
        }
    }
    kernel /= sum;

    // 对图像进行卷积
    cv::Mat dstimg = cv::Mat::zeros(srcimg.size(), srcimg.type());
    for(int row = center; row < srcimg.rows-center; row++){
        for(int col = center; col < srcimg.cols-center; col++){
            double sum_r=0, sum_g=0, sum_b=0;
            for(int m = -center; m <= center; m++){
                for(int n = -center; n <= center; n++){
                    int x = row + m;
                    int y = col + n;
                    sum_r += srcimg.at<cv::Vec3b>(x, y)[0] * kernel.at<double>(center+m, center+n);
                    sum_g += srcimg.at<cv::Vec3b>(x, y)[1] * kernel.at<double>(center+m, center+n);
                    sum_b += srcimg.at<cv::Vec3b>(x, y)[2] * kernel.at<double>(center+m, center+n);
                }
            }
            dstimg.at<cv::Vec3b>(row, col)[0] =  cv::saturate_cast<uchar>(sum_r);
            dstimg.at<cv::Vec3b>(row, col)[1] =  cv::saturate_cast<uchar>(sum_g);
            dstimg.at<cv::Vec3b>(row, col)[2] =  cv::saturate_cast<uchar>(sum_b);
        }
    }

    return dstimg;
}

static cv::Mat custom_MeanFilter(const cv::Mat& srcimg, int kernel_size){
    cv::Mat dstimg = cv::Mat::zeros(srcimg.size(), srcimg.type());
    int center = kernel_size / 2;
    for(int row = center; row < srcimg.rows-center; row++){
        for(int col = center; col < srcimg.cols; col++){
            int sum_r=0, sum_g=0, sum_b=0;
            for(int i = -center; i <= center; i++){
                for(int j = -center; j <= center; j++){
                    int m = row + i;
                    int n = col + j;
                    sum_r += srcimg.at<cv::Vec3b>(m, n)[0];
                    sum_g += srcimg.at<cv::Vec3b>(m, n)[1];
                    sum_b += srcimg.at<cv::Vec3b>(m, n)[2];
                }
            }
            dstimg.at<cv::Vec3b>(row, col)[0] = cv::saturate_cast<uchar>(sum_r / kernel_size /kernel_size);
            dstimg.at<cv::Vec3b>(row, col)[1] = cv::saturate_cast<uchar>(sum_g / kernel_size /kernel_size);
            dstimg.at<cv::Vec3b>(row, col)[2] = cv::saturate_cast<uchar>(sum_b / kernel_size /kernel_size);
        }
    }
    return dstimg;
}
    
// cv中常见的图像降噪算法
int test_cv_ImageDenoising(){
    TITLE("=== test_cv_ImageDenoising() ===");

    std::string imgsrcpath{"/e/QDWorkplace/data/lena.png"};
    std::string imgdstpath{"/e/QDWorkplace/code/QCV/temp/ImageDenoising.jpg"};
    std::string method{"blur"}; // "medianBlur"中值滤波, "GaussianBlur"高斯滤波, "blur"均值滤波
    
    cv::Mat srcimg = cv::imread(imgsrcpath);
    if(srcimg.empty()){
        ERROR("imread %s fail!", imgsrcpath.c_str());
        return TEST_FLAG_FETAL;
    }

    cv::Mat dstimg;

    //################################################################

    // 中值滤波
    if(method == "medianBlur"){// 中值滤波
        cv::medianBlur(srcimg, dstimg, 5); // 卷积核大小为5x5
    }else if(method == "GaussianBlur"){ // 高斯滤波
        // cv::GaussianBlur(srcimg, dstimg, cv::Size(5, 5), 1.5);
        dstimg = custom_GaussianFilter(srcimg, 5, 1.5);
    }else if(method == "blur"){ // 均值滤波
        // cv::blur(srcimg, dstimg, cv::Size(5, 5));
        dstimg = custom_MeanFilter(srcimg, 5);
    }
    else{
        ERROR("Unsupported Type: %s", method.c_str());
        return TEST_FLAG_BAD_PARAMETER;
    }

    //################################################################

    cv::imwrite(imgdstpath, dstimg);

    return TEST_FLAG_SUCCESSFUL;
}

} // namespace TEST
