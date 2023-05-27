#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, temp, sum=0;

	cin >> n;

	//1~n까지 반복문을 돌면서 
	//i에 5인수가 몇개 인지 count
	for (int i = 1; i <= n; i++) {
		temp = i;
		while (temp % 5 == 0) {
			temp /= 5;
			sum++;
		}
	}

	//다른 사람의 풀이
	/*for (int i = 5; i <= n; i *= 5) {
		sum += (n / i);
	}*/	

	cout << sum;

	return 0;
}