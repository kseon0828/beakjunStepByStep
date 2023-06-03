#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	int result = 1;

	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		result *= n--;
	}

	int temp = k;
	for (int i = 0; i < temp; i++) {
		result /= k--;
	}

	cout << result;

	return 0;
}