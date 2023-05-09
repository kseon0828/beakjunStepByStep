#include <bits/stdc++.h>
using namespace std;


int main(void) {
	int n;
	cin >> n;

	int result=0;

	//각 계층에 존재하는 수는 6*계층이다
	//1계층 - 6개, 2계층 - 12개, 3계층 - 18개 ...
	//등비 수열을 합으로 문제를 풀 수 있다.
	//따라서 입력받은 수 n까지 계층이 몇인지 구한다.
	for (int i = 2; i <= n; result++) {
		i += 6 * result;
	}

	//입력이 1일때 결과는 1
	if (n == 1) result = 1;
	cout << result;
	
	return 0;
}