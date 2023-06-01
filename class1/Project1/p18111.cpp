#include <bits/stdc++.h>
using namespace std;

int arr[500][500];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//b는 인벤토리로, 인벤토리에 있는 블록을 사용해서 쌓으면 됨
	int n, m, b, inputNum;
	int minSec = INT_MAX, resultHeight;

	cin >> n >> m >> b;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	//높이가 0에서 256까지를 기준으로 모든 경우를 고려함
	for (int h = 0; h <= 256; h++) {
		int build = 0; //쌓아야 하는 블록 개수 이때, 인벤토리에 있는 값을 초과하면 X
		int remove = 0; //제거해야 하는 블록 개수

		//arr의 탐색하면서 높이의 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int diff = arr[i][j] - h; //현재 기준인 높이 h와 arr[i][j]의 높이 차이
				//차이가 0보다 크면 그만큼 블록을 빼야 함
				if (diff > 0) remove += diff;
				//차이가 0보다 작으면 그만큼 블록을 쌓아야 함
				else if (diff < 0) build -= diff;
			}
		}

		//인벤토리(기존 + 블록을 제거해서 추가)에 존재하는 개수가 
		//새롭게 쌓아야 하는 블록 개수보다 커야 함
		//안크면 갱신 안하고 다음 높이로
		if (remove + b >= build) {
			//현재 기준인 높이(h)로 맞췄을 때 걸리는 시간 계산
			int time = 2 * remove + build;
			//최소 시간보다 현재 시간이 작거나 같으면 갱신
			if (minSec >= time) {
				minSec = time;
				resultHeight = h;
			}
		}
	}

	cout << minSec << ' ' << resultHeight;

	return 0;
}