#include <iostream>

#include "Tasks.h"


int main() {
	Tasks T;
	//Task1
	//cout << T.binaryGap(561892) << std::endl;


	//Task2
	//vector<int> z2{1, 1, 1};
	//vector<int> zad2 = T.cyclicRotation(z2, 0);
	//for (int i : zad2) {
	//	cout << i << endl;
	//}

	/*vector<int> z3{1};
	cout << T.oddOccurances(z3) << std::endl;*/

	//cout << T.frogJmp(10, 85, 30) << std::endl;

	//vector<int> z5{2, 2};
	//cout << T.permMissingElem(z5) << std::endl;

	vector<int> z6{3, 1, 2, 4, 3};
	cout << T.tapeEquilibrium(z6) << std::endl;

	return 0;
}