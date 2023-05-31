#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	long long sum = 0, r=1;
	string str;

	int m = 1234567891;

	cin >> n;
	cin >> str;


	/*
	* ai*r^i mod M = {(ai mod M)*(r^i mod M)} mod M
	*/
	for (int i = 0; i < n; i++) {
		sum = (sum + (str[i] - 'a'+1) *r)%m;

		//r�� 31^i�� ���� �κ� (pow(31, i)��� ���)
		r = (r * 31) % m;
	}

	cout << sum;

	return 0;
}


//50�� Ǯ��
/*
int main() {
	int n;
	long long sum = 0;
	string str;

	cin >> n;
	cin >> str;

	for (int i = 0; i < n; i++) {
		sum += (str[i] - 'a'+1) * pow(31, i);
	}

	cout << sum;

	return 0;
}
*/