#pragma once

#include "DetectedLine.h"

using namespace cv;
using namespace std;

struct DetectedLineResult
{
public:
	DetectedLine* detectedLine;
	vector<Vec4i>* remainingLines;
};

/*
 * Given a set of raw lines identify line fragments that are part of the same line
 */
class LineDetector
{
private:
	static const float SLOPE_THRESHOLD = 2;
	static const float DISTANCE_THRESHOLD = 100;

	DetectedLineResult DetectLine(vector<Vec4i>* lines);

public:
	LineDetector();
	~LineDetector();
	vector<DetectedLine*>* DetectLines(vector<Vec4i>* rawLines);
};

