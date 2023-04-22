#include <iostream>
#include <opencv2/opencv.hpp>

#include "test/test.h"

int main(int, char**) {
    std::cout << "Hello, world!\n";

    // TEST::test();
    TEST::test_cv_mosaic();

    return 0;
}
