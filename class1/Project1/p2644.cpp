#include <bits/stdc++.h>
using namespace std;

bool graph[101][101];
bool visited[101];
int n, m, p1, p2;
int chon = false;

void dfs(int people, int cnt) {
	//현재 탐색 중인 사람을 방문중으로 갱신
	visited[people] = true;

	//두 번째 사람의 촌수를 찾음
	if (people == p2) {
		cout << cnt;
		chon = true;
		return;
	}
	//못찾으면, dfs 탐색
	for (int i = 1; i <= n; i++) {
		//현재 탐색하는 사람이 누구(i)랑 연결되어 있는지
		//연결된 사람이 방문되었는지
		if (graph[people][i] && !visited[i]) {
			dfs(i, cnt + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int x, y;

	cin >> n >> p1 >> p2 >> m;

	while (m--) {
		cin >> x >> y;
		//양방향 그래프
		graph[x][y] = true;
		graph[y][x] = true;
	}

	dfs(p1, 0);

	if (chon == false) cout << -1;


	return 0;
}