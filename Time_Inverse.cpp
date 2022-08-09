#include "opencv2/opencv.hpp"
#include <iostream>
#include <stdio.h>


using namespace std;
using namespace cv;


void time_Inverse() {
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);
	
	if (src.empty()) {
		cerr << "Image Load Failed!" << endl;
		return;
	}

	Mat dst(src.rows, src.cols, src.type());

	TickMeter tm;
	tm.start();

	for (int j = 0; j < src.rows; j++) {
		for (int i = 0; i < src.cols; i++) {
			dst.at<uchar>(j, i) = 255 - src.at<uchar>(j, i);
		}
	}

	tm.stop();
	cout << "Image inverse took" << tm.getTimeMilli() << "ms." << endl;
}