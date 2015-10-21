#ifndef TEMPLATEMATCHINGRESULT_H_
#define TEMPLATEMATCHINGRESULT_H_

#include "opencv2/core.hpp"

class TemplateMatchingResult
{
public:
	TemplateMatchingResult();
	~TemplateMatchingResult();
	TemplateMatchingResult(int offsetX, int offsetY, cv::Mat corrMatrix, double maxCorrValue);

	int OffsetX;
	int OffsetY;

	cv::Mat CorrelationMatrix;
	double MaxCorrelationValue;
};

#endif