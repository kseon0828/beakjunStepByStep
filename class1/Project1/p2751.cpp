#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n, inputNum;
	priority_queue<int> pq;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> inputNum;
		pq.push(-inputNum);
	}

	for (int i = 0; i < n; i++) {
		cout<<-pq.top()<<'\n';
		pq.pop();
	}

	return 0;
}