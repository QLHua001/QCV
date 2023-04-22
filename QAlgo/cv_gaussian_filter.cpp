#include <opencv2/opencv.hpp>

using namespace cv;

namespace QAlgo
{
    
void cv_gaussian_filter(cv::Mat original_image, int kernel_size, double sigma){

    // 定义高斯内核
    Mat kernel = getGaussianKernel(kernel_size, sigma);
    // 对内核进行翻转
    flip(kernel, kernel, 0);
    
    // 处理边界像素点
    int border_size = kernel_size / 2;  // 计算边界大小
    Mat border_image;
    copyMakeBorder(original_image, border_image, border_size, border_size, border_size, border_size, BORDER_REPLICATE);
    
    // 遍历所有像素点
    for (int i = border_size; i < border_image.cols - border_size; i++) {
        for (int j = border_size; j < border_image.rows - border_size; j++) {
            // 定义颜色值变量，初值为0
            Scalar color_value = Scalar(0, 0, 0);
            // 遍历当前像素点周围的像素点
            for (int x = i - border_size; x <= i + border_size; x++) {
                for (int y = j - border_size; y <= j + border_size; y++) {
                    // 读取周围像素点的颜色值
                    Scalar pixel_color = border_image.at<Vec3b>(y, x);
                    // 获取对应位置在内核中的权值
                    double weight = kernel.at<double>(x - i + border_size, y - j + border_size);
                    // 累加颜色值
                    color_value += (pixel_color * weight);
                }
            }
            // 将颜色值设置为当前像素点的颜色值
            original_image.at<Vec3b>(j - border_size, i - border_size)[0] = color_value[0];
            original_image.at<Vec3b>(j - border_size, i - border_size)[1] = color_value[1];
            original_image.at<Vec3b>(j - border_size, i - border_size)[2] = color_value[2];
        }
    }

}

} // namespace QAlgo
