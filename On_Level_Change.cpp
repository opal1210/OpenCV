#include "opencv2/opencv.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

void on_level_change(int pos, void* userdata) {
	Mat img = *(Mat*)userdata;

	img.setTo(pos * 16);
	imshow("img", img);
}

void on_level_change_main() {
	Mat img = Mat::zeros(200, 450, CV_8UC1);

	namedWindow("img");
	createTrackbar("level", "img", 0, 16, on_level_change, (void*)&img);

	imshow("img", img);
	waitKey();

	destroyAllWindows();
}