#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int a, b, c;
	long long int powA, powB, powC;
	long long int maxCm, sumCm;

	while (true) {
		cin >> a >> b >> c;

		if (a == 0 && b == 0 && c == 0) break;

		powA = pow(a, 2);
		powB = pow(b, 2);
		powC = pow(c, 2);

		//세개의 입력 값 중에 어느 것이 최대인지 확인하여 빗변을 정함
		maxCm = max(powA, max(powB, powC));

		//빗변이 아닌 밑변과 높이가 무엇인지 찾고 제곱한 두 선을 더함
		for (int i = 0; i < 3; i++) {
			if (powA == maxCm) sumCm = powB + powC;
			else if (powB == maxCm) sumCm = powA + powC;
			else sumCm = powA + powB;
		}

		if (sumCm == maxCm)
			cout << "right" << '\n';
		else
			cout << "wrong" << '\n';
	}

	return 0;
}