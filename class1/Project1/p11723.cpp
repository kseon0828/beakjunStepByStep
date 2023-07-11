#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	set <int> s;

	int m, x;
	string order;

	cin >> m;
	while (m--) {
		cin >> order;

		if (order == "add") {
			cin >> x;
			s.insert(x);
		}
		else if (order == "remove") {
			cin >> x;
			s.erase(x);
		}
		else if (order == "check") {
			cin >> x;
			//찾는 요소가 없음
			if (s.find(x) == s.end()) {
				cout << "0\n";
			}
			//찾는 요소가 있음
			else {
				cout << "1\n";
			}
		}
		else if (order == "toggle") {
			cin >> x;
			if (s.find(x) == s.end()) {
				s.insert(x);
			}
			else {
				s.erase(x);
			}
		}
		else if (order == "all") {
			for (int i = 1; i <= 20; i++) {
				s.insert(i);
			}
		}
		else if (order == "empty") {
			s.erase(s.begin(), s.end());
		}
	}


	return 0;
}