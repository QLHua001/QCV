#include <opencv2/opencv.hpp>

#define QALGO_FLAG_SUCCESSFUL				(0)
#define QALGO_FLAG_BAD_PARAMETER			    (-1)
#define QALGO_FLAG_FETAL					    (-2)
#define QALGO_FLAG_NULL_POINTER			    (-3)
#define QALGO_FLAG_UNINITIALIZED			    (-4)
#define QALGO_FLAG_INITIALIZATION			(-5)
#define QALGO_FLAG_LICENSE_INVALID		    (-6)
#define QALGO_FLAG_EXCEPTION                 (-7)
#define QALGO_FLAG_OUT_OF_RANGE			    (-16)
#define QALGO_FLAG_OUT_OF_ACTION			    (-17)
#define QALGO_FLAG_BUSY					    (-18)

namespace QAlgo
{

// 马赛克算法
void cv_mosaic(cv::Mat original_image, int block_size);

// 高斯滤波算法
void cv_gaussian_filter(cv::Mat original_image, int kernel_size, double sigma);

// 直方图均衡化
void cv_equalize_hist(const cv::Mat& srcimg, cv::Mat& dstimg);

void cv_laplacian(const cv::Mat& srcimg, cv::Mat& dstimg);

// Gamma校正
void cv_GammaCorrection(const cv::Mat& src, cv::Mat& dst, float gamma);

} // namespace QAlgo
