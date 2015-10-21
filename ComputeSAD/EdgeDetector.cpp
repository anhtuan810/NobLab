#include "EdgeDetector.h"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;

EdgeDetector::EdgeDetector()
{
}

EdgeDetector::~EdgeDetector()
{
}

cv::Mat EdgeDetector::PerformEdgeDetection(cv::Mat inputFrame)
{
	return PerformSobelEdgeDetection(inputFrame);
}

cv::Mat EdgeDetector::PerformSobelEdgeDetection(cv::Mat inputFrame)
{
	Mat grad;
	Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y;
	
	int scale = 1;
	int delta = 0;
	int ddepth = CV_8UC1;

	// Gradient X
	Sobel(inputFrame, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT);
	convertScaleAbs(grad_x, abs_grad_x);
	
	// Gradient Y
	Sobel(inputFrame, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT);
	convertScaleAbs(grad_y, abs_grad_y);

	// Total Gradient
	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);

	//threshold(grad, grad, 100, 255, THRESH_BINARY);
	
	//adaptiveThreshold(grad, grad, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 11, 0);

	return grad;
}

cv::Mat EdgeDetector::PerformLaplacianEdgeDetection(cv::Mat inputFrame)
{
	int kernel_size = 3;
	int scale = 1;
	int delta = 0;
	int ddepth = CV_8UC1;

	Mat edge;
	Mat edge_abs;
	Mat blurred;

	//GaussianBlur(inputFrame, blurred, Size(3, 3), 0, 0, BORDER_DEFAULT);
	Laplacian(inputFrame, edge, ddepth, kernel_size, scale, delta, BORDER_DEFAULT);
	convertScaleAbs(edge, edge_abs);

	//threshold(edge_abs, edge_abs, 50, 255, ddepth);

	return edge_abs;
}

cv::Mat EdgeDetector::PerformCannyEdgeDetection(cv::Mat inputFrame)
{
	int lowThreshold = 50;
	int const maxLowThreshold = 100;
	int ratio = 3;
	int kernelSize = 3;

	Mat blurred;
	Mat edge;

	GaussianBlur(inputFrame, blurred, Size(3, 3), 0, 0, BORDER_DEFAULT);
	Canny(blurred, edge, lowThreshold, lowThreshold * ratio, kernelSize);

	return edge;
}
