#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma once
#include <QMainWindow>
#include "opencv2/core/core.hpp"
#include "VideoProcessor.h"
#include <stdio.h>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "mainwindow.h"
#include <QMainWindow>


using namespace cv;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow , public FrameProcessor
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Ui::MainWindow getUI();
    void MainWindow::setLabelImage(cv::Mat mat , int labelNumber);
    void MainWindow::closeEvent(QCloseEvent *event);
    // Create video procesor instance
    VideoProcessor processor;
    void process(cv:: Mat &frame, cv:: Mat &output);
    void filterVideo(cv::Mat &frame , cv::Mat &filteredFrame);

private slots:
    void on_actionExit_triggered();

    void on_actionOpen_triggered();

    void on_actionStart_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    Mat baseFrame , filteredFrame , finalFrame;
    int frameCount;
};

#endif // MAINWINDOW_H
