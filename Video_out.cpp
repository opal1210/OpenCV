#include "opencv2/opencv.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

void video_out() {
	VideoCapture cap("stopwatch.avi");

	if (!cap.isOpened()) {
		cerr << "Camera open failed!" << endl;
		return;
	}
	int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
	int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));
	double fps = cap.get(CAP_PROP_FPS);
	int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');
	int delay = cvRound(1000 / fps);

	cout << "Frame width: " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
	cout << "Frame height: " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;
	cout << "Frame count: " << cvRound(cap.get(CAP_PROP_FRAME_COUNT)) << endl;
	cout << "FPS: " << fps << endl;

	VideoWriter outputVideo("output.avi", fourcc, fps, Size(w, h));

	if (!outputVideo.isOpened()) {
		cerr << "Video Write failed!" << endl;
		return;
	}

	Mat frame;
	while (true) {
		cap >> frame;
		if (frame.empty())
			break;

		Mat inverse = frame(Rect(120, 60, 250, 250));
		inverse = ~inverse;
		outputVideo << inverse;

		imshow("frame", frame);
		imshow("inverse", inverse);

		if (waitKey(delay) == 27)
			break;
	}
	destroyAllWindows();
}