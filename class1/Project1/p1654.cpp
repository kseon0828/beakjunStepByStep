#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n, k, line, cm=0, maxi=0;
	long long low, high, mid; //�̺� Ž���� �ʿ��� ������
	int lines[10001];

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> lines[i];

		//���� �� ���� �������� �̺� Ž�� ������ ����
		if (maxi < lines[i]) maxi = lines[i];
	}

	low = 1;
	high = maxi;

	//low�� high�� �����Ҷ� ���� ����
	while (low <= high) {
		mid = (low + high) / 2;

		int cnt = 0; //k���� �ѱ�� ���ǿ� ����
		for (int i = 0; i < n; i++) cnt += lines[i] / mid;

		//���� ���� k���� ũ��, ���� �κ��� Ž��
		if (cnt >= k) {
			low = mid + 1;
			if (cm < mid) cm = mid;
		}
		//�׷��� ������, ���� �κ��� Ž���Ͽ� cm�� �ٿ���
		else {
			high = mid - 1;
		}
	}

	cout << cm;


	return 0;
}