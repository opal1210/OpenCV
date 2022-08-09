#include "opencv2/opencv.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

void matclone() {
	Mat img1 = imread("lenna.bmp");
	Mat img2 = img1(Rect(120, 60, 100, 100));
	Mat img3 = img1(Rect(220, 160, 100, 100)).clone();
	img2 = ~img2;
	img3 = img3 - img2.clone();
	namedWindow("image1");
	imshow("image1", img1);

	namedWindow("image2");
	imshow("image2", img2);

	namedWindow("image3");
	imshow("image3", img3);

	waitKey();
}