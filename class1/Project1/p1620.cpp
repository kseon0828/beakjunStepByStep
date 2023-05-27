#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	string name, quest;
	//���ڷ� �̸��� or �̸����� ���ڸ� Ȯ���ؾ� �ϹǷ�
	//�� ��Ȳ ��� �˻��� ������ map�� �ΰ� ����
	map<int, string> keyInt;
	map<string, int> keyString;

	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> name;
		keyInt.insert({ i, name });
		keyString.insert({ name, i });
	}

	for (int i = 0; i < m; i++) {
		//�Է��� ���ڿ��ϼ��� , �����ϼ��� �ֱ� ������
		//���� �迭�� �Է� �ް�
		//[0]�� �������� ���ڿ� or ���� �˻�
		char quest[21];
		cin >> quest;

		if (quest[0] < 'A') {
			int num = atoi(quest);
			cout << keyInt[num] << '\n';
		}
		else {
			cout << keyString[quest] << '\n';
		}
	}

	return 0;
}