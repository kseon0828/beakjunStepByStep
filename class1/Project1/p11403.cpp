#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100];
int visited[100]; //i에서 어떤 j들과 연결이 되어있는지 check

//재귀적으로 i와 j가 연결이 되어 있는지 확인
void dfs(int x) {
	//graph[x]에 연결된 j들을 탐색하기
	for (int i = 0; i < graph[x].size(); i++) {
		//graph[x]의 노드 j가 방문하지 않았으면
		//방문 상태 바꾸고, dfs로 그 j노드와 연결된 노드들 탐색 진행
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