#include <iostream>
#include <opencv2/opencv.hpp>
 
int main()
{
    std::cout << "OpenCV Version : " << CV_VERSION << std::endl;
    cv::Mat img;
    cv::namedWindow("CAPTURE#1", 1);
    cv::VideoCapture cap;
 
    cap.open("/dev/video10"); 
    cap.set(cv::CAP_PROP_FRAME_WIDTH, 0x7FFFFFFF);          // working
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 0x7FFFFFFF);         // working
    cap.set(cv::CAP_PROP_FPS, 30);			    // not working...
    while (cap.isOpened())
    {
        cap >> img;
        cv::imshow("CAPTURE#1", img);
        if (cv::waitKey(30)==27)
        {
            break;
        }
    }
    cv::destroyWindow("CAPTURE#1");
    return 0;
}


