#pragma once
#include <vector>

using namespace std;

class Tasks
{
public:
	int binaryGap(int N);
	vector<int> cyclicRotation(vector<int>& A, int K);
	int oddOccurancesInArray(vector<int>& A);
	int frogJmp(int X, int Y, int D);
	int permMissingElem(vector<int>& A);
	int tapeEquilibrium(vector<int>& A);
	int frogRiverOne(int X, vector<int>& A);
	int permCheck(vector<int>& A);
	vector<int> maxCounters(int N, vector<int>& A);

};

