#include<iostream>
#include<bitset>

int binaryGap(int N) {
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

int main() {
	std::cout << binaryGap(561892) << std::endl;

	return 0;
}