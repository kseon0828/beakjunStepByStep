#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
	int num, opNum=0;

	for (int i = 0; i < 5; i++) {
		cin >> num;
		opNum += pow(num,2);
	}

	cout << opNum % 10;

	return 0;
}