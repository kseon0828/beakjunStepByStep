#include <bits/stdc++.h>
using namespace std;

int stair[301];
int DP[301];
int total = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, inpuptNum;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> stair[i];
	}

	DP[1] = stair[1];
	DP[2] = stair[1] + stair[2];
	//����� 3�� �϶� 1+2 or 2+3���� �ִ븦 ���� ��
	//stair[3]�� ������ �ʿ��� ������ ������ ����� ������ ��ƾ� �ϱ� ����
	DP[3] = max(stair[1] + stair[3], stair[2] + stair[3]);
	
	for (int i = 4; i <= n; i++) {
	// ������ ����� ������ ��ƾ� ��
	// �� �� ����� ������, �� �������� ����ϸ� ��
		DP[i] = max(DP[i - 2] + stair[i], DP[i - 3] + stair[i - 1] + stair[i]);
	}

	cout << DP[n];

	return 0;
}