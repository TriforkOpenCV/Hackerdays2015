/*
 * CornerHistogramAnalyzer.cpp
 *
 *  Created on: Jun 12, 2015
 *      Author: nsh
 */

#include "CornerHistogramAnalyzer.h"

CornerHistogramAnalyzer::CornerHistogramAnalyzer() {
}

CornerHistogramAnalyzer::~CornerHistogramAnalyzer() {
}

bool CornerHistogramAnalyzer::IsLowerLeftCornerOfPaper(Point2f point, Mat original)
{
	//Mat cropped = original(Rect(0,0,20,30));

	Mat image(original.size(), CV_8UC1);
	cvtColor(original, image, CV_BGR2GRAY);

	MatND hist;
	int nImages = 1;
	int channels[] = { 0, 1 };
	Mat mask = Mat();
	int dims = 1;
	int hbins = 5, sbins = 2;
	int histSize[] = {hbins};

	float hranges[] = { 0, 180 };
	    // saturation varies from 0 (black-gray-white) to
	    // 255 (pure spectrum color)
	float sranges[] = { 0, 256 };
	const float* ranges[] = { hranges };
	bool uniform = true;
	bool accumulate = false;

	calcHist(&image, nImages, channels, mask, hist, 1, histSize, ranges, uniform, accumulate);


	double maxVal=0;
	minMaxLoc(hist, 0, &maxVal, 0, 0);

	int scale = 10;
	Mat histImg = Mat::zeros(sbins*scale, hbins*10, CV_8UC3);

	for( int h = 0; h < hbins; h++ ) {
		cout << "hist " << hist.at<float>(h)*100/maxVal << "\n";
		/*
	        for( int s = 0; s < sbins; s++ )
	        {
	            float binVal = hist.at<float>(h, s);
	            int intensity = cvRound(binVal*255/maxVal);
	            rectangle( histImg, Point(h*scale, s*scale),
	                        Point( (h+1)*scale - 1, (s+1)*scale - 1),
	                        Scalar::all(intensity),
	                        CV_FILLED );
	        }
	        */
	}

	    namedWindow( "H-S Histogram", 1 );
	    imshow( "H-S Histogram", histImg );
	    waitKey();
}


