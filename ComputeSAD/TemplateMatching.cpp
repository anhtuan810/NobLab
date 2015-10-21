#include "TemplateMatching.h"
#include "opencv2/imgproc.hpp"
#include "Constants.h"

using namespace cv;

TemplateMatching::TemplateMatching()
{
}

TemplateMatching::~TemplateMatching()
{
}

cv::Mat TemplateMatching::PerformMatching(cv::Mat image, cv::Mat temp)
{
	_img = image;
	_temp = temp;

	int borderH = Constants::FRAME_HEIGHT - 1;
	int borderW = Constants::FRAME_WIDTH - 1;
	Mat newImg(image.rows + borderH * 2, image.cols + borderW * 2, image.depth());
	copyMakeBorder(image, newImg, borderH, borderH, borderW, borderW, BORDER_CONSTANT, 0);

	
	
	Mat matchingResult;
	matchTemplate(newImg, temp, matchingResult, CV_TM_CCORR_NORMED);

	
	
	double minVal; double maxVal; Point minLoc; Point maxLoc;
	Point matchLoc;
	minMaxLoc(matchingResult, &minVal, &maxVal, &minLoc, &maxLoc, Mat());



	int offsetW, offsetH;
	offsetW = borderW - maxLoc.x;
	offsetH = borderH - maxLoc.y;


	return matchingResult;
}