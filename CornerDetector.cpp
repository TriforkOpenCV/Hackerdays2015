#include "CornerDetector.h"


CornerDetector::CornerDetector()
{
}


CornerDetector::~CornerDetector()
{
}

Intersection CornerDetector::DetectCorner(vector<DetectedLine*>* lines, Mat image)
{
	for (int i = 0; i < lines->size(); i++) {
		for (int j = i + 1; j < lines->size(); j++) {
			Intersection intersection = lines->at(i)->GetIntersectionPoint(lines->at(j));
			if (intersection.IsCorner) {
				cout << intersection.Angle << "\n";
			}
			if (intersection.IsCorner && std::abs(90 - intersection.Angle) < 5 ) {
				circle(image, intersection.Point, 12, Scalar(0, 255, 0), 5);
			}
		}
	}


	Mat small;
	resize(image, small, Size(0,0), 0.5, 0.5);
	namedWindow("Display Image", WINDOW_AUTOSIZE);
	imshow("Display Image", small);
	waitKey(0);





	return Intersection();
}
