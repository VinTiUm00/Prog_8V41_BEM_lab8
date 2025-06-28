#include "task.hpp"
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <fstream>

int main(){
    cv::Mat image = cv::imread("image.png", cv::IMREAD_COLOR);
    if (image.empty()){
        std::cerr << "Error opening the image" << std::endl;
        return -1;
    }

    std::ofstream out("out.txt");
    if (!out.is_open()){
        std::cerr << "The output file could not be opened" << std::endl;
        return -2;
    }

    std::string firsthash = Get_Image_SHA256(image);
    std::cout << "The original SHA256: " << firsthash << std::endl;
    out << "The original SHA256: " << firsthash << std::endl;

    Modify_Image(image);

    std::string secondhash = Get_Image_SHA256(image);
    std::cout << "After modification: " << secondhash << std::endl;
    out << "After modification: " << secondhash << std::endl;

    bool EqualHash = (firsthash == secondhash);
    if (EqualHash == true){
        std::cout << "SHA256 is the same" << std::endl;
        out << "SHA256 is the same" << std::endl;
    }
    else{
        std::cout << "SHA256 is different" << std::endl;
        out << "SHA256 is different" << std::endl;
    }
    out.close();

    system("pause");
    return 0;
}