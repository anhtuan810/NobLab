#include "TemplateMatchingResult.h"

TemplateMatchingResult::TemplateMatchingResult()
{
}

TemplateMatchingResult::~TemplateMatchingResult()
{
}

TemplateMatchingResult::TemplateMatchingResult(int offsetX, int offsetY, cv::Mat corrMatrix, double maxCorrValue)
{
	OffsetX = offsetX;
	OffsetY = offsetY;
	CorrelationMatrix = corrMatrix;
	MaxCorrelationValue = maxCorrValue;
}