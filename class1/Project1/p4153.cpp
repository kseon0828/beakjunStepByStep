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

		//������ �Է� �� �߿� ��� ���� �ִ����� Ȯ���Ͽ� ������ ����
		maxCm = max(powA, max(powB, powC));

		//������ �ƴ� �غ��� ���̰� �������� ã�� ������ �� ���� ����
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