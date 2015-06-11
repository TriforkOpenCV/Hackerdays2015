#include "LineExtractor.h"


LineExtractor::LineExtractor()
{
}


LineExtractor::~LineExtractor()
{
}

vector<Vec4i> LineExtractor::ExtractLines(Mat inputImage)
{
	Mat image;
	resize(inputImage, image, Size(), 0.25, 0.25, INTER_NEAREST);

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

	namedWindow("Display Image", WINDOW_AUTOSIZE);
	imshow("Display Image", image);
	waitKey(0);

	return lines;
}