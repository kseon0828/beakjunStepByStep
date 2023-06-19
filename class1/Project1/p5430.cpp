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

		//숫자의 자리수, 컴마 여부에 따라 dq에 들어가야 하는 수를 많은 경우의 수로 고려해야 해서
		//이 방법으로 진행
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
		int backTemp = 0; //0이면 앞에서 부터, 1이면 뒤부터
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