#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100];
int visited[100]; //i���� � j��� ������ �Ǿ��ִ��� check

//��������� i�� j�� ������ �Ǿ� �ִ��� Ȯ��
void dfs(int x) {
	//graph[x]�� ����� j���� Ž���ϱ�
	for (int i = 0; i < graph[x].size(); i++) {
		//graph[x]�� ��� j�� �湮���� �ʾ�����
		//�湮 ���� �ٲٰ�, dfs�� �� j���� ����� ���� Ž�� ����
		if (!visited[graph[x][i]]) {
			visited[graph[x][i]] = 1;
			dfs(graph[x][i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, inputNum;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> inputNum;
			if (inputNum) {
				graph[i].push_back(j);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		memset(visited, 0, sizeof(visited));
		dfs(i);
		for (int j = 0; j < n; j++) {
			cout << visited[j] << " ";
		}
		cout << "\n";
	}

	return 0;
}