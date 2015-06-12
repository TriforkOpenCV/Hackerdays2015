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
	blur(image, image, Size(Blur, Blur));
	Canny(image, edges, CannyEdgeThreshold1, CannyEdgeThreshold2, ApertureSize);

	//namedWindow("Canny");
	//imshow("Canny", edges);

	vector<Vec4i> lines;
	HoughLinesP(edges, lines, Rho, Theta, HoughThreshold, MinLineLength, MaxLineGap);

	return lines;
}
