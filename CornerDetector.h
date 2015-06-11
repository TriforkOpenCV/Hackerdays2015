#pragma once

#include "DetectedLine.h"

using namespace cv;
using namespace std;

class CornerDetector
{
public:
	CornerDetector();
	~CornerDetector();
	Intersection DetectCorner(vector<DetectedLine>* lines, Mat image);
};

