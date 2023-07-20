#include <bits/stdc++.h>
using namespace std;

int _map[1000][1000];
int dist[1000][1000];
bool visited[1000][1000];

int dx[4] = { 0,0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int n, m;

void search(int inputX, int inputY) {
    queue <pair<pair<int, int>, int>> q;
    q.push({ {inputX, inputY}, 0 });
    visited[inputX][inputY] = true;
    dist[inputX][inputY] = 0;

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dis = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (visited[nx][ny])
                continue;
            if (_map[nx][ny] == 0) {
                dist[nx][ny] = 0;
                visited[nx][ny] = true;
                continue;
            }

            visited[nx][ny] = true;
            dist[nx][ny] = dis + 1;
            q.push({ {nx, ny}, dis + 1 });
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int sx, sy;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> _map[i][j];
            if (_map[i][j] == 2) {
                sx = i;
                sy = j;
            }
        }
    }

    search(sx, sy);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //갈 수 있는 땅(1)이지만 도달할 수 없는 위치
            if (dist[i][j] == 0 && _map[i][j] == 1)
                cout << -1 << ' ';
            else
                cout << dist[i][j] << ' ';
        }
        cout << "\n";
    }

    return 0;
}