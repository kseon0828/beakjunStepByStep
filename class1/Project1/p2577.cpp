#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int numCount[10] = { 0 };
	int inputNum;
	int mul = 1;

	for (int i = 0; i < 3; i++) {
		cin >> inputNum;
		mul *= inputNum;
	}

	while (mul != 0) {
		numCount[mul % 10]++;
		mul /= 10;
	}

	for (int i = 0; i < 10; i++) {
		printf("%d\n", numCount[i]);
	}

	return 0;
}