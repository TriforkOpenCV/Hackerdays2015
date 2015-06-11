#include "DetectedLine.h"
#include <cmath>

DetectedLine::DetectedLine(Vec4i line)
{
	_line = line;
	DetectedLine::SetLeftMostPointFirst(_line);
}

DetectedLine::~DetectedLine()
{
}

void DetectedLine::AddLine(Vec4i other)
{
	DetectedLine::SetLeftMostPointFirst(other);
	if (_line[0] <= other[0]) {
		_line[2] = other[2];
		_line[3] = other[3];
	} else {
		_line[0] = other[0];
		_line[1] = other[1];
	}
}

void DetectedLine::SetLeftMostPointFirst(Vec4i line)
{
	if (line[0] > line[2]) {
		int tmpX = line[0];
		int tmpY = line[1];
		line[0] = line[2];
		line[1] = line[3];
		line[2] = tmpX;
		line[3] = tmpY;
	}

}

Vec4i DetectedLine::GetLine()
{
	return _line;
}

float DetectedLine::Length()
{
	float dx = _line[2] - _line[0];
	float dy = _line[3] - _line[1];
	return std::sqrt(dx*dx + dy*dy);

}

Intersection DetectedLine::GetIntersectionPoint(DetectedLine* otherLine)
{
	Vec4i other = otherLine->GetLine();
	if (DetectedLine::Length() < 500 || otherLine->Length() < 500) {
		return Intersection();
	}

	float x1 = _line[0], x2 = _line[2], x3 = other[0], x4 = other[2];
	float y1 = _line[1], y2 = _line[3], y3 = other[1], y4 = other[3];

	float d = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
	if (d == 0) return Intersection();

	float pre = (x1 * y2 - y1 * x2), post = (x3 * y4 - y3 * x4);
	float x = ( pre * (x3 - x4) - (x1 - x2) * post) / d;
	float y = ( pre * (y3 - y4) - (y1 - y2) * post) / d;

	// todo remove T-junctions

	Intersection intersection = Intersection();

	intersection.Point = Point2f(x, y);
	intersection.IsCorner = false;
	intersection.Angle = 0; // todo

	return intersection;
}
