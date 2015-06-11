#include "DetectedLine.h"

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
