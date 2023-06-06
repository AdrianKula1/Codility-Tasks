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

vector<int> Tasks::cyclicRotation(vector<int>& A, int K)
{	
	if (A.size() <= 1) {
		return A;
	}

	K %= A.size();

	if (K == 0) {
		return A;
	}

	

	while (K--) {
		int lastNumber = A.back();

		int previousNumber = A[0];
		int nextNumber = A[1];
		
		for (int i = 1; i < A.size(); i++) {
			nextNumber = A[i];
			A[i] = previousNumber;

			previousNumber = nextNumber;
			
		}
		A[0] = lastNumber;
	}

	return A;
}
