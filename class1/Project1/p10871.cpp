#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n, x, inputNum;

	cin >> n >> x;

	for (int i = 0; i < n; i++) {
		cin >> inputNum;
		if (inputNum < x) cout << inputNum << " ";
	}

	return 0;
}