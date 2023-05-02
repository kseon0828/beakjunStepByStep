#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n, inputNum;
	vector<int> v;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> inputNum;
		v.push_back(inputNum);
	}

	int max = *max_element(v.begin(), v.end());
	int min = *min_element(v.begin(), v.end());

	cout << min << " " << max;

	return 0;
}