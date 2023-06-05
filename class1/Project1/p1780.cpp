#include <bits/stdc++.h>
using namespace std;

int arr[2200][2200];
int cnt[3]; //-1, 0, 1�� ������ ����

bool check(int x, int y, int n) {
	int temp = arr[x][y];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[x + i][y + j] != temp)
				return false;
		}
	}
	return true;
}

void seperatePaper(int x, int y, int n) {
	//x,y ��ǥ���� �Ѻ��� ���̸�ŭ ���� ������ ���� ������ Ȯ��
	//���ٸ� cnt���� �ش� ���� ������ �ϳ� ����
	//�׸��� ���� ��͸� return���� ����
	if (check(x, y, n)) {
		int paperNum = arr[x][y];
		cnt[paperNum + 1]++;
		return;
	}
	
	//�ش� �������� ���� ���� ������ 3���� �ɰ��� Ž�� ����
	int div = n / 3;

	//��� �׸����� ����
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			seperatePaper(x + div * i, y + div * j, div);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	//Ž���ϰ����ϴ� ��ǥ�� ������ �Ѻ��� ���̸� ����
	seperatePaper(0, 0, n);

	for (int i = 0; i < 3; i++) {
		cout << cnt[i] << '\n';
	}

	return 0;
}