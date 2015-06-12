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
	DetectedLineResult DetectLine(vector<Vec4i>* lines);

public:
	float SlopeThreshold = 0.05;
	float DistanceThreshold = 100;
	LineDetector();
	~LineDetector();
	vector<DetectedLine*>* DetectLines(vector<Vec4i>* rawLines);
};

