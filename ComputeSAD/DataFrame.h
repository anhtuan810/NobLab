#ifndef DATAFRAME_H_
#define DATAFRAME_H_

#include "opencv2/core.hpp"

class DataFrame
{
public:
	DataFrame();
	~DataFrame();
	DataFrame(cv::Mat frame);
	cv::Mat ImageData;
	
private:
	cv::Mat _frame;
};

#endif
