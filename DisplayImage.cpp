#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "LineExtractor.h"
#include "LineDetector.h"
#include "CornerDetector.h"

using namespace cv;
using namespace std;

void ProcessImage(Mat input)
{
	LineExtractor* lineExtractor = new LineExtractor();
	LineDetector* lineDetector = new LineDetector();
	CornerDetector* cornerDetector = new CornerDetector();

	vector<Vec4i> lines = lineExtractor->ExtractLines(input);
	vector<DetectedLine>* detectedLines = lineDetector->DetectLines(lines);
	Intersection corner = cornerDetector->DetectCorner(detectedLines);

	delete lineExtractor;
	delete lineDetector;
	delete cornerDetector;
}


int main(int argc, char** argv )
{
	ProcessImage(imread("./Pictures/dong.jpg", 1));
	ProcessImage(imread("./Pictures/kajak.jpg", 1));
	ProcessImage(imread("./Pictures/hofor.jpg", 1));

    return 0;
}

