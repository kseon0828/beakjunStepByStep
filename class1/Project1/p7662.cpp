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
				//���� �����ϰ� �ּҰ� ����� ��� �� ���� ��� ����
				if (!ms.empty() && inputNum == -1) {
					ms.erase(ms.begin());
				}
				//������ ��� ����
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