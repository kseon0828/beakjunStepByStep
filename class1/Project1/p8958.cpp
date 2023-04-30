#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int t;
	string inputStr;

	cin >> t;

	for (int i = 0; i < t; i++) {
		int sum = 0;
		int eachSum = 0;

		cin >> inputStr;

		for (char c : inputStr) {
			if (c == 'O') {
				eachSum++;
				sum += eachSum;
			}
			else {
				eachSum = 0;
			}
		}
		cout << sum<<'\n';
	}

	return 0;
}