#include "opencv2/opencv.hpp"
#include <iostream>
#include <stdio.h>


using namespace std;
using namespace cv;


void Brightness1() {
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image Loat Failed!" << endl;
		return;
	}

	Mat dat = src + 100;

	imshow("src", src);
	imshow("dat", dat);

	waitKey();
	destroyAllWindows();
}