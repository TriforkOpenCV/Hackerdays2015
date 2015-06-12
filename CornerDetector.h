#pragma once

#include "DetectedLine.h"

using namespace cv;
using namespace std;

class CornerDetector
{
public:
	int AngleTolerance = 5;
	CornerDetector();
	~CornerDetector();
	vector<Intersection>* DetectCorner(vector<DetectedLine*>* lines, Mat image);
};

