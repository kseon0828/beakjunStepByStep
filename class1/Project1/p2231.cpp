#include <bits/stdc++.h>
using namespace std;


int main(void) {
	int n;

	cin >> n;

	int sum, part;


	for (int i = 1; i <n; ++i) {
		sum = i;
		part = i;

		while (part) {
			sum += part % 10;
			part /= 10;
		}

		if (sum == n) {
			cout << i;
			return 0;
		}
	}

	cout << 0;
	
	return 0;
}