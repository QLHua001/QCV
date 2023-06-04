#pragma once

#define TEST_FLAG_SUCCESSFUL				(0)
#define TEST_FLAG_BAD_PARAMETER			    (-1)
#define TEST_FLAG_FETAL					    (-2)
#define TEST_FLAG_NULL_POINTER			    (-3)
#define TEST_FLAG_UNINITIALIZED			    (-4)
#define TEST_FLAG_INITIALIZATION			(-5)
#define TEST_FLAG_LICENSE_INVALID		    (-6)
#define TEST_FLAG_EXCEPTION                 (-7)
#define TEST_FLAG_OUT_OF_RANGE			    (-16)
#define TEST_FLAG_OUT_OF_ACTION			    (-17)
#define TEST_FLAG_BUSY					    (-18)


namespace TEST
{
    
int test();

int test_cv_mosaic();

int test_cv_gaussian_filter();

// cv中常见的图像降噪算法
int test_cv_ImageDenoising();

int test_cv_equalize_hist();

int test_cv_Laplacian();

int test_cv_GammaCorrection();

} // namespace TEST
