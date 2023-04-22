#include <string>
#include <opencv2/opencv.hpp>
#include "common/log.h"
#include "test.h"
#include "QAlgo/QAlgo.h"

namespace TEST{

int test_cv_mosaic(){

    std::string imgpath{"/e/QDWorkplace/code/QCV/imgs/test001.jpg"};


    cv::Mat srcimg = cv::imread(imgpath);
    if(srcimg.empty()){
        ERROR("imread %s fail!", imgpath.c_str());
        return TEST_FLAG_NULL_POINTER;
    }
    int srcimg_w = srcimg.cols;
    int srcimg_h = srcimg.rows;

    QAlgo::cv_mosaic(srcimg, 10);
    
    cv::imwrite("./temp/srcimg.jpg", srcimg);

    return TEST_FLAG_SUCCESSFUL;
}

}