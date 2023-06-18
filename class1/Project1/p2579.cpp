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
	//계단이 3개 일때 1+2 or 2+3에서 최대를 고르면 됨
	//stair[3]이 무조건 필요한 이유는 마지막 계단은 무조건 밟아야 하기 때문
	DP[3] = max(stair[1] + stair[3], stair[2] + stair[3]);
	
	for (int i = 4; i <= n; i++) {
	// 마지막 계단은 무조건 밟아야 함
	// 그 전 계단을 밟을지, 안 밟을지만 고려하면 됨
		DP[i] = max(DP[i - 2] + stair[i], DP[i - 3] + stair[i - 1] + stair[i]);
	}

	cout << DP[n];

	return 0;
}