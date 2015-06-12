#pragma once

#include "DetectedLine.h"

using namespace cv;
using namespace std;

class CornerDetector
{
private:
	bool IsAngleWithinTolerance(Intersection intersection);
	bool IsIntersectionWithinWindow(Intersection intersection, Mat image);
public:
	int AngleTolerance = 5;
	float MinLineLength = 60;

	// Capture window, from top left corner, 1.0 = full width/height
	float WindowX = 0.0;
	float WindowY = 0.5;
	float WindowWidth = 0.5;
	float WindowHeight = 0.5;

	CornerDetector();
	~CornerDetector();
	vector<Intersection>* DetectCorner(vector<DetectedLine*>* lines, Mat image);
};

