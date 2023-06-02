#include <bits/stdc++.h>
using namespace std;

int visited[100001];
int n, k;

void bfs(int n) {
	queue<pair<int, int>> q;
	q.push({n,0});

	while (!q.empty()) {
		int x = q.front().first; //Ž���ϴ� ��ġ
		int cnt = q.front().second; //���� �ɸ��� �ð�
		q.pop();

		//������ �ִ� ���� �湮�ϸ� ���
		if (x == k) {
			cout << cnt;
			break;
		}

		//x�� 1�� ���ϴ� ��찡 ������ �ִٸ�
		//ť�� ��ġ�� �ð� �־��ְ�, �湮�ߴٰ� �湮
		if (x + 1 >= 0 && x + 1 < 100001) {
			if (!visited[x + 1]) {
				visited[x + 1] = true;
				q.push({ x + 1, cnt + 1 });
			}
		}

		//x�� 1�� ���� ��찡 ������ �ִٸ�
		//ť�� ��ġ�� �ð� �־��ְ�, �湮�ߴٰ� �湮
		if (x - 1 >= 0 && x - 1 < 100001) {
			if (!visited[x - 1]) {
				visited[x - 1] = true;
				q.push({ x - 1, cnt + 1 });
			}
		}

		//x�� 2�� ���ϴ� ��찡 ������ �ִٸ�
		//ť�� ��ġ�� �ð� �־��ְ�, �湮�ߴٰ� �湮
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