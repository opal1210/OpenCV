#include "opencv2/opencv.hpp"
#include <iostream>
#include <stdio.h>


using namespace std;
using namespace cv;

Mat calcGrayHist(const Mat& img);
Mat getGrayHistImage(const Mat& hist);

void HistoEqual()
{
	Mat src = imread("hawkes.bmp", IMREAD_GRAYSCALE);

	if (src.empty())
	{
		cerr << "Image Load Failed!" << endl;
		return;
	}

	Mat dat;
	equalizeHist(src, dat);

	Mat hist = calcGrayHist(src);
	Mat hist_img = getGrayHistImage(hist);

	Mat histd = calcGrayHist(dat);
	Mat histd_img = getGrayHistImage(histd);

	imshow("src", src);
	imshow("src_histo", hist_img);

	imshow("dat", dat);
	imshow("dat_histo", histd_img);

	waitKey();
	destroyAllWindows();
}