#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <stdio.h>


int main() {

    cv::VideoCapture vcap;
    cv::Mat image;

    const std::string videoStreamAddress = "rtsp://192.168.0.15";


    if (!vcap.open(videoStreamAddress)) {
        std::cerr << "Error opening video stream or file" << std::endl;
        return -1;
    }

    for (;;) {
        if (!vcap.read(image)) {
            std::cerr << "No frame" << std::endl;
            break;
        }
        vcap.grab();
        cv::imshow("RTSP Stream output", image);

        if (cv::waitKey(1) >= 0) break;
    }

    // Release the video capture object and close the window
    vcap.release();
    cv::destroyAllWindows();
    
    return 0;
}
