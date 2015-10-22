#include <iostream>
#include <fstream>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "Constants.h"
#include "DataStream.h"
#include "EdgeDetector.h"
#include "TemplateMatching.h"
#include "TemplateMatchingTester.h"

using namespace std;
using namespace cv;

void main()
{
	char* fileName = "C:\\WORKPLACE\\SampleData_15m\\8_backward_slow_ok\\vid2.bin";
/*

	DataStream stream(fileName);
	stream.ReadAllData();

	Mat sampleFrame1 = stream.Frames[14000];
	Mat sampleFrame2 = stream.Frames[14005];

	EdgeDetector edgeDetector;
	Mat edgeResult1 = edgeDetector.PerformEdgeDetection(sampleFrame1);
	Mat edgeResult2 = edgeDetector.PerformEdgeDetection(sampleFrame2);

	TemplateMatching templateMatching;
	auto result = templateMatching.PerformMatching(edgeResult1, edgeResult2);
	namedWindow("Test1", WINDOW_KEEPRATIO);
	imshow("Test1", result.CorrelationMatrix);
	waitKey(0);*/


	TemplateMatchingTester tester;
	tester.Test(fileName);
	

}