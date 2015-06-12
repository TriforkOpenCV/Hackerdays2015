#pragma once

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

class LineExtractor
{
public:
	double Rho = 1;
	double Theta = CV_PI / 180;
	int Threshold = 50;
	double MinLineLength = 100;
	double MaxLineGap = 10;

	LineExtractor();
	~LineExtractor();
	vector<Vec4i> ExtractLines(Mat image);
};

