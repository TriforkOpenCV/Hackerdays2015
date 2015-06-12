/*
 * CornerHistogramAnalyzer.h
 *
 *  Created on: Jun 12, 2015
 *      Author: nsh
 */

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

class CornerHistogramAnalyzer {
public:
	CornerHistogramAnalyzer();
	virtual ~CornerHistogramAnalyzer();
	bool IsLowerLeftCornerOfPaper(Point2f point, Mat image);
};

