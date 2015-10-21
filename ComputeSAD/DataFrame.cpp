#include "DataFrame.h"

using namespace cv;

DataFrame::DataFrame()
{
}

DataFrame::~DataFrame()
{
}

DataFrame::DataFrame(cv::Mat frame)
{
	_frame = frame;
}