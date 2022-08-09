#include "main.h"

void color_inverse()
{
	Mat src = imread("butterfly.jpg", IMREAD_COLOR);

	if (src.empty())
	{
		cerr << "Image Load Failed!" << endl;
		return;
	}

	Mat dst(src.rows, src.cols, src.type());

	for (int j = 0; j < src.rows; j++)
	{
		for (int i = 0; i < src.cols; i++)
		{
			Vec3b& p1 = src.at<Vec3b>(j, i);
			Vec3b& p2 = dst.at<Vec3b>(j, i);

			p2[0] = 255 - p1[0];
			p2[1] = 255 - p1[1];
			p2[2] = 255 - p1[2];
		}
	}

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
}

void color_trans()
{
	Mat src = imread("butterfly.jpg");

	if (src.empty())
	{
		cerr << "Image Load Failed!" << endl;
		return;
	}

	Mat dst1, dst2, dst3, dst4, dst5, dst6;
	cvtColor(src, dst1, COLOR_BGR2RGB);
	cvtColor(src, dst2, COLOR_RGB2BGR);
	cvtColor(src, dst3, COLOR_BGR2XYZ);
	cvtColor(src, dst4, COLOR_BGR2YCrCb);
	cvtColor(src, dst5, COLOR_BGR2HSV);
	cvtColor(src, dst6, COLOR_BGR2Lab);

	imshow("src", src);
	imshow("dst1", dst1);
	imshow("dst2", dst2);
	imshow("dst3", dst3);
	imshow("dst4", dst4);
	imshow("dst5", dst5);
	imshow("dst6", dst6);

	waitKey();
	destroyAllWindows();
}

void color_split()
{
	Mat src = imread("candies.png");

	if (src.empty())
	{
		cerr << "Image Load Failed!" << endl;
		return;
	}

	vector<Mat> bgr_planes;
	split(src, bgr_planes);

	imshow("src", src);
	
	imshow("B_plane", bgr_planes[0]);
	imshow("G_plane", bgr_planes[1]);
	imshow("R_plane", bgr_planes[2]);

	waitKey();
	destroyAllWindows();
}

void color_histo_strech()
{
	Mat src = imread("pepper.bmp", IMREAD_COLOR);

	if (src.empty())
	{
		cerr << "Image Load Failed!" << endl;
		return;
	}

	Mat src_ycrcb;
	cvtColor(src, src_ycrcb, COLOR_BGR2YCrCb);

	vector<Mat> ycrcb_planes;
	split(src_ycrcb, ycrcb_planes);

	equalizeHist(ycrcb_planes[0], ycrcb_planes[0]);

	Mat dst_ycrcb;
	merge(ycrcb_planes, dst_ycrcb);

	Mat dst;
	cvtColor(dst_ycrcb, dst, COLOR_YCrCb2BGR);


	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();


}