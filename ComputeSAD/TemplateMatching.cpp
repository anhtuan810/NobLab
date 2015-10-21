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

TemplateMatchingResult TemplateMatching::PerformMatching(Mat image, Mat temp)
{
	Mat imgWithBorder = AddBorderToImage(image);

	Mat correlationMatrix = MatchTemplateWithBorderImg(imgWithBorder, temp);
	
	return FindOffsetFromCorrMatrix(correlationMatrix);
}

cv::Mat TemplateMatching::AddBorderToImage(cv::Mat image)
{
	int borderH = Constants::FRAME_HEIGHT - 1;
	int borderW = Constants::FRAME_WIDTH - 1;
	Mat newImg(image.rows + borderH * 2, image.cols + borderW * 2, image.depth());
	copyMakeBorder(image, newImg, borderH, borderH, borderW, borderW, BORDER_CONSTANT, 0);

	return newImg;
}

Mat TemplateMatching::MatchTemplateWithBorderImg(cv::Mat image, cv::Mat temp)
{
	Mat corrMatrix;
	matchTemplate(image, temp, corrMatrix, CV_TM_CCORR_NORMED);
	return corrMatrix;
}

TemplateMatchingResult TemplateMatching::FindOffsetFromCorrMatrix(Mat corrMatrix)
{
	double minVal; double maxVal; Point minLoc; Point maxLoc;
	minMaxLoc(corrMatrix, &minVal, &maxVal, &minLoc, &maxLoc, Mat());

	int offsetW, offsetH;
	offsetW = Constants::FRAME_WIDTH - 1 - maxLoc.x;
	offsetH = Constants::FRAME_HEIGHT - 1 - maxLoc.y;

	TemplateMatchingResult result(offsetW, offsetH, corrMatrix, maxVal);

	return result;
}