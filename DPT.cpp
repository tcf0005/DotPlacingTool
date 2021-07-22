#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui_c.h>

int main( int argc, char** argv){
   
    //import image
    cv::Mat image = cv::imread("inverted.png");
    cv::resize(image, image,cv::Size(640, 480));
    cv::Mat original = image.clone();
    cv::Mat drawing = original.clone();

    //Initializing Slider
    int X=75, Y=90, Smin=79, Smax=138,Vmin=119,Vmax=140;
    cv::namedWindow("Sliders",cv::WINDOW_NORMAL);
    cv::resizeWindow("Sliders",300,300);
    cv::createTrackbar("X Value", "Sliders", &X, 639) ;
    cv::createTrackbar("Y Value", "Sliders", &Y, 479) ;
   

     while (true)
     {
        cv::Mat drawing = original.clone();
        cv::namedWindow("Filtered",cv::WINDOW_AUTOSIZE);
        cv::circle( drawing, cv::Point( X, Y ), 3.0, cv::Scalar( 0, 255, 25 ), 1, 8 );

        cv::imshow("Filtered",drawing);
        
        

        
        
        
        cv::waitKey(5);
     }

    return 0;
    //std::cout<<moments<<std::endl
} 