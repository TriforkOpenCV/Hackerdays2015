#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "LineExtractor.h"
#include "LineDetector.h"
#include "CornerDetector.h"

using namespace cv;
using namespace std;

void DisplayResizedImage(Mat image)
{
	Mat small;
	resize(image, small, Size(0,0), 0.5, 0.5);
	namedWindow("Display Image", WINDOW_AUTOSIZE);
	imshow("Display Image", small);
	waitKey(0);
}

void ProcessImage(Mat input)
{
	LineExtractor* lineExtractor = new LineExtractor();

	LineDetector* lineDetector = new LineDetector();
	lineDetector->SlopeThreshold = 0.07;

	CornerDetector* cornerDetector = new CornerDetector();
	cornerDetector->AngleTolerance = 20;

	vector<Vec4i> lines = lineExtractor->ExtractLines(input);
	for (int i = 0; i < lines.size(); i++)
	{
		Vec4i l = lines[i];
		line(input, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 1, CV_AA);
	}
	DisplayResizedImage(input);

	vector<DetectedLine*>* detectedLines = lineDetector->DetectLines(&lines);
	for (int i = 0; i < detectedLines->size(); i++)
	{
		Vec4i l = detectedLines->at(i)->GetLine();
		line(input, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(255, 0, 0), 3, CV_AA);
	}
	DisplayResizedImage(input);

	vector<Intersection>* corners = cornerDetector->DetectCorner(detectedLines, input);

	for (int i = 0; i < corners->size(); i++) {
		Intersection intersection = corners->at(i);
		circle(input, intersection.Point, 12, Scalar(0, 255, 0), 5);
	}
	DisplayResizedImage(input);

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

