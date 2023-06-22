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
#include<cmath>
int Tasks::tapeEquilibrium(vector<int>& A)
{
	unsigned long int left = 0, right = 0;

	left = A[0];

	for (int number : A) {
		right += number;
	}
	right -= A[0];

	int lowestDifference = INT_MAX;
	for (int i = 1; i < A.size(); i++) {
		int result = left - right;
		if (abs(result) < lowestDifference) {
			lowestDifference = abs(result);
		}
		left += A[i];
		right -= A[i];
	}

	return lowestDifference;
}
#include<unordered_set>
int Tasks::frogRiverOne(int X, vector<int>& A)
{
	if (A.size() < X) {
		return -1;
	}

	unordered_set<int> path;
	for (unsigned int i = 0; i < A.size(); i++) {
		path.insert(A[i]);

		if (path.size() == X) {
			return i;
		}
	}

	return -1;
}
#include<set>
int Tasks::permCheck(vector<int>& A)
{
	multiset<int> numbers;

	for (int number : A) {
		numbers.insert(number);
	}

	int nextNumber = 1;

	for (int key : numbers) {
		if (key != nextNumber) {
			return 0;
		}
		nextNumber++;
	}

	return 1;
}
#include <algorithm>
vector<int> Tasks::maxCounters(int N, vector<int>& A)
{
	vector<int> result(N, 0);
	int maxElement = 0;
	int currentMaxElement = 0;
	for (int i = 0; i < A.size(); i++) {
		if (A[i] > N) {
			//maxElement = *max_element(result.begin(), result.end());
			if (maxElement < currentMaxElement) {
				maxElement = currentMaxElement;
			}
		}else {
			result[A[i] - 1] = max(maxElement + 1, result[A[i] - 1] + 1);
			if (currentMaxElement < result[A[i] - 1]) {
				currentMaxElement = result[A[i] - 1];
			}
		}
			
	}

	for (int i = 0; i < result.size(); i++) {
		if (result[i] < maxElement) {
			result[i] = maxElement;
		}
	}

	return result;
}
#include<set>
int Tasks::missingInteger(vector<int>& A)
{
	set<int> numbers;
	for (int number : A) {
		numbers.insert(number);
	}

	int actualNumber = 1;

	for (int key : numbers) {
		if (actualNumber != key && key>0) {
			return actualNumber;
		}
		actualNumber++;
	}

	return actualNumber;
}

#include<vector>
int Tasks::passingCars(vector<int>& A)
{

	vector<int> passings;
	int westCounter = 0;

 	for(unsigned int i=0; i<A.size(); i++){
		if (A[i] == 0) {
			passings.push_back(0 - westCounter);
		}
		else {
			westCounter++;
		}
	}

	int result = 0;

	for (int number : passings) {
		result += (number + westCounter);
		if (result > 1000000000) {
			return -1;
		}
	}
	
	return result;
}

#include<cmath>
int Tasks::countDiv(int A, int B, int K)
{
	int bDivisors = B / K;
	int aDivisors = A / K;
	int aIsDivisor = (A % K == 0 ? 1 : 0);
	int result = bDivisors - aDivisors + aIsDivisor;
	return result;
}

#include <set>
int Tasks::distinct(vector<int>& A)
{
	unordered_set<int> uniqueNumbers;
	for (int number : A) {
		uniqueNumbers.insert(number);
	}

	return uniqueNumbers.size();
}


#include <algorithm>
int Tasks::maxProductOfThree(vector<int>& A)
{	
	sort(A.begin(), A.end());

	int firstThree = A[0] * A[1] * A[2];
	int firstTwoOneLast = A[0] * A[1] * A[A.size()-1];
	int lastThree = A[A.size() - 1] * A[A.size() - 2] * A[A.size() - 3];
	int lastTwoOneFirst = A[A.size() - 1] * A[A.size() - 2] * A[0];

	return max({ firstThree, firstTwoOneLast, lastThree, lastTwoOneFirst });
}

#include <algorithm>
int Tasks::triangle(vector<int>& A)
{
	if (A.size() < 3) return 0;

	sort(A.begin(), A.end());

	for (int i = 0; i < A.size() - 2; i++) 
		if(A[i] >= 0 && A[i] > A[i + 2] - A[i + 1]) return 1;
	
	return 0;

}

//THIS TASK SCORED 81% AND SO FAR I DON'T KNOW HOW TO MAKE IT FASTER
//int Tasks::numberOfDiscIntersections(vector<int>& A)
//{
//	int n = A.size();
//	int sum = 0;
//	int interect = 0;
//	long total = n * (n - 1) / 2;
//	for (int i = 0; i < n; i++) {
//		for (int right = i + 1; right < n; right++) {
//			if (right - A[i] - i > A[right]) { 
//				sum++;
//			}
//		}
//	}
//
//	if ((total - sum) > 10000000) {
//		return -1;
//	}
//	return (total - sum);
//}
#include<stack>
int Tasks::brackets(string& S)
{

	stack<char> brackets;
	for (char c : S) {
		if (c == '(' || c == '{' || c == '[') {
			brackets.push(c);
			continue;
		}else if (brackets.top() == '(' && c==')') {
			brackets.pop();
		}else if (brackets.top() == '{' && c == '}') {
			brackets.pop();
		}else if (brackets.top() == '[' && c == ']') {
			brackets.pop();
		}else {
			return 0;
		}
	}

	if (brackets.empty()) {
		return 1;
	}

	return 0;
}

#include <stack>
int Tasks::fish(vector<int>& A, vector<int>& B)
{
	stack<int> downstream;
	int eatenFishes = 0;
	for (int i = 0; i < A.size(); i++) {

		if (B[i] == 1) {
			downstream.push(A[i]);
		}else {
			while (!downstream.empty()) {
				if (downstream.top() > A[i]) {
					eatenFishes++;
					break;
				}else {
					eatenFishes++;
					downstream.pop();
				}
			}
		}
	}
	return A.size() - eatenFishes;
}
#include<stack>
int Tasks::nesting(string& S)
{
	if (S.size() % 2 == 1) {
		return 0;
	}
	stack<int> brackets;
	for (char c : S) {
		if (c == '(') {
			brackets.push(c);
		}
		else {
			if (brackets.top() == '(') {
				brackets.pop();
			}else {
				return 0;
			}
		}
	}

	if (brackets.empty())
		return 1;


	return 0;
	
	
}
