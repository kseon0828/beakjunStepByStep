#include <bits/stdc++.h>
using namespace std;

bool graph[101][101];
bool visited[101];
int n, m, p1, p2;
int chon = false;

void dfs(int people, int cnt) {
	//���� Ž�� ���� ����� �湮������ ����
	visited[people] = true;

	//�� ��° ����� �̼��� ã��
	if (people == p2) {
		cout << cnt;
		chon = true;
		return;
	}
	//��ã����, dfs Ž��
	for (int i = 1; i <= n; i++) {
		//���� Ž���ϴ� ����� ����(i)�� ����Ǿ� �ִ���
		//����� ����� �湮�Ǿ�����
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
		//����� �׷���
		graph[x][y] = true;
		graph[y][x] = true;
	}

	dfs(p1, 0);

	if (chon == false) cout << -1;


	return 0;
}