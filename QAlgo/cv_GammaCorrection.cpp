#include <opencv2/opencv.hpp>

#include "common/log.h"
#include "QAlgo.h"


namespace QAlgo
{

// Gamma校正
void cv_GammaCorrection(const cv::Mat& src, cv::Mat& dst, float gamma){

    cv::Mat lut(1, 256, CV_8U);

    // 计算gamma校正的lut表
    for(int i = 0; i < 256; i++){
        lut.at<uchar>(i) = cv::saturate_cast<uchar>(std::pow(i/255.0, gamma) * 255.0); 
    }

    // 应用LUT 对图像进行gamma校正
    cv::LUT(src, lut, dst);

}

} // namespace QAlgo
