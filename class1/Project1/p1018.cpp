#include <stdio.h>
#include <iostream>
using namespace std;

char wb[8][8];
char bw[8][8];

void make_map() {
	for (int i = 0; i < 8; i++)
	{
		if (i % 2 == 0) {
			for (int j = 0; j < 8; j+=2) {
				wb[i][j] = 'W';
				bw[i][j] = 'B';
			}
			for (int j = 1; j < 8; j+=2) {
				wb[i][j] = 'B';
				bw[i][j] = 'W';
			}
		}
		else {
			for (int j = 0; j < 8; j += 2) {
				wb[i][j] = 'B';
				bw[i][j] = 'W';
			}
			for (int j = 1; j < 8; j += 2) {
				wb[i][j] = 'W';
				bw[i][j] = 'B';
			}
		}

	}
}

int main() {
	make_map();

	int n, m;
	int min = 9999;
	int num;

	scanf("%d %d", &n, &m);
	char** board = new char* [n];
	for (int i = 0; i < n; i++) board[i] = new char[m];

	//board 입력 받기
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	for(int i=0; i<n-8+1; i++)
		for (int j = 0; j < m - 8 + 1; j++) {
			int num1= 0;
			int num2 = 0;
			for (int x = 0; x < 8; x++)
				for (int y = 0; y < 8; y++) {
					if (board[i + x][j + y] != bw[x][y]) num1++;
					if (board[i + x][j + y] != wb[x][y]) num2++;
				}

			if (num1 < num2) {
				min = (min < num1) ? min : num1;
			}
			else min = (min < num2) ? min : num2;
		}

	printf("%d", min);
	return 0;
}