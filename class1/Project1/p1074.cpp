#include <bits/stdc++.h>
using namespace std;

int n, r, c;
int cnt = 0;

void dc(int x, int y, int size) {
	//찾는 행열과 현재 좌표가 일치하면, 함수 중단
	if (c == x && r == y) {
		cout << cnt;
		return;
	}
	//찾으려는 행열이 현재 좌표가 있는 4분면 안에 위치한다면
	//4분면으로 분할을 진행하여 계속 탐색 진행
	else if (c < x + size && r < y + size && c >= x && r >= y) {
		//Z 순서로 탐색 진행
		dc(x, y, size / 2);
		dc(x + size / 2, y, size / 2);
		dc(x, y + size / 2, size / 2);
		dc(x + size / 2, y + size / 2, size / 2);
	}
	//찾으려는 행렬이 4분면에 존재하지 않는다면
	//현재 사분면을 탐색할 필요가 없어서 cnt를 더하고, 재귀 진행하지 않음
	else {
		cnt += size * size;
	}
}

int main(void) {

	cin >> n >> r >> c;

	//dc 재귀 함수에 현재 위치하는 좌표와 그래프의 크기를 입력
	//크기가 2^n인 그래프에서 (0,0)부터 탐색 시작
	dc(0, 0, pow(2, n));

	return 0;
}