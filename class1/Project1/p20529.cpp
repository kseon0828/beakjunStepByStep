/*
참고) https://withhamit.tistory.com/512
*/

#include <bits/stdc++.h>
using namespace std;

int calcDist(string a, string b, string c) {
	int dist = 0;
	for (int i = 0; i < 4; i++) {
		dist += (a[i] != b[i]) + (b[i] != c[i]) + (c[i] != a[i]);
	}

	return dist;
}

int comb(int n, vector<string> inputMbti) {
	//사람이 33명 이상이면 겹치는 mbti가 3개 이상이므로
	//거리는 무조건 0
	if (n > 33)
		return 0;

	int minDist = 999999;
	//삼중 for문으로 조합 구현
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				minDist = min(minDist, calcDist(inputMbti[i], inputMbti[j], inputMbti[k]));
			}
		}
	}

	return minDist;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t, n;

	cin >> t;

	while (t--) {
		cin >> n;

		vector <string> inputMbti(n);

		for (int i = 0; i < n; i++)
			cin >> inputMbti[i];
		
		int dist = comb(n, inputMbti);

		cout << dist << '\n';
	}


	return 0;
}
