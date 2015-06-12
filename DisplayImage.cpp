#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "LineExtractor.h"
#include "LineDetector.h"
#include "CornerDetector.h"

using namespace cv;
using namespace std;

void DisplayResizedImage(Mat image)
{
	Mat resized;
	resize(image, resized, Size(0,0), 2, 2);
	namedWindow("Display Image", WINDOW_AUTOSIZE);
	imshow("Display Image", resized);
	waitKey(0);
}

void ProcessImage(Mat input)
{
	Mat image;
	resize(input, image, Size(0,0), 0.2, 0.2);

	LineExtractor* lineExtractor = new LineExtractor();
	lineExtractor->Blur = 3;
	lineExtractor->HoughThreshold = 120;
	lineExtractor->Theta = 1;
	lineExtractor->MinLineLength = 200;
	lineExtractor->MaxLineGap = 120;

	LineDetector* lineDetector = new LineDetector();
	lineDetector->SlopeThreshold = 0.10;
	lineDetector->DistanceThreshold = 20;

	CornerDetector* cornerDetector = new CornerDetector();
	cornerDetector->AngleTolerance = 20;
	cornerDetector->MinLineLength = 60;

	vector<Vec4i> lines = lineExtractor->ExtractLines(image);
	for (int i = 0; i < lines.size(); i++)
	{
		Vec4i l = lines[i];
		line(image, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 1, CV_AA);
	}
	DisplayResizedImage(image);

	vector<DetectedLine*>* detectedLines = lineDetector->DetectLines(&lines);
	for (int i = 0; i < detectedLines->size(); i++)
	{
		Vec4i l = detectedLines->at(i)->GetLine();
		line(image, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(255, 0, 0), 2, CV_AA);
	}
	DisplayResizedImage(image);

	vector<Intersection>* corners = cornerDetector->DetectCorner(detectedLines, image);

	for (int i = 0; i < corners->size(); i++) {
		Intersection intersection = corners->at(i);
		circle(image, intersection.Point, 12, Scalar(0, 255, 0), 5);
	}
	DisplayResizedImage(image);

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

