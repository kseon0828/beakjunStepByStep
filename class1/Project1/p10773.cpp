#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> v;

	int n, inputNum, sum=0;
	
	cin >> n;

	while (n--) {
		cin >> inputNum;

		//0�̸� �� ���� pop
		if (inputNum == 0) {
			v.pop_back();
		}

		//0�� �ƴϸ� �� push
		else {
			v.push_back(inputNum);
		}
	}

	//accumulate�� ����� v�� ���� ����
	cout << accumulate(v.begin(), v.end(), 0);

	return 0;
}