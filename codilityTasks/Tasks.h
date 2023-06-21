#pragma once
#include <vector>
#include <string>

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
	int missingInteger(vector<int>& A);
	int passingCars(vector<int>& A);
	int countDiv(int A, int B, int K);
	int distinct(vector<int>& A);
	int maxProductOfThree(vector<int>& A);
	int triangle(vector<int>& A);
	//int numberOfDiscIntersections(vector<int>& A);
	int brackets(string& S);
	int fish(vector<int>& A, vector<int>& B);
};

