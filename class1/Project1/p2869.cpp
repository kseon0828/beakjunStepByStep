#include <bits/stdc++.h>
using namespace std;

int main(void) {
	long long int a, b, v, day;

	cin >> a >> b >> v;

	//day >= (v-b)/(a-b)
	//day�� ���� �������� �״�� day�� ���ϸ�ǰ�
	if ((v - b) % (a - b) == 0) day = (v - b) / (a - b);
	//day�� ���� �������� �״�� day�� ���ϸ�ǰ�
	else day = (v - b) / (a - b) + 1;

	cout << day;

	return 0;
}