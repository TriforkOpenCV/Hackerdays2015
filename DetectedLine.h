#pragma once

#include <opencv2/opencv.hpp>

using namespace cv;

struct Intersection
{
public:
	Point2f Point;
	double Angle;
	bool IsCorner;
};

class DetectedLine
{
private:
	Vec4i _line;

public:
	DetectedLine(Vec4i line);
	~DetectedLine();
	Intersection GetIntersectionPoint(DetectedLine otherLine);
	Vec4i GetLine();
};
