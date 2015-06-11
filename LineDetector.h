#pragma once

#include "DetectedLine.h"

using namespace cv;
using namespace std;

class LineDetector
{
public:
	LineDetector();
	~LineDetector();
	vector<DetectedLine>* DetectLines(vector<Vec4i> rawLines);
};

