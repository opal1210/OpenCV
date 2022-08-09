#include "opencv2/opencv.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

void drawText() {
	Mat img(500, 800, CV_8UC3, Scalar(255, 255, 255));

	putText(img, "FONT_HERSHEY_DUPLEX", Point(20, 50), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 255));
	putText(img, "FONT_HERSHEY_DUPLEX", Point(20, 100), FONT_HERSHEY_SCRIPT_SIMPLEX, 1, Scalar(0, 0, 0));
	putText(img, "FONT_HERSHEY_DUPLEX", Point(20, 200), FONT_HERSHEY_SCRIPT_COMPLEX, 1, Scalar(0, 0, 0));


	imshow("img", img);
	waitKey();

	destroyAllWindows();
}

void drawText2() {
	Mat img(200, 640, CV_8UC3, Scalar(255, 255, 255));

	const String text = "Hello, OpenCV";
	int fontFace = FONT_HERSHEY_TRIPLEX;
	double fontScale = 2.0;
	int thickness = 1;

	Size sizeText = getTextSize(text, fontFace, fontScale, thickness, 0);
	Size sizeImg = img.size();

	Point org((sizeImg.width - sizeText.width) / 2, (sizeImg.height + sizeText.height) / 2);
	putText(img, text, org, fontFace, fontScale, Scalar(255, 0, 0), thickness);
	rectangle(img, org, org + Point(sizeText.width, -sizeText.height), Scalar(255, 0, 0), 1);


	imshow("img", img);
	waitKey();

	destroyAllWindows();
}