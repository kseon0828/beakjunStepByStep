#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n, result=0;
	cin >> n;

	while (n >= 0) {
		if (n % 5 == 0) {
			result += (n / 5);
			cout << result;
			return 0;
		}

		//n이 5에서 나눠 떨어지지 않으면
		//n에서 3을 뺀 값을 가지고 다시 5로 나눔
		//위의 과정을 5로 나눠떨어질때 까지, 진행하는데
		//n이 0보다 작아지면 -1 출력
		n -= 3;
		result++;
	}

	cout << -1;

	return 0;
}