#include <bits/stdc++.h>
using namespace std;

int _map[25][25];
vector <int> houseCnts;

int n;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1, 0,0 };

void bfs(int inputX, int inputY) {
	int cnt = 0;

	queue < pair<int, int>> q;
	q.push({ inputX, inputY });
	_map[inputX][inputY] = 0;

	while (!q.empty()) {
		cnt++;
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 > nx || nx >= n || 0 > ny || ny >= n)
				continue;

			if (_map[nx][ny] == 1) {
				_map[nx][ny] = 0;
				q.push({ nx, ny });
			}
		}
	}

	houseCnts.push_back(cnt);
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &_map[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (_map[i][j] == 1) {
				bfs(i, j);
			}
		}
	}

	sort(houseCnts.begin(), houseCnts.end());

	cout << houseCnts.size() << '\n';

	for (auto cnt : houseCnts) {
		cout << cnt << "\n";
	}

	return 0;
}