#include <bits/stdc++.h>
using namespace std;

deque <int> dq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int testCase, numCnt;
	string order, tempInput, s;

	cin >> testCase;
	while (testCase--) {
		cin >> order;
		cin >> numCnt;
		cin >> tempInput;

		//������ �ڸ���, �ĸ� ���ο� ���� dq�� ���� �ϴ� ���� ���� ����� ���� �����ؾ� �ؼ�
		//�� ������� ����
		for (int i = 0; i < tempInput.length(); i++) {
			if (isdigit(tempInput[i])) {
				s += tempInput[i];

			}
			else {
				if (!s.empty()) {
					dq.push_back(stoi(s));
					s = "";
				}
			}
		}

		bool errorTemp = false;
		int backTemp = 0; //0�̸� �տ��� ����, 1�̸� �ں���
		for (char c : order) {
			if (c == 'R') backTemp = (backTemp + 1) % 2;
			else {
				if (dq.empty()) {
					cout << "error\n";
					errorTemp = true;
					break;
				}
				if (backTemp) {
					dq.pop_back();
				}
				else {
					dq.pop_front();
				}
			}
		}

		if (!errorTemp) {
			cout <<'[';
		}
		if(backTemp && !dq.empty()) {
			for (auto o = dq.rbegin(); o != dq.rend(); o++) {
				if (o == dq.rend() - 1)
					cout << *o;
				else
					cout << *o << ',';
			}
		}
		else if (!backTemp && !dq.empty()) {
			for (auto o = dq.begin(); o != dq.end(); o++) {
				if (o == dq.end() - 1)
					cout << *o;
				else
					cout << *o << ',';
			}
		}
		if (!errorTemp)
			cout << "]\n";


		dq.clear();
	}



	return 0;
}