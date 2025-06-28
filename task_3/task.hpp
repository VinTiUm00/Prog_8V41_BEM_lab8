#ifndef TASK_HPP
#define TASK_HPP

#include <string>
#include <opencv2/opencv.hpp>

std::string Get_Image_SHA256(const cv::Mat& image);
void Modify_Image(cv::Mat& image);

#endif