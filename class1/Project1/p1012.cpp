#include <bits/stdc++.h>
using namespace std;

int tt, m, n, k; //입력 값
int sum; //총 벌레 수

//탐색 방향 설정, 상하좌우
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void bfs(int x, int y, int** array) {
	int nx, ny;
	array[x][y] = 0;

	queue <pair<int, int>> q;
	q.push({ x, y });

	while (!q.empty()) {
		int now_x = q.front().first;
		int now_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			nx = now_x + dx[i];
			ny = now_y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				//양배추가 있다면, 0으로 갱신하고
				//queue에 추가
				if (array[nx][ny] == 1) {
					array[nx][ny] = 0;
					q.push({ nx, ny });
				}
			}
		}
	}
	sum++;
}

int main() {
	int x, y; //양배추 위치 입력

	cin >> tt;

	for (int t = 0; t < tt; t++) {
		cin >> m >> n >> k;
		sum = 0;

		//2차원 동적 배열 할당
		int** array = new int* [n];
		for (int j = 0; j < n; j++) array[j] = new int[m] {0};

		//양배추의 위치 1 할당
		for (int j = 0; j < k; j++) {
			cin >> y >> x;
			array[x][y] = 1;
		}

		for (int a = 0; a < n; a++) {
			for (int b = 0; b < m; b++) {
				//그래프를 순차적으로 탐색하던 중 양배추의 위치가 1이라면
				//BFS 진행하여 연결된 양배추 구역 확인
				if (array[a][b] == 1) {
					bfs(a, b, array);
				}
			}
		}
		cout << sum << "\n";
	}
	return 0;
}