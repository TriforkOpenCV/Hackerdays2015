#pragma once

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

class LineExtractor
{
public:
	// Blur
	int Blur = 5;

	// Edge Detection
	double CannyEdgeThreshold1 = 100;
	double CannyEdgeThreshold2 = 50;
	int ApertureSize = 3;

	// Hough parameters
	double Rho = 1;
	double Theta = 1; // degrees
	int HoughThreshold = 50;
	double MinLineLength = 100;
	double MaxLineGap = 10;

	LineExtractor();
	~LineExtractor();
	vector<Vec4i> ExtractLines(Mat image);
};

