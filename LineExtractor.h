#pragma once

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

class LineExtractor
{
public:
	LineExtractor();
	~LineExtractor();
	vector<Vec4i> ExtractLines(Mat image);
};

