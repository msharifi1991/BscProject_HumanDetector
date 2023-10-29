#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "QFileDialog"
#include "VideoProcessor.h"
#include "thread"
#include "QFuture"
#include "QtConcurrent/QtConcurrent"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

Ui::MainWindow MainWindow::getUI()
{
    return *ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    std::cout<<"Window Destroyed"<<std::endl;
    QApplication::quit();
}

void MainWindow::setLabelImage(cv::Mat mat , int labelNumber)
{
    cv::cvtColor(mat , mat , CV_BGR2RGB);
    QImage qbaseImage((uchar*) mat.data , mat.cols , mat.rows , mat.step , QImage::Format_RGB888 );
    if(labelNumber == 1)
    {
        this->ui->label1->setPixmap(QPixmap::fromImage(qbaseImage));
    }
    else if (labelNumber == 2)
    {
        this->ui->label2->setPixmap(QPixmap::fromImage(qbaseImage));
    }
    else
    {
        this->ui->label3->setPixmap(QPixmap::fromImage(qbaseImage));
    }
}

void MainWindow::on_actionExit_triggered()
{
    std::cout<<"Window Destroyed"<<std::endl;
    QApplication::quit();
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileNames = QFileDialog::getOpenFileName(this, tr("Open File"),"/path/to/file/",tr("MPEG Files (*.mpg)"));
    std::cout<<fileNames.toStdString()<<std::endl;

    // Open video file
    //processor.setInput("EnterExitCrossingPaths1cor.mpg");
    processor.setInput(fileNames.toStdString());





    cv::VideoCapture capture;
    capture.open(fileNames.toStdString());
    this->ui->slider->setRange(0 , 2000 );


    // set frame processor
    processor.setFrameProcessor(this);
}

void MainWindow::on_actionStart_triggered()
{
    // Start the process
   // std::thread myThread(processor.run_static_entry, processor);
    QFuture<void> future = QtConcurrent::run(QThreadPool::globalInstance() ,processor.run_static_entry , processor);
    frameCount = 0;
}

void filterVideo(cv::Mat &frame , cv::Mat &filteredFrame)
{
    /// morphology filter

    ///end of morphology filter


}

// processing method
void MainWindow::process(cv:: Mat &frame, cv:: Mat &output) {

    frameCount++;

    this->ui->slider->setValue(frameCount);

    frame.copyTo(output);

    frame.copyTo(baseFrame);

    this->setLabelImage(baseFrame , 1);



    Mat img,filteredImg;

    /// Filters
    ////////////////////////////////////////////////////////////////////////////////////////////
    int n2 = this->ui->morphslider->value() - 10;
    int an2 = n2 > 0 ? n2 : -n2;
    Mat element = getStructuringElement(MORPH_RECT, Size(an2*2+1, an2*2+1), Point(an2, an2) );
    if( n2 < 0 )
        morphologyEx(baseFrame, filteredImg, CV_MOP_OPEN, element);
    else
        morphologyEx(baseFrame, filteredImg, CV_MOP_CLOSE, element);

    int n = this->ui->errodslider->value() - 10;
    int an = n > 0 ? n : -n;
    Mat element2 = getStructuringElement(MORPH_RECT, Size(an*2+1, an*2+1), Point(an, an) );
    if( n < 0 )
        erode(filteredImg, filteredImg, element2);
    else
        dilate(filteredImg, filteredImg, element2);
    this->setLabelImage(filteredImg , 2);
    filteredImg.copyTo(img);
    ///////////////////////////////////////////////////////////////////////////////////////////


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

    this->setLabelImage(finalFrame , 3);


}

void MainWindow::on_pushButton_clicked()
{
    on_actionStart_triggered();
}

void MainWindow::on_pushButton_2_clicked()
{
    on_actionOpen_triggered();
}


