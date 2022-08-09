#include "opencv2/opencv.hpp"
#include <iostream>
#include <stdio.h>


using namespace std;
using namespace cv;

void Logical()
{
	Mat src1 = imread("lenna256.bmp", IMREAD_GRAYSCALE);
	Mat src2 = imread("square.bmp", IMREAD_GRAYSCALE);

	if (src1.empty() || src2.empty())
	{
		cerr << "Image Load Failed!" << endl;
		return;
	}

	Mat dat1, dat2, dat3, dat4;

	bitwise_and(src1, src2, dat1);
	bitwise_or(src1, src2, dat2);
	bitwise_xor(src1, src2, dat3);
	bitwise_not(src1, dat4);

	imshow("src1", src1);
	imshow("src2", src2);
	imshow("dat1", dat1);
	imshow("dat2", dat2);
	imshow("dat3", dat3);
	imshow("dat4", dat4);

	waitKey();
	destroyAllWindows();
}