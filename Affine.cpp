#include "main.h"


void Affine()
{
	Mat src = imread("tekapo.bmp");

	if (src.empty())
	{
		cerr << "Image Load Failed!" << endl;
		return;
	}

	Point2f srcPts[3], dstPts[3];

	srcPts[0] = Point2f(0, 0);
	srcPts[1] = Point2f(src.cols-1, 0);
	srcPts[2] = Point2f(src.cols - 1, src.rows-1);
	dstPts[0] = Point2f(50, 50);
	dstPts[1] = Point2f(src.cols-100, 100);
	dstPts[2] = Point2f(src.cols-50, src.rows-50);

	Mat M = getAffineTransform(srcPts, dstPts);

	Mat dst;
	warpAffine(src, dst, M, Size());

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
}

void Affine_translation()
{
	Mat src = imread("tekapo.bmp");

	if (src.empty())
	{
		cerr << "Image Load Failed!" << endl;
		return;
	}

	Mat M = Mat_<double>({ 2,3 }, { 1,0,150,0,1,100 });

	Mat dst;
	warpAffine(src, dst, M, Size());

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
}

void Affine_shear()
{
	Mat src = imread("tekapo.bmp");

	if (src.empty())
	{
		cerr << "Image Load Failed!" << endl;
		return;
	}

	double mx = 1.0;
	Mat M = Mat_<double>({ 2,3 }, { 1, mx, 0, 0,1,0 });

	Mat dst;
	warpAffine(src, dst, M, Size());

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
}

void Affine_scale()
{
	Mat src = imread("rose.bmp");

	if (src.empty())
	{
		cerr << "Image Load Failed!" << endl;
		return;
	}

	Mat dst1, dst2, dst3, dst4;

	resize(src, dst1, Size(), 4, 4, INTER_NEAREST);
	resize(src, dst2, Size(1920, 1280), 0, 0);
	resize(src, dst3, Size(1920, 1280), 0, 0, INTER_CUBIC);
	resize(src, dst4, Size(1920, 1280), 0, 0, INTER_LANCZOS4);

	imshow("src", src);
	imshow("dst1", dst1(Rect(400,500,400,400)));
	imshow("dst2", dst2(Rect(400, 500, 400, 400)));
	imshow("dst3", dst3(Rect(400, 500, 400, 400)));
	imshow("dst4", dst4(Rect(400, 500, 400, 400)));

	waitKey();
	destroyAllWindows();
}

void Affine_rotation()
{
	Mat src = imread("tekapo.bmp");

	if (src.empty())
	{
		cerr << "Image Load Failed!" << endl;
		return;
	}

	Point2f cp(0, 0);
	Mat M = getRotationMatrix2D(cp, 20, 1);

	Mat dst;
	warpAffine(src, dst, M, Size());

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
}

void Affine_flip()
{
	Mat src = imread("eastsea.bmp");

	if (src.empty())
	{
		cerr << "Image Load Failed!" << endl;
		return;
	}

	Mat dst1, dst2, dst3;
	flip(src, dst1, 1);
	flip(src, dst2, 0);
	flip(src, dst3, -1);

	imshow("src", src);
	imshow("dst1", dst1);
	imshow("dst2", dst2);
	imshow("dst3", dst3);

	waitKey();
	destroyAllWindows();
}
