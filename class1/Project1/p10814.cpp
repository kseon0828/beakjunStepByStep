#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, string> x, pair<int, string> y) {
	//ù��° ���Ҹ� �������� �������� ����
	return x.first < y.first;
}

int main(void) {
	vector<pair<int, string>> v;

	int n, age;
	string name;

	cin >> n;

	while (n--) {
		cin >> age >> name;
		//�Է� ���� ���̿� �̸��� pair�� vector�� push��
		v.push_back({ age, name });
	}

	//stabel_sort�� �Է� ������ �����Ͽ� ������
	stable_sort(v.begin(), v.end(), compare);

	for (auto i : v) {
		cout << i.first << ' ' << i.second << '\n';
	}
}