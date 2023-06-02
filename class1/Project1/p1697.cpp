#include <bits/stdc++.h>
using namespace std;

int visited[100001];
int n, k;

void bfs(int n) {
	queue<pair<int, int>> q;
	q.push({n,0});

	while (!q.empty()) {
		int x = q.front().first; //탐색하는 위치
		int cnt = q.front().second; //현재 걸리는 시간
		q.pop();

		//동생이 있는 곳에 방문하면 출력
		if (x == k) {
			cout << cnt;
			break;
		}

		//x에 1을 더하는 경우가 범위에 있다면
		//큐에 위치와 시간 넣어주고, 방문했다고 방문
		if (x + 1 >= 0 && x + 1 < 100001) {
			if (!visited[x + 1]) {
				visited[x + 1] = true;
				q.push({ x + 1, cnt + 1 });
			}
		}

		//x에 1을 빼는 경우가 범위에 있다면
		//큐에 위치와 시간 넣어주고, 방문했다고 방문
		if (x - 1 >= 0 && x - 1 < 100001) {
			if (!visited[x - 1]) {
				visited[x - 1] = true;
				q.push({ x - 1, cnt + 1 });
			}
		}

		//x에 2를 곱하는 경우가 범위에 있다면
		//큐에 위치와 시간 넣어주고, 방문했다고 방문
		if (x*2 >= 0 && x*2 < 100001) {
			if (!visited[x*2]) {
				visited[x*2] = true;
				q.push({ x*2, cnt + 1 });
			}
		}
	}
}

int main() {
	cin >> n >> k;

	visited[n] = true;
	bfs(n);

	return 0;
}