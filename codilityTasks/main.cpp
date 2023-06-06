#include <iostream>

#include "Tasks.h"


int main() {
	Tasks T;
	//cout << T.binaryGap(561892) << std::endl;
	vector<int> z2{};
	vector<int> zad2 = T.cyclicRotation(z2, 10);
	for (int i : zad2) {
		cout << i << endl;
	}


	return 0;
}