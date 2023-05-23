#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, inputNum;
	string op;
	stack<int> s;

	cin >> n;

	while (n--) {
		cin >> op;

		if (op == "push") {
			cin >> inputNum;
			s.push(inputNum);
		}
		else if (op == "top") {
			if (!s.empty()) cout << s.top() << '\n';
			else cout << "-1\n";
		}
		else if (op == "size") {
			cout << s.size() << '\n';			
		}
		else if (op == "pop") {
			if (!s.empty()) {
				cout << s.top() << '\n';
				s.pop();
			}
			else cout << "-1\n";
		}
		else if (op == "empty") {
			if (!s.empty()) cout <<"0\n";
			else cout << "1\n";
		}
	}

	return 0;
}