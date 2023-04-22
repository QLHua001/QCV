#include <opencv2/opencv.hpp>
#include "QAlgo.h"

namespace QAlgo
{
    
void cv_mosaic(cv::Mat original_image, int block_size){

    // 获取原图的宽和高
    int original_image_width = original_image.cols;
    int original_image_height = original_image.rows;
    // 计算块数
    int block_count_x = original_image_width / block_size;
    int block_count_y = original_image_height / block_size;
    
    // 遍历所有块
    for (int x = 0; x < block_count_x; x++) {
        for (int y = 0; y < block_count_y; y++) {
            // 计算当前块的起始点坐标
            int block_start_x = x * block_size;
            int block_start_y = y * block_size;
            // 定义颜色块变量，初值为0
            //! 在 OpenCV 中，cv::Scalar 是一个四元组（R，G，B，A）的向量，分别表示颜色的红、绿、蓝和透明度通道的值（当然，有些情况下可能是其他用处）。
            cv::Scalar color_block = cv::Scalar(0, 0, 0);
            // 计算当前块内所有像素点颜色平均值
            for (int i = block_start_x; i < block_start_x + block_size; i++) {
                for (int j = block_start_y; j < block_start_y + block_size; j++) {
                    // 读取像素点颜色
                    cv::Scalar pixel_color = original_image.at<cv::Vec3b>(j, i);
                    // 累加颜色值
                    color_block += pixel_color;
                }
            }
            // 计算块内颜色平均值
            cv::Scalar average_color = color_block / (block_size * block_size);
            // 设置当前块内所有像素点的颜色为块内颜色平均值
            for (int i = block_start_x; i < block_start_x + block_size; i++) {
                for (int j = block_start_y; j < block_start_y + block_size; j++) {
                    original_image.at<cv::Vec3b>(j, i)[0] = average_color[0];
                    original_image.at<cv::Vec3b>(j, i)[1] = average_color[1];
                    original_image.at<cv::Vec3b>(j, i)[2] = average_color[2];
                    // original_image.at<cv::Vec3b>(j, i) = average_color;
                }
             }
        }
    }
}

} // namespace QAlgo
