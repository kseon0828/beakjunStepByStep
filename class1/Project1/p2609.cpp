#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y) {
	if (x % y == 0) return y;
	return gcd(y, x % y);
}

int main(void) {
	int num1, num2;
	int maxDiv = 0;
	
	cin >> num1 >> num2;

	if (num1 >= num2) maxDiv = gcd(num1, num2);
	else maxDiv = gcd(num2, num1);

	cout << maxDiv << '\n' << (num1 * num2) / maxDiv;

	return 0;
}