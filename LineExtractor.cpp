#include "LineExtractor.h"


LineExtractor::LineExtractor()
{
}


LineExtractor::~LineExtractor()
{
}

vector<Vec4i> LineExtractor::ExtractLines(Mat image)
{
	Mat edges;
	blur(image, image, Size(5, 5));
	Canny(image, edges, 100, 50, 3);

	//namedWindow("Canny");
	//imshow("Canny", edges);

	vector<Vec4i> lines;
	HoughLinesP(edges, lines, Rho, Theta, Threshold, MinLineLength, MaxLineGap);

	return lines;
}
