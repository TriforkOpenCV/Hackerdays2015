#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "LineExtractor.h"
#include "LineDetector.h"
#include "CornerDetector.h"

using namespace cv;
using namespace std;

void ProcessImage(Mat input)
{
	LineExtractor* lineExtractor = new LineExtractor();
	LineDetector* lineDetector = new LineDetector();
	CornerDetector* cornerDetector = new CornerDetector();

	vector<Vec4i> lines = lineExtractor->ExtractLines(input);
	vector<DetectedLine*>* detectedLines = lineDetector->DetectLines(&lines);

	for (size_t i = 0; i < detectedLines->size(); i++)
	{
		Vec4i l = detectedLines->at(i)->GetLine();
		line(input, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(255, 0, 0), 3, CV_AA);
	}

	Mat small;
	resize(input, small, Size(0,0), 0.5, 0.5);
	namedWindow("Display Image", WINDOW_AUTOSIZE);
	imshow("Display Image", small);
	waitKey(0);


	Intersection corner = cornerDetector->DetectCorner(detectedLines, input);

	delete lineExtractor;
	delete lineDetector;
	delete cornerDetector;
}


int main(int argc, char** argv )
{
	ProcessImage(imread("./Pictures/dong.jpg", 1));
	ProcessImage(imread("./Pictures/kajak.jpg", 1));
	ProcessImage(imread("./Pictures/hofor.jpg", 1));

    return 0;
}

