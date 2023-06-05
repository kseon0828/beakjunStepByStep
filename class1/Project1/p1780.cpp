#include <bits/stdc++.h>
using namespace std;

int arr[2200][2200];
int cnt[3]; //-1, 0, 1의 종이의 개수

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
	//x,y 좌표에서 한변의 길이만큼 가로 세로의 수가 같은지 확인
	//같다면 cnt에서 해당 수의 개수를 하나 증가
	//그리고 현재 재귀를 return으로 끝냄
	if (check(x, y, n)) {
		int paperNum = arr[x][y];
		cnt[paperNum + 1]++;
		return;
	}
	
	//해당 페이지에 수가 같지 않으면 3으로 쪼개서 탐색 시작
	int div = n / 3;

	//노션 그림으로 설명
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

	//탐색하고자하는 좌표와 종이의 한변의 길이를 전달
	seperatePaper(0, 0, n);

	for (int i = 0; i < 3; i++) {
		cout << cnt[i] << '\n';
	}

	return 0;
}