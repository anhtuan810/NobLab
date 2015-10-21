#include <iostream>
#include <fstream>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "Constants.h"
#include "DataStream.h"
#include "EdgeDetector.h"
#include "TemplateMatching.h"

using namespace std;
using namespace cv;

void main()
{
	//Mat img;
	//img = imread("C:\\test.png");
	//namedWindow("Test");
	//imshow("Test", img);
	//waitKey();

	char* fileName = "C:\\WORKPLACE\\SampleData_15m\\7_forward_slow_ok\\vid1.bin";

	//ifstream stream;
	//char* rawData;

	//stream.open(fileName, ios::in | ios::binary | ios::ate);
	//long begin = 0;
	//long end = 0;
	//if (stream.is_open())
	//{
	//	begin = stream.tellg();
	//	rawData = new char[begin];
	//	stream.seekg(0, ios::end);
	//	stream.read(rawData, begin);
	//	end = stream.tellg();
	//}
	//
	//stream.close();

	//long size = begin / (84 * 162);

	//cout << size;

	DataStream stream(fileName);
	stream.ReadAllData();

	Mat sampleFrame1 = stream.Frames[14000];
	Mat sampleFrame2 = stream.Frames[14005];

	EdgeDetector edgeDetector;
	Mat edgeResult1 = edgeDetector.PerformEdgeDetection(sampleFrame1);
	Mat edgeResult2 = edgeDetector.PerformEdgeDetection(sampleFrame2);

	//namedWindow("Test1", WINDOW_KEEPRATIO);
	//imshow("Test1", edgeResult1);

	//namedWindow("Test2", WINDOW_KEEPRATIO);
	//imshow("Test2", edgeResult2);
	//waitKey(0);

	TemplateMatching templateMatching;
	auto result = templateMatching.PerformMatching(edgeResult1, edgeResult2);
	namedWindow("Test1", WINDOW_KEEPRATIO);
	imshow("Test1", result.CorrelationMatrix);
	waitKey(0);
}