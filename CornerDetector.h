#pragma once

#include "DetectedLine.h"

using namespace cv;
using namespace std;

class CornerDetector
{
public:
	int AngleTolerance = 5;
	float MinLineLength = 60;
	CornerDetector();
	~CornerDetector();
	vector<Intersection>* DetectCorner(vector<DetectedLine*>* lines, Mat image);
};

