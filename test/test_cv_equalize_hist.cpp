#include <opencv2/opencv.hpp>
#include "common/log.h"
#include "test.h"
#include "QAlgo/QAlgo.h"

namespace TEST{

int test_cv_equalize_hist(){
    std::string srcimgpath{"/e/QDWorkplace/code/QCV/imgs/test001.jpg"};
    std::string dstimgpath{"/e/QDWorkplace/code/QCV/temp/test_cv_equalize_hist.jpg"};

    float f = -105;
    uchar c = cv::saturate_cast<uchar>(f);  // c 的值被裁剪到 255

    cv::Mat srcimg = cv::imread(srcimgpath, cv::IMREAD_GRAYSCALE);
    cv::imwrite("./temp/gray.jpg", srcimg);
    if(srcimg.empty()){
        ERROR("imread %s fail!", srcimgpath.c_str());
        return TEST_FLAG_NULL_POINTER;
    }

    cv::Mat dstimg;
    QAlgo::cv_equalize_hist(srcimg, dstimg);

    cv::imwrite(dstimgpath, dstimg);

    return 0;
}

}