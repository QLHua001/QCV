#include "QAlgo.h"

namespace QAlgo{

//! 直方图均衡化(Histogram Equalization)是一种增强图像对比度(Image Contrast)的方法，
//! 其主要思想是将一副图像的直方图分布通过累积分布函数变成近似均匀分布，从而增强图像的对比度。

//!直方图均衡化是一种常见的图像增强技术，其原理是通过调整图像像素的亮度分布，使得图像中的亮度值更加均匀，从而增强图像的对比度。具体而言，直方图均衡化的过程如下：
//!
//!统计图像的像素灰度值分布，得到原始图像的灰度直方图。
//!对灰度直方图进行归一化处理，将灰度值范围映射到[0,1]的区间内。
//!计算累积分布函数(CDF)，即将归一化直方图中的每个灰度级与前面所有灰度级的归一化值相加得到的函数。
//!将CDF映射到灰度级范围内，得到新的灰度级映射表。
//!对原始图像中的每一个像素，查找其灰度级对应的新灰度级并用新灰度级替换原始灰度级，得到均衡化后的图像。
//!直方图均衡化可用于增强图像的对比度，使图像更加清晰明亮。但是，它也可能会导致一些副作用，例如增强噪声和细节，使得图片看起来过于人工。因此，在使用直方图均衡化时需要根据具体情况进行选择。
void cv_equalize_hist(const cv::Mat& srcimg, cv::Mat& dstimg){

    // 计算图像直方图
    int hist[256] = {0}; // 直方图数组
    int total_pixels = srcimg.rows * srcimg.cols; // 图像总像素数
    for (int i = 0; i < srcimg.rows; i++)
    {
        for (int j = 0; j < srcimg.cols; j++)
        {
            int pixel_val = (int)srcimg.at<uchar>(i, j); // 获取像素值
            hist[pixel_val]++; // 直方图计数器加一
        }
    }

    // 计算直方图均衡化的累计分布函数
    float cdf[256] = {0}; // 累计分布函数数组
    float pdf[256] = {0}; // 概率密度函数数组
    for (int i = 0; i < 256; i++)
    {
        pdf[i] = (float)hist[i] / total_pixels; // 计算概率密度函数
        if (i == 0)
        {
            cdf[i] = pdf[i]; // 计算累计分布函数
        }
        else
        {
            cdf[i] = cdf[i-1] + pdf[i]; // 计算累计分布函数
        }
    }

    // 进行直方图均衡化
    dstimg = cv::Mat(srcimg.rows, srcimg.cols, CV_8U); // 创建输出图像
    for (int i = 0; i < srcimg.rows; i++)
    {
        for (int j = 0; j < srcimg.cols; j++)
        {
            int pixel_val = (int)srcimg.at<uchar>(i, j); // 获取像素值
            dstimg.at<uchar>(i, j) = (uchar)(cdf[pixel_val]*255+0.5); // 进行直方图均衡化
        }
    }

}

}