#include "task.hpp"
#include <opencv2/opencv.hpp>
#include <openssl/sha.h>
#include <string>
#include <sstream>
#include <iomanip>

std::string Get_Image_SHA256(const cv::Mat& image){
    std::vector<uchar> buffer;
    cv::imencode(".png", image, buffer);
    
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(buffer.data(), buffer.size(), hash);
    
    std::stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    
    return ss.str();
}

void Modify_Image(cv::Mat& image){
    if (image.empty()) return;

    cv::Vec3b& pixel = image.at<cv::Vec3b>(13, 26);
    pixel[2] = (pixel[2] + 34) % 256;
}