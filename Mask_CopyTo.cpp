#include "opencv2/opencv.hpp"
#include <iostream>
#include <stdio.h>


using namespace std;
using namespace cv;


void mask_copyTo() {
	Mat src = imread("airplane.bmp", IMREAD_COLOR);
	Mat mask = imread("mask_plane.bmp", IMREAD_GRAYSCALE);
	Mat dst = imread("field.bmp", IMREAD_COLOR);	

	if (src.empty() || mask.empty() || dst.empty()) {
		cerr << "Image Load Failed!" << endl;
		return;
	}
	imshow("dst1", dst);
	src.copyTo(dst, mask);

	imshow("dst2", dst);
	imshow("src", src);
	imshow("mask", mask);

	waitKey();
	destroyAllWindows();
}