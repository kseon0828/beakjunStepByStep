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

		//n�� 5���� ���� �������� ������
		//n���� 3�� �� ���� ������ �ٽ� 5�� ����
		//���� ������ 5�� ������������ ����, �����ϴµ�
		//n�� 0���� �۾����� -1 ���
		n -= 3;
		result++;
	}

	cout << -1;

	return 0;
}