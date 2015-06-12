#include "CornerDetector.h"



CornerDetector::CornerDetector()
{
}


CornerDetector::~CornerDetector()
{
}

vector<Intersection>* CornerDetector::DetectCorner(vector<DetectedLine*>* lines, Mat image)
{
	vector<Intersection>* result = new vector<Intersection>();

	for (int i = 0; i < lines->size(); i++) {
		for (int j = i + 1; j < lines->size(); j++) {
			Intersection intersection = lines->at(i)->GetIntersectionPoint(lines->at(j), MinLineLength);
			if (intersection.IsIntersection && std::abs(90 - intersection.Angle) < AngleTolerance ) {
				result->push_back(intersection);
			}
		}
	}

	return result;
}
