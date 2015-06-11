#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void ProcessImage(Mat input)
{
	Mat image;
	resize(input, image, Size(), 0.25, 0.25, INTER_NEAREST);

	Mat edges;
	blur(image, image, Size(5, 5));
	Canny(image, edges, 100, 50, 3);

	namedWindow("Canny");
	imshow("Canny", edges);

	vector<Vec4i> lines;
	HoughLinesP(edges, lines, 1, CV_PI / 180, 50, 100, 10);

	namedWindow("Display Image", WINDOW_AUTOSIZE);
	

	for (size_t i = 0; i < lines.size(); i++)
	{
		Vec4i l = lines[i];
		line(image, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 1, CV_AA);
		imshow("Display Image", image);
		waitKey(0);
	}

	

	waitKey(0);
}


int main(int argc, char** argv )
{
    /*if ( argc != 2 )
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }*/


	ProcessImage(imread("./Pictures/dong.jpg", 1));
	ProcessImage(imread("./Pictures/kajak.jpg", 1));
	ProcessImage(imread("./Pictures/hofor.jpg", 1));


    /*Mat image;
    image = imread( "./Pictures/dong.jpg", 1 );

    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }

	Mat edges;
	blur(image, image, Size(3, 3));
	Canny(image, edges, 100, 50, 3);

	vector<Vec4i> lines;
	HoughLinesP(edges, lines, 1, CV_PI / 180, 50, 50, 10);

	for (size_t i = 0; i < lines.size(); i++)
	{
		Vec4i l = lines[i];
		line(image, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 3, CV_AA);
	}

	namedWindow("Display Image", WINDOW_NORMAL);
    imshow("Display Image", image);

    waitKey(0);*/

    return 0;
}

