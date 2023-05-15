#include <bits/stdc++.h>
using namespace std;

int main(void) {
	long long int a, b, v, day;

	cin >> a >> b >> v;

	//day >= (v-b)/(a-b)
	//day가 나눠 떨어지면 그대로 day를 구하면되고
	if ((v - b) % (a - b) == 0) day = (v - b) / (a - b);
	//day가 나눠 떨어지면 그대로 day를 구하면되고
	else day = (v - b) / (a - b) + 1;

	cout << day;

	return 0;
}