#include <bits/stdc++.h>
using namespace std;

int Map[128][128];
int length;
int white = 0, blue = 0;

//입력 받은 사분면의 색깔들이 다 같은지 확인하는 것
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
	//1,2,3,4분면을 쪼개서 검사함
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			//check가 false면 해당 사분면이 색깔이 같지 않다는 것
			//따라서 또 divide 해야함
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
	//Map 입력 받음
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {			
			cin >> Map[i][j];
		}
	}

	//이것때문에 처음에 틀렸는데,
	//Map 전체가 다 같은 색일 수 있다는 거 확인해야 함
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
		//분할 시작
		divide(length, 0, 0);
	}
	else {
		temp == 0 ? white++ : blue++;
	}

	cout << white << '\n' << blue;

	return 0;
}