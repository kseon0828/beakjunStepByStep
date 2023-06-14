#include <bits/stdc++.h>
using namespace std;

int Map[128][128];
int length;
int white = 0, blue = 0;

//�Է� ���� ��и��� ������� �� ������ Ȯ���ϴ� ��
bool check(int len, int x, int y) {
	int temp = Map[x][y];
	for (int i = 0; i < (len / 2); i++) {
		for (int j = 0; j < (len / 2); j++) {
			if (temp != Map[x + i][y + j]) {
				return false;
			}
		}
	}
	
	temp == 0 ? white++ : blue++;

	return true;
}

void divide(int len, int x, int y) {
	//1,2,3,4�и��� �ɰ��� �˻���
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			//check�� false�� �ش� ��и��� ������ ���� �ʴٴ� ��
			//���� �� divide �ؾ���
			if (!check(len, x + (len / 2) * i, y + (len / 2) * j)) {
				divide(len / 2, x + (len / 2) * i, y + (len / 2) * j);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);


	cin >> length;
	//Map �Է� ����
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {			
			cin >> Map[i][j];
		}
	}

	//�̰Ͷ����� ó���� Ʋ�ȴµ�,
	//Map ��ü�� �� ���� ���� �� �ִٴ� �� Ȯ���ؾ� ��
	int temp = Map[0][0], keepGo=0;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			if (temp != Map[i][j]) {
				keepGo = 1;
				break;
			}
		}
	}

	if (keepGo) {
		//���� ����
		divide(length, 0, 0);
	}
	else {
		temp == 0 ? white++ : blue++;
	}

	cout << white << '\n' << blue;

	return 0;
}