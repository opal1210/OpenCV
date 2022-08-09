#include "opencv2/opencv.hpp"
#include <iostream>
#include <stdio.h>


using namespace std;
using namespace cv;

Mat calcGrayHist(const Mat& img) 
{
	CV_Assert(img.type() == CV_8UC1);

	Mat hist;
	int channels[] = { 0 };
	int dims = 1;
	const int histSize[] = { 256 };
	float graylevel[] = { 0,256 };
	const float* ranges[] = { graylevel };

	calcHist(&img, 1, channels, noArray(), hist, dims, histSize, ranges);

	return hist;

}

Mat getGrayHistImage(const Mat& hist)
{
	CV_Assert(hist.type() == CV_32FC1);
	CV_Assert(hist.size() == Size(1, 256));

	double Maxhist;
	minMaxLoc(hist, 0, &Maxhist);

	Mat imgHist(100, 256, CV_8UC1, Scalar(255));
	for (int i = 0; i < 256; i++) {
		line(imgHist, Point(i, 100), Point(i, 100 - cvRound(hist.at<float>(i, 0) * 100 / Maxhist)), Scalar(0));
	}

	return imgHist;
}

void Histogram() {
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "Image Load Failed!" << endl;
		return;
	}
	Mat hist = calcGrayHist(src);
	Mat hist_img = getGrayHistImage(hist);

	imshow("src", src);
	imshow("hist_img", hist_img);

	waitKey();
	destroyAllWindows();
}

void HistoStretch() {
	Mat src = imread("hawkes.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image Load Failed!" << endl;
		return;
	}

	double Maxhist;
	double Minhist;

	minMaxLoc(src, &Minhist, &Maxhist);

	Mat srcst = (src - Minhist) / (Maxhist - Minhist) * 255;

	Mat hist = calcGrayHist(src);
	Mat hist_img = getGrayHistImage(hist);

	Mat histr = calcGrayHist(srcst);
	Mat histr_img = getGrayHistImage(histr);

	imshow("src", src);
	imshow("src_histo", hist_img);

	imshow("srcst", srcst);
	imshow("srcst_histo", histr_img);

	waitKey();
	destroyAllWindows();

}