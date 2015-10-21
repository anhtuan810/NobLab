#ifndef DATASTREAM_H_
#define DATASTREAM_H_
#include "opencv2/core.hpp"

class DataStream
{
public:
	DataStream();
	DataStream(char* fileName);
	~DataStream();

	int FramesNumber;
	cv::Mat* Frames;

	void ReadAllData();

private:
	char* _fileName;
	char* _rawData;
	void PrepareFrames();
};

#endif