#include <bits/stdc++.h>
using namespace std;

int tt, m, n, k; //�Է� ��
int sum; //�� ���� ��

//Ž�� ���� ����, �����¿�
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
				//����߰� �ִٸ�, 0���� �����ϰ�
				//queue�� �߰�
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
	int x, y; //����� ��ġ �Է�

	cin >> tt;

	for (int t = 0; t < tt; t++) {
		cin >> m >> n >> k;
		sum = 0;

		//2���� ���� �迭 �Ҵ�
		int** array = new int* [n];
		for (int j = 0; j < n; j++) array[j] = new int[m] {0};

		//������� ��ġ 1 �Ҵ�
		for (int j = 0; j < k; j++) {
			cin >> y >> x;
			array[x][y] = 1;
		}

		for (int a = 0; a < n; a++) {
			for (int b = 0; b < m; b++) {
				//�׷����� ���������� Ž���ϴ� �� ������� ��ġ�� 1�̶��
				//BFS �����Ͽ� ����� ����� ���� Ȯ��
				if (array[a][b] == 1) {
					bfs(a, b, array);
				}
			}
		}
		cout << sum << "\n";
	}
	return 0;
}