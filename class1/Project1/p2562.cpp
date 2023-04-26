#include <iostream>
using namespace std;

int main(void) {
	int num, maxNum = 0, maxIdx =0;

	for (int i = 0; i < 9; i++) {
		cin >> num;

		if (num > maxNum) {
			maxNum = num;
			maxIdx = i;
		}
	}

	printf("%d\n%d", maxNum, maxIdx+1);

	return 0;
}