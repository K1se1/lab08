#include "caeser.hpp"

void caeser(cv::Mat& img, int shift)
{
    cv::Size size = img.size();
    for(int i =0; i < size.height; ++i)
    {
        for(int j =0; j < size.width; ++j)
        {
            img.at<cv::Vec3b>(i, j)+=cv::Vec3b(shift, 0, 0); 
        }
    }
    return;
}