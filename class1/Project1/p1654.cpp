#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n, k, line, cm=0, maxi=0;
	long long low, high, mid; //이분 탐색에 필요한 변수들
	int lines[10001];

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> lines[i];

		//제일 긴 선을 기준으로 이분 탐색 진행할 예정
		if (maxi < lines[i]) maxi = lines[i];
	}

	low = 1;
	high = maxi;

	//low가 high를 역전할때 까지 진행
	while (low <= high) {
		mid = (low + high) / 2;

		int cnt = 0; //k개를 넘기면 조건에 충족
		for (int i = 0; i < n; i++) cnt += lines[i] / mid;

		//선의 수가 k보다 크면, 상위 부분을 탐색
		if (cnt >= k) {
			low = mid + 1;
			if (cm < mid) cm = mid;
		}
		//그렇지 않으면, 하위 부분을 탐색하여 cm를 줄여감
		else {
			high = mid - 1;
		}
	}

	cout << cm;


	return 0;
}