#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int testCase, cnt, inputNum;
	string order;

	cin >> testCase;

	while (testCase--) {
		cin >> cnt;
		multiset <int> ms;
		for (int i = 0; i < cnt; i++) {
			cin >> order >> inputNum;

			if (order == "I") {
				ms.insert(inputNum);
			}
			else {
				//값이 존재하고 최소값 지우는 경우 맨 앞의 요소 지움
				if (!ms.empty() && inputNum == -1) {
					ms.erase(ms.begin());
				}
				//마지막 요소 지움
				else if (!ms.empty() && inputNum == 1) {
					auto it = ms.end();
					it--;
					ms.erase(it);
				}
			}
		}

		if (ms.empty()) {
			cout << "EMPTY\n";
		}
		else {
			auto end_it = ms.end();
			end_it--;
			cout << *end_it << ' ' << *ms.begin() << "\n";
		}
	}

	return 0;
}