#ifndef TEMPLATEMATCHING_H_
#define TEMPLATEMATCHING_H_

#include "opencv2/core.hpp"

class TemplateMatching
{
public:
	TemplateMatching();
	~TemplateMatching();
	cv::Mat PerformMatching(cv::Mat image, cv::Mat temp);

private:
	cv::Mat _img;
	cv::Mat _temp;
};

#endif
