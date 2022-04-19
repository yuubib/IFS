#pragma once
#include"matrix.h"
#include"image.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <assert.h>
#include <random>
using namespace std;
class IFS
{
public:
	IFS(const char* filename);
	~IFS();
	int transNum;
	vector<Matrix> transFunc;
	vector<float> transProb;

	void render(Image& img, int pointsNum, int iterNum);
};
