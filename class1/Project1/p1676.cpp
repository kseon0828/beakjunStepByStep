#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, temp, sum=0;

	cin >> n;

	//1~n���� �ݺ����� ���鼭 
	//i�� 5�μ��� � ���� count
	for (int i = 1; i <= n; i++) {
		temp = i;
		while (temp % 5 == 0) {
			temp /= 5;
			sum++;
		}
	}

	//�ٸ� ����� Ǯ��
	/*for (int i = 5; i <= n; i *= 5) {
		sum += (n / i);
	}*/	

	cout << sum;

	return 0;
}