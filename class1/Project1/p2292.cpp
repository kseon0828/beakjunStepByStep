#include <bits/stdc++.h>
using namespace std;


int main(void) {
	int n;
	cin >> n;

	int result=0;

	//�� ������ �����ϴ� ���� 6*�����̴�
	//1���� - 6��, 2���� - 12��, 3���� - 18�� ...
	//��� ������ ������ ������ Ǯ �� �ִ�.
	//���� �Է¹��� �� n���� ������ ������ ���Ѵ�.
	for (int i = 2; i <= n; result++) {
		i += 6 * result;
	}

	//�Է��� 1�϶� ����� 1
	if (n == 1) result = 1;
	cout << result;
	
	return 0;
}