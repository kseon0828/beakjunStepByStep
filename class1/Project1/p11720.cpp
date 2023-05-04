#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n, sum=0;
	string num;

	cin >> n >> num;

	for (int i = 0; i < n; i++) {
		sum += (int)num[i] - 48;
	}

	cout << sum;

	return 0;
}