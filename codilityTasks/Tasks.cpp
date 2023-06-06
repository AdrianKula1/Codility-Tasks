#include "Tasks.h"

int Tasks::binaryGap(int N) {
	
	int mask = 0b1;
	int maxBinaryGap = 0;
	int currentBinaryGap = 0;


	bool firstOneFound = false;

	while (mask > 0) {

		int result = mask & N;

		//If 0 found, increment current counter
		if (result == 0 && firstOneFound) {
			currentBinaryGap++;
		}

		//If 1 found, compare counters and choose higher one and reset current counter (also, searches for first one in the number)
		if (result > 0) {
			if (!firstOneFound) {
				firstOneFound = true;
			}

			if (currentBinaryGap > maxBinaryGap) {
				maxBinaryGap = currentBinaryGap;
			}
			currentBinaryGap = 0;
		}

		//Shift mask left 1
		mask = mask << 1;
	}

	return maxBinaryGap;
}
#include <algorithm>
vector<int> Tasks::cyclicRotation(vector<int>& A, int K)
{

	if (A.size() <= 1) {
		return A;
	}

	K %= A.size();
	
	if (K == 0) {
		return A;
	}

	
	//How many times do we have to perform the rotation
	while (K--) {
		int lastNumber = A.back();

		int previousNumber = A[0];
		int nextNumber = A[1];
		
		//Swap numbers 
		for (int i = 1; i < A.size(); i++) {
			nextNumber = A[i];
			A[i] = previousNumber;

			previousNumber = nextNumber;
			
		}
		//Last number becomes first
		A[0] = lastNumber;
	}

	return A;
}


#include<unordered_map>
int Tasks::oddOccurancesInArray(vector<int>& A)
{
	unordered_map<int, int> occurances;

	for (int i : A) {
		if (occurances.find(i) == occurances.end()) {
			occurances[i] = 1;
		}else {
			occurances[i]++;
		}
	}

	for (pair<int, int> Pair : occurances) {
		if (Pair.second % 2 == 1) {
			return Pair.first;
		}
	}

	return 0;
}
#include<cmath>
int Tasks::frogJmp(int X, int Y, int D)
{
	int totalDistance = Y - X;
	double result = ceil((double)totalDistance / (double)D);

	return result;
}
#include<set>
int Tasks::permMissingElem(vector<int>& A)
{
	if (A.size() == 0) {
		return 1;
	}
	set<int> Set;
	for (int number : A) {
		Set.insert(number);
	}

	
	int nextNumber = 1;
	for (int number : Set) {
		if (number == nextNumber) {
			nextNumber++;
		}else {
			return nextNumber;
		}
	}

	return nextNumber;
}

