#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n;
	//��, �ڷ� push, pop�� �� �ִ� deque�� ���
	deque<int> dq;

	cin >> n;

	//1���� �Է� ���� �� n���� dq�� ����
	for (int i = 1; i < n + 1; i++) dq.push_back(i);

	//�� ���� ī�带 ������ ������ n-1�� �߻�
	int m = n - 1;
	while (m--) {
		//�� ���� ī�带 ����
		dq.pop_front();
		//������ �� �� ���� ī���� ���� Ȯ���ϰ�
		int topNum = dq.front();
		//�� �ڿ� ����
		dq.push_back(topNum);
		//������ �� �� ���� ī�带 ����
		dq.pop_front();
	}

	//������ ī�尡 n-1�� �������� ���常 ���� ��
	//���� ���� ī�带 Ȯ��
	cout << dq.front();

	return 0;
}