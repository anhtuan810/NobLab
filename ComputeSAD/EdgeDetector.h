#ifndef EDGEDETECTOR_H_
#define EDGEDETECTOR_H_

#include "opencv2/core/core.hpp"

class EdgeDetector
{
public:
	EdgeDetector();
	~EdgeDetector();

	cv::Mat PerformEdgeDetection(cv::Mat inputFrame);

private:
	cv::Mat PerformSobelEdgeDetection(cv::Mat inputFrame);
	cv::Mat PerformLaplacianEdgeDetection(cv::Mat inputFrame);
	cv::Mat PerformCannyEdgeDetection(cv::Mat inputFrame);
};


#endif