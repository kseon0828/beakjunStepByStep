#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n, m, getNum, findNum;
	vector<int> v;

	cin >> n;

	while (n--) {
		cin >> getNum;
		//�Է¹��� ������ vector�� ����
		v.push_back(getNum);
	}

	//vector�� ������
	sort(v.begin(), v.end());

	cin >> m;
	while (m--) {
		cin >> findNum;
		//������ ���� ������
		//�� ���� �ּ� �ε����� �ִ� �ε����� ���̸� ���ϸ�, �� ���� ������ ���� �� ����
		cout << upper_bound(v.begin(), v.end(), findNum) - lower_bound(v.begin(), v.end(), findNum) << ' ';
	}

	return 0;
}