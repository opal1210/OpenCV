#pragma once
#include "opencv2/opencv.hpp"
#include <iostream>
#include <stdio.h>


using namespace std;
using namespace cv;

Mat calcGrayHist(const Mat& img);
Mat getGrayHistImage(const Mat& hist);


void matclone();
void vec();
void camera_in();
void video_in();
void video_out();
void drawLines();
void drawPoly();
void drawText();
void drawText2();
void mouse_main();
void on_level_change_main();
void writedata();
void readData();
void mask_setTo();
void mask_copyTo();
void time_Inverse();
void Brightness1();
void Brightness2();
void Contrast1();
void Contrast2();
void Histogram();
void HistoStretch();
void HistoEqual();
void Arithmetic();
void Logical();
void Filter_Embossing();
void Blurring();
void Gaussian();
void Unsharp();
void Noise_Gaussian();
void Affine();
void Affine_translation(); 
void Affine_shear();
void Affine_scale();
void Affine_rotation();
void Affine_flip();
void Perspective();
void sobel_edge();
void Canny_edge();
void hough_lines();
void hough_lines_segments();
void hough_circle();
void color_inverse();
void color_trans();
void color_split();
void color_histo_strech();







