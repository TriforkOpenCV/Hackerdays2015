#include "LineDetector.h"

#include <cmath>

LineDetector::LineDetector()
{
}


LineDetector::~LineDetector()
{
}


float Slope(Vec4i line)
{
	float dy = line[3] - line[1];
	float dx = line[2] - line[0];
	if (dx != 0) {
		return dy/dx;
	} else {
		return FLT_MAX;
	}
}

// y1 = a*x1 + b => b = y1 - a*x1
float IntersectWithYAxis(Vec4i line, float slope)
{
	if (slope == FLT_MAX) {
		return -FLT_MAX;
	} else {
		return ((float)line[1]) - ((float)slope * ((float)line[0]));
	}
}

DetectedLineResult LineDetector::DetectLine(vector<Vec4i>* lines)
{
	DetectedLineResult result = DetectedLineResult();
	result.detectedLine = new DetectedLine(lines->at(0));
	if (lines->size() == 1) {
		lines->clear();
		result.remainingLines = lines;
	} else {
		Vec4i line1 = lines->at(0);
		float slope1 = Slope(line1);

		result.remainingLines = new vector<Vec4i>();
		for (int i = 1; i < lines->size(); i++) {
			Vec4i line2 = lines->at(i);
			float slope2 = Slope(line2);
			if (std::abs(1 - slope2 / slope1) < SlopeThreshold) {

				float b1 = IntersectWithYAxis(line1, slope1);
				float b2 = IntersectWithYAxis(line2, slope2);
				//cout << "dist " << b1 << ", " << b2 << "\n";
 				if (std::abs(b2-b1)/std::sqrt(slope1*slope2 + 1) < DistanceThreshold) {
					result.detectedLine->AddLine(line2);
				} else {
					result.remainingLines->push_back(line2);
				}
			} else {
				result.remainingLines->push_back(line2);
			}
		}
		//delete lines;
	}

	return result;
}

vector<DetectedLine*>* LineDetector::DetectLines(vector<Vec4i>* rawLines)
{
	vector<DetectedLine*>* result = new vector<DetectedLine*>();

	DetectedLineResult lineResult = DetectedLineResult();
	lineResult.remainingLines = rawLines;
	while (lineResult.remainingLines->size() > 0) {
		lineResult = LineDetector::DetectLine(lineResult.remainingLines);
		result->push_back(lineResult.detectedLine);
	}

	return result;
}




