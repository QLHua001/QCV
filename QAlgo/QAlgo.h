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

void cv_mosaic(cv::Mat original_image, int block_size);

} // namespace QAlgo