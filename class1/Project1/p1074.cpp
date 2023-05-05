#include <bits/stdc++.h>
using namespace std;

int n, r, c;
int cnt = 0;

void dc(int x, int y, int size) {
	//ã�� �࿭�� ���� ��ǥ�� ��ġ�ϸ�, �Լ� �ߴ�
	if (c == x && r == y) {
		cout << cnt;
		return;
	}
	//ã������ �࿭�� ���� ��ǥ�� �ִ� 4�и� �ȿ� ��ġ�Ѵٸ�
	//4�и����� ������ �����Ͽ� ��� Ž�� ����
	else if (c < x + size && r < y + size && c >= x && r >= y) {
		//Z ������ Ž�� ����
		dc(x, y, size / 2);
		dc(x + size / 2, y, size / 2);
		dc(x, y + size / 2, size / 2);
		dc(x + size / 2, y + size / 2, size / 2);
	}
	//ã������ ����� 4�и鿡 �������� �ʴ´ٸ�
	//���� ��и��� Ž���� �ʿ䰡 ��� cnt�� ���ϰ�, ��� �������� ����
	else {
		cnt += size * size;
	}
}

int main(void) {

	cin >> n >> r >> c;

	//dc ��� �Լ��� ���� ��ġ�ϴ� ��ǥ�� �׷����� ũ�⸦ �Է�
	//ũ�Ⱑ 2^n�� �׷������� (0,0)���� Ž�� ����
	dc(0, 0, pow(2, n));

	return 0;
}