#include <bits/stdc++.h>
using namespace std;

struct compare {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b))
			return a > b;
		return abs(a) > abs(b);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	priority_queue <int, vector<int>, compare> pq;
	int cnt, inputNum;

	cin >> cnt;

	while (cnt--) {
		cin >> inputNum;

		//입력된 수가 0이면 작은값 출력
		if (inputNum == 0) {
			if (pq.empty()) cout << "0\n";
			else {				
				cout << pq.top() <<"\n";
				pq.pop();
			}
		}
		else {
			pq.push(inputNum);
		}
	}

	return 0;
}