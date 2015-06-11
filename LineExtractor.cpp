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

	namedWindow("Canny");
	imshow("Canny", edges);

	vector<Vec4i> lines;
	HoughLinesP(edges, lines, 1, CV_PI / 180, 50, 100, 10);

	for (size_t i = 0; i < lines.size(); i++)
	{
		Vec4i l = lines[i];
		line(image, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 1, CV_AA);
	}

	Mat small;
	resize(image, small, Size(0,0), 0.5, 0.5);
	namedWindow("Display Image", WINDOW_AUTOSIZE);
	imshow("Display Image", small);
	waitKey(0);

	return lines;
}
