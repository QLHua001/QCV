#include "common/log.h"
#include "test.h"
#include "QAlgo/QAlgo.h"

namespace TEST
{

int test_cv_gaussian_filter(){

    std::string imgpath{"/e/QDWorkplace/code/QCV/imgs/test001.jpg"};


    cv::Mat srcimg = cv::imread(imgpath);
    if(srcimg.empty()){
        ERROR("imread %s fail!", imgpath.c_str());
        return TEST_FLAG_NULL_POINTER;
    }
    int srcimg_w = srcimg.cols;
    int srcimg_h = srcimg.rows;

    QAlgo::cv_gaussian_filter(srcimg, 5, 0.2);
    
    cv::imwrite("./temp/srcimg.jpg", srcimg);

    return TEST_FLAG_SUCCESSFUL;
}    

} // namespace TEST
