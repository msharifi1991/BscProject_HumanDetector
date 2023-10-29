//
//  PeopleDetector.h
//  BscProject
//
//  Created by Amin Sojoudi on 11/16/14.
//  Copyright (c) 2014 Amin Sojoudi. All rights reserved.
//
#pragma once
#ifndef __BscProject__PeopleDetector__
#define __BscProject__PeopleDetector__

#include <stdio.h>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "mainwindow.h"
#include <QMainWindow>
#include "videoprocessor.h"


using namespace cv;

class PeopleDetector : public FrameProcessor {
    
//    cv::Mat gray;			// current gray-level image
//    cv::Mat gray_prev;		// previous gray-level image
//    std::vector<cv::Point2f> points[2]; // tracked features from 0->1
//    std::vector<cv::Point2f> initial;   // initial position of tracked points
//    std::vector<cv::Point2f> features;  // detected features
//    int max_count;	  // maximum number of features to detect
//    double qlevel;    // quality level for feature detection
//    double minDist;   // minimum distance between two feature points
//    std::vector<uchar> status; // status of tracked features
//    std::vector<float> err;    // error in tracking
private:
    QImage qbaseImage;


public:
    Mat baseFrame , filteredFrame , finalFrame;


    PeopleDetector()
    {
    }


    // processing method
    void process(cv:: Mat &frame, cv:: Mat &output) {
        
        frame.copyTo(output);

        frame.copyTo(baseFrame);

      //  window->setPixmap(baseFrame);
        
        Mat img;
        frame.copyTo(img);
        
        HOGDescriptor hog;
        hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
            
        fflush(stdout);
        vector<Rect> found, found_filtered;
        double t = (double)getTickCount();
        // run the detector with default parameters. to get a higher hit-rate
        // (and more false alarms, respectively), decrease the hitThreshold and
        // groupThreshold (set groupThreshold to 0 to turn off the grouping completely).
        hog.detectMultiScale(img, found, 0.5, Size(8,8), Size(32,32), 1.05, 2);
        t = (double)getTickCount() - t;
        printf("tdetection time = %gms\n", t*1000./cv::getTickFrequency());
        printf("Found People : %d  \n" , found.size());
        size_t i, j;
        for( i = 0; i < found.size(); i++ )
        {
            Rect r = found[i];
            for( j = 0; j < found.size(); j++ )
                if( j != i && (r & found[j]) == r)
                    break;
            if( j == found.size() )
                found_filtered.push_back(r);
        }
        for( i = 0; i < found_filtered.size(); i++ )
        {
            Rect r = found_filtered[i];
            // the HOG detector returns slightly larger rectangles than the real objects.
            // so we slightly shrink the rectangles to get a nicer output.
            r.x += cvRound(r.width*0.1);
            r.width = cvRound(r.width*0.8);
            r.y += cvRound(r.height*0.07);
            r.height = cvRound(r.height*0.8);
            rectangle(img, r.tl(), r.br(), cv::Scalar(0,255,0), 3);
        }
        
        img.copyTo(output);

        output.copyTo(finalFrame);


        
    }
};




#endif /* defined(__BscProject__PeopleDetector__) */
