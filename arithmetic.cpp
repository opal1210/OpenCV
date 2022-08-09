#include "opencv2/opencv.hpp"
#include <iostream>
#include <stdio.h>


using namespace std;
using namespace cv;

Mat calcGrayHist(const Mat& img);
Mat getGrayHistImage(const Mat& hist);

void Arithmetic()
{
	Mat src1 = imread("lenna256.bmp", IMREAD_GRAYSCALE);
	Mat src2 = imread("square.bmp", IMREAD_GRAYSCALE);

	if (src1.empty() || src2.empty())
	{
		cerr << "Image Load Failed!" << endl;
		return;
	}

	Mat dat1;
	Mat dat2;
	Mat dat3;
	Mat dat4;
	Mat dat5;

	add(src1, src2, dat1);
	addWeighted(src1, 0.5, src2, 0.5, 0, dat2);
	subtract(src1, src2, dat3);
	subtract(src2, src1, dat4);
	absdiff(src1, src2, dat5);

	imshow("src1", src1);
	imshow("src2", src2);
	imshow("dat1", dat1);
	imshow("dat2", dat2);
	imshow("dat3", dat3);
	imshow("dat4", dat4);
	imshow("dat5", dat5);

	waitKey();
	destroyAllWindows();


}