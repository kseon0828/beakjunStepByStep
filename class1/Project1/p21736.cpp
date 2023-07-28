#include <bits/stdc++.h>
using namespace std;

char _map[600][600];
bool visited[600][600];

int people = 0;
int doX, doY; //도연이의 위치
int n, m;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void bfs(int inputX, int inputY) {
	queue<pair<int, int>> q;
	q.push({ inputX, inputY });
	visited[inputX][inputY] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
				
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			if (visited[nx][ny])
				continue;

			if (_map[nx][ny] == 'X')
				continue;

			if (_map[nx][ny] == 'P') {
				people++;
			}

			visited[nx][ny] = true;
			q.push({ nx, ny });
		}
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> _map[i][j];
			if (_map[i][j] == 'I') {
				doX = i;
				doY = j;
			}
		}
	}

	bfs(doX, doY);

	if (people == 0) {
		cout << "TT";
	}
	else {
		cout << people;
	}



	return 0;
}