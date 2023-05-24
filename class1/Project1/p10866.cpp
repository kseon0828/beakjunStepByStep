#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	deque<int> dq;

	int n, inputNum;
	string op;

	cin >> n;

	while (n--) {
		cin >> op;

		if (op == "push_front") {
			cin >> inputNum;
			dq.push_front(inputNum);
		}
		else if (op == "push_back") {
			cin >> inputNum;
			dq.push_back(inputNum);
		}
		else if (op == "pop_front") {
			if (!dq.empty()) {
				cout << dq.front()<<'\n';
				dq.pop_front();
			}
			else cout << "-1\n";
		}
		else if (op == "pop_back") {
			if (!dq.empty()) {
				cout << dq.back()<<'\n';
				dq.pop_back();
			}
			else cout << "-1\n";
		}
		else if (op == "size") {
			cout << dq.size()<<'\n';
		}
		else if (op == "empty") {
			if (!dq.empty()) cout << "0\n";
			else cout << "1\n";
		}
		else if (op == "front") {
			if (!dq.empty()) cout << dq.front() << '\n';
			else cout << "-1\n";
		}
		else if (op == "back") {
			if (!dq.empty()) cout << dq.back() << '\n';
			else cout << "-1\n";
		}
	}

	return 0;
}