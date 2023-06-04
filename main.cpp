#include <iostream>
#include <opencv2/opencv.hpp>

#include "test/test.h"

int main(int, char**) {
    std::cout << "Hello, world!\n";

    // TEST::test();
    // TEST::test_cv_mosaic();
    // TEST::test_cv_gaussian_filter();
    // TEST::test_cv_ImageDenoising();
    // TEST::test_cv_equalize_hist();
    TEST::test_cv_Laplacian();

    return 0;
}
