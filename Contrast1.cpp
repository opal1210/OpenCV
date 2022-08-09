#include "main.h"

void Contrast1() {

	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image Load Failed!" << endl;
		return;
	}
	
	float d = -0.5f;
	float u = 2.0f;
	Mat uat = src * u;
	Mat dat = src * d;

	imshow("src", src);
	imshow("dat", dat);
	imshow("uat", uat);

	waitKey();
	destroyAllWindows();
}

void Contrast2() {

	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image Load Failed!" << endl;
		return;
	}

	float u = 0.5f;
	float d = -0.5f;

	Mat uat = src + (src - 128) * u;
	Mat dat = src + (src - 128) * d;

	Mat hist = calcGrayHist(src);
	Mat hist_img = getGrayHistImage(hist);

	Mat histu = calcGrayHist(uat);
	Mat histu_img = getGrayHistImage(histu);

	Mat histd = calcGrayHist(dat);
	Mat histd_img = getGrayHistImage(histd);

	imshow("src", src);
	imshow("hist", hist_img);

	imshow("uat", uat);
	imshow("histu", histu_img);

	imshow("dat", dat);
	imshow("histd", histd_img);

	waitKey();
	destroyAllWindows();
}