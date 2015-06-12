#include "CornerDetector.h"



CornerDetector::CornerDetector()
{
}


CornerDetector::~CornerDetector()
{
}

bool CornerDetector::IsAngleWithinTolerance(Intersection intersection)
{
	return std::abs(90 - intersection.Angle) < AngleTolerance;
}

bool CornerDetector::IsIntersectionWithinWindow(Intersection intersection, Mat image)
{
	float height = image.size().height;
	float width = image.size().width;

	float x = width * WindowX;
	float y = height * WindowY;

	Point2f point = intersection.Point;

	Rect_<float> rect = Rect_<float>(x, y, width * WindowWidth, height * WindowHeight);
	return point.inside(rect);

}

vector<Intersection>* CornerDetector::DetectCorner(vector<DetectedLine*>* lines, Mat image)
{
	vector<Intersection>* result = new vector<Intersection>();

	for (int i = 0; i < lines->size(); i++) {
		for (int j = i + 1; j < lines->size(); j++) {
			Intersection intersection = lines->at(i)->GetIntersectionPoint(lines->at(j), MinLineLength);
			if (intersection.IsIntersection && IsAngleWithinTolerance(intersection)
				&& IsIntersectionWithinWindow(intersection, image)) {
				result->push_back(intersection);
			}
		}
	}

	return result;
}
