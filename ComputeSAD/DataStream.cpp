#include "DataStream.h"
#include <fstream>
#include "Constants.h"
#include "opencv2/core.hpp"

using namespace std;
using namespace cv;

DataStream::DataStream()
{
}

DataStream::DataStream(char* fileName)
{
	_fileName = fileName;
}

DataStream::~DataStream()
{
}

void DataStream::ReadAllData()
{
	ifstream stream;
	long size = 0;

	stream.open(_fileName, ios::in | ios::binary | ios::ate);
	if (stream.is_open())
	{
		size = stream.tellg();
		_rawData = new char[size];
		stream.seekg(0, ios::beg);
		stream.read(_rawData, size);
	}
	stream.close();

	FramesNumber = size / (Constants::FRAME_HEIGHT * Constants::FRAME_WIDTH);
	PrepareFrames();
}

void DataStream::PrepareFrames()
{
	Frames = new Mat[FramesNumber];
	for (auto i = 0; i < FramesNumber; ++i)
	{
		Mat frame(Constants::FRAME_HEIGHT, Constants::FRAME_WIDTH, CV_8UC1, Scalar(0));
		int startIdx = i * Constants::FRAME_HEIGHT * Constants::FRAME_WIDTH;
		memcpy(&frame.data[0], &_rawData[startIdx], Constants::FRAME_HEIGHT * Constants::FRAME_WIDTH);

		Frames[i] = frame;
	}
}