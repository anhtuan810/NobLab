#ifndef TEMPLATEMATCHING_H_
#define TEMPLATEMATCHING_H_

#include "opencv2/core.hpp"
#include "TemplateMatchingResult.h"

class TemplateMatching
{
public:
	TemplateMatching();
	~TemplateMatching();
	TemplateMatchingResult PerformMatching(cv::Mat image, cv::Mat temp);

private:
	cv::Mat AddBorderToImage(cv::Mat image);
	cv::Mat MatchTemplateWithBorderImg(cv::Mat image, cv::Mat temp);
	TemplateMatchingResult TemplateMatching::FindOffsetFromCorrMatrix(cv::Mat corrMatrix);
};

#endif
