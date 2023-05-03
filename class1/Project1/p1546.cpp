#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n, score;
	double sum = 0;
	vector<int> scores;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> score;
		scores.push_back(score);
	}

	int max = *max_element(scores.begin(), scores.end());
	
	for (int i = 0; i < n; i++) {
		sum += ((double)scores[i] / max) * 100;
	}

	cout << sum / n;

	return 0;
}