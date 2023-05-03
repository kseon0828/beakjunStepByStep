#include <bits/stdc++.h>
using namespace std;

int decimalT(int num) {
	for (int i = 2; i < num; i++) {
		if (num % i == 0) return 0;
	}
	return 1;
}

int main(void) {
	int n, cnt=0, inputNum;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> inputNum;
		if (inputNum == 1) continue;
		else if (decimalT(inputNum)) cnt++;
	}

	cout << cnt;

	return 0;
}