#include "opencv2/core.hpp"
#include "TemplateMatchingTester.h"
#include "DataStream.h"
#include "EdgeDetector.h"
#include "TemplateMatching.h"
#include <vector>
#include <iostream>

using namespace cv;
using namespace std;

void TemplateMatchingTester::Test(char* fileName)
{
	DataStream stream(fileName);
	stream.ReadAllData();

	std::vector<int> offsetX;
	std::vector<int> offsetY;
	std::vector<double> maxVal;

	for (int i = 0; i < stream.FramesNumber - 1; ++i)
	{
		Mat frm1 = stream.Frames[i];
		Mat frm2 = stream.Frames[i + 1];

		EdgeDetector edgeDetector;
		Mat edgeResult1 = edgeDetector.PerformEdgeDetection(frm1);
		Mat edgeResult2 = edgeDetector.PerformEdgeDetection(frm2);

		TemplateMatching templateMatching;
		auto result = templateMatching.PerformMatching(edgeResult1, edgeResult2);

		offsetX.push_back(result.OffsetX);
		offsetY.push_back(result.OffsetY);
		maxVal.push_back(result.MaxCorrelationValue);

		cout << i << "\n";
	}
}