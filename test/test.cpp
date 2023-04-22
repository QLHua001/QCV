#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

#include "common/log.h"
#include "test.h"

namespace TEST
{
    
int test(){

    std::string imgpath{"/e/QDWorkplace/code/QCV/imgs/test001.jpg"};

    cv::Mat srcimg = cv::imread(imgpath);
    if(srcimg.empty()){
        ERROR("imread %s fail!", imgpath.c_str());
        return TEST_FLAG_NULL_POINTER;
    }
    int srcimg_w = srcimg.cols;
    int srcimg_h = srcimg.rows;

    return 0;
}

} // namespace TEST
