#include <opencv2/opencv.hpp>
#include "common/log.h"
#include "test.h"

namespace TEST
{

static int opencv_Laplacian(){
    std::string srcimgpath{"/e/QDWorkplace/code/QCV/imgs/test001.jpg"};

    cv::Mat srcimg = cv::imread(srcimgpath, cv::IMREAD_GRAYSCALE); //！以灰度图方式读入图片
    if(srcimg.empty()){
        ERROR("imread %s fail!", srcimgpath.c_str());
        return TEST_FLAG_NULL_POINTER;
    }

    // #1 先进行图像平滑
    cv::Mat blurred_img;
    cv::GaussianBlur(srcimg, blurred_img, cv::Size(3, 3), 0);

    // #2 Laplacian变换
    cv::Mat laplacian_img;
    cv::Laplacian(blurred_img, laplacian_img, CV_16S, 3);
    cv::imwrite("./temp/laplacian_img.jpg", laplacian_img);

    // #3 将拉普拉斯图像转换为8位无符号整数类型
    cv::Mat laplacian_img_8u;
    cv::convertScaleAbs(laplacian_img, laplacian_img_8u);

    // #4 将laplacian图像与源图像相加
    cv::Mat dstimg;
    cv::addWeighted(srcimg, 1, laplacian_img_8u, -1, 0, dstimg);

    cv::imwrite("./temp/opencv_Laplacian.jpg", dstimg);

    return 0;
}

static int custom_Laplacian(){
    std::string srcimgpath{"/e/QDWorkplace/code/QCV/imgs/test001.jpg"};

    cv::Mat srcimg = cv::imread(srcimgpath, cv::IMREAD_GRAYSCALE); //！以灰度图方式读入图片
    if(srcimg.empty()){
        ERROR("imread %s fail!", srcimgpath.c_str());
        return TEST_FLAG_NULL_POINTER;
    }

    // #1 先进行图像平滑
    cv::GaussianBlur(srcimg, srcimg, cv::Size(3, 3), 0);

    // #1 定义拉普拉斯算子
    int laplacian_kernel[3][3] = {{0 ,1, 0}, {1, -4, 1}, {0, 1, 0}};

    // #2 定义输出图像
    cv::Mat dstimg = cv::Mat::zeros(srcimg.size(), srcimg.type());

    // #3 遍历原图的每个像素进行laplacian变换
    for(int row = 1; row < srcimg.rows-1; row++){
        for(int col = 1; col < srcimg.cols-1; col++){
            int sum = 0;
            for(int i = -1; i <= 1; i++){
                for(int j = -1; j <= 1; j++){
                    int pixel = srcimg.at<uchar>(row+i, col+j);
                    sum += (pixel * laplacian_kernel[1+i][1+j]);
                }
            }
            dstimg.at<uchar>(row, col) = cv::saturate_cast<uchar>(sum);
        }
    }
    cv::imwrite("./temp/custom_Laplacian_1.jpg", dstimg);

    // 对拉普拉斯变换结果进行二值化处理
    cv::Mat binary;
    threshold(dstimg, binary, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);

    cv::addWeighted(srcimg, 1, binary, -1, 0, dstimg);

    cv::imwrite("./temp/custom_Laplacian_2.jpg", dstimg);

    return 0;
}
    
int test_cv_Laplacian(){
    // opencv_Laplacian();

    custom_Laplacian();
    return 0;
}

} // namespace TEST
