#include <opencv2/opencv.hpp>
#include <string>
#include "common/log.h"
#include "test.h"

namespace TEST
{

// custom medianblur
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// // 定义中值滤波函数
// vector<vector<int>> medianFilter(vector<vector<int>>& img, int kernel_size) {
//     // 获取图像的行数和列数
//     int rows = img.size();
//     int cols = img[0].size();

//     // 定义一个二维数组，用于存储中值滤波后的图像
//     vector<vector<int>> filtered_img(rows, vector<int>(cols, 0));

//     // 计算 kernel_size 的一半
//     int half_kernel_size = (kernel_size - 1) / 2;

//     // 对于每个像素，进行中值滤波
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             // 定义一个一维数组，用于存储像素点周围 kernel_size x kernel_size 的像素值
//             vector<int> pixels;

//             // 遍历像素点周围 kernel_size x kernel_size 的像素
//             for (int m = -half_kernel_size; m <= half_kernel_size; m++) {
//                 for (int n = -half_kernel_size; n <= half_kernel_size; n++) {
//                     // 获取当前像素点的行和列
//                     int row = i + m;
//                     int col = j + n;

//                     // 如果当前像素点越界，则跳过
//                     if (row < 0 || row >= rows || col < 0 || col >= cols) {
//                         continue;
//                     }

//                     // 将当前像素点的值加入到数组 pixels 中
//                     pixels.push_back(img[row][col]);
//                 }
//             }

//             // 对数组 pixels 进行排序，取中间的值作为当前像素点的值
//             sort(pixels.begin(), pixels.end());
//             int median = pixels[pixels.size() / 2];

//             // 将中值赋给当前像素点
//             filtered_img[i][j] = median;
//         }
//     }

//     // 返回中值滤波后的图像
//     return filtered_img;
// }

// int main() {
//     // 定义一个二维数组，表示图像像素点的灰度值
//     vector<vector<int>> img = {
//         {10, 20, 30, 40, 50},
//         {15, 25, 35, 45, 55},
//         {23, 33, 43, 53, 63},
//         {28, 38, 48, 58, 68},
//         {33, 43, 53, 63, 73}
//     };

//     // 使用中值滤波函数进行滤波
//     vector<vector<int>> filtered_img = medianFilter(img, 3);

//     // 输出滤波前后的图像
//     cout << "Original Image:" << endl;
//     for (int i = 0; i < img.size(); i++) {
//         for (int j = 0; j < img[0].size(); j++) {
//             cout << img[i][j] << " ";
//         }
//         cout << endl;
//     }

//     cout << "Filtered Image:" << endl;
//     for (int i = 0; i < filtered_img.size(); i++) {
//         for (int j = 0; j < filtered_img[0].size(); j++) {
//             cout << filtered_img[i][j] << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }
    
// cv中常见的图像降噪算法
int test_cv_ImageDenoising(){
    TITLE("=== test_cv_ImageDenoising() ===");

    std::string imgsrcpath{"/e/QDWorkplace/data/lena.png"};
    std::string imgdstpath{"/e/QDWorkplace/code/QCV/temp/ImageDenoising.jpg"};
    std::string method{"medianBlur"};
    
    cv::Mat srcimg = cv::imread(imgsrcpath);
    if(srcimg.empty()){
        ERROR("imread %s fail!", imgsrcpath.c_str());
        return TEST_FLAG_FETAL;
    }

    cv::Mat dstimg;

    //################################################################

    // 中值滤波
    if(method == "medianBlur"){
        cv::medianBlur(srcimg, dstimg, 5); // 卷积核大小为5x5
    }else{
        ERROR("Unsupported Type: %s", method.c_str());
        return TEST_FLAG_BAD_PARAMETER;
    }

    //################################################################

    cv::imwrite(imgdstpath, dstimg);

    return TEST_FLAG_SUCCESSFUL;
}

} // namespace TEST
