#include <bits/stdc++.h>
using namespace std;

int _map[101];
int cntMap[101];
bool bfsDone;

int result;

void BFS(int x) {
	queue<pair<int, int>> q;

	q.push({ x, 0 });

	while (!q.empty()) {
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();

		for (int i = 1; i <= 6; i++) {
			int nx = now + i;

			//���� �ȿ� �����ϴ��� �˻�
			if (nx < 1 || nx > 100)
				continue;
			

			//���̳� ��ٸ��� �̵��� �� ����
			if (_map[nx]) {
				nx = _map[nx];
			}
			//�̵��� ���� �ֻ��� Ƚ������ ���� Ƚ���� ������ q�� �߰�
			if (cntMap[nx] > cnt+1) {
				cntMap[nx] = cnt + 1;
				q.push({ nx, cnt + 1 });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;

	cin >> n >> m;

	int now, goTo;
	while (n--) {
		cin >> now >> goTo;
		_map[now] = goTo;
	}
	while (m--) {
		cin >> now >> goTo;
		_map[now] = goTo;
	}

	memset(cntMap, 999999, sizeof(cntMap));

	BFS(1);

	cout << cntMap[100]<<'\n';


	return 0;
}