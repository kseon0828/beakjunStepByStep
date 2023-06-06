#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, inputNum;
	priority_queue<int, vector<int>, greater<int>> pq;

	cin >> n;

	while (n--) {
		cin >> inputNum;

		if (inputNum == 0) {
			if (pq.empty()) cout << "0\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(inputNum);
		}
	}

	return 0;
}