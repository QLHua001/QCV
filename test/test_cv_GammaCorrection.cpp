#include <opencv2/opencv.hpp>
#include "common/log.h"
#include "QAlgo/QAlgo.h"
#include "test.h"

namespace TEST
{

int test_cv_GammaCorrection(){

    std::string srcimgpath{"/e/QDWorkplace/code/QCV/imgs/test001.jpg"};

    cv::Mat srcimg = cv::imread(srcimgpath, cv::IMREAD_GRAYSCALE);


    cv::Mat dstimg;
    QAlgo::cv_GammaCorrection(srcimg, dstimg, 0.2);

    cv::imwrite("./temp/GammaCorrection.jpg", dstimg);

    return 0;
}

} // namespace TEST

