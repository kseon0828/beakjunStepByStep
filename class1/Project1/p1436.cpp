#include <iostream>
using namespace std;

int main(void) {
	int n, temp;
	int result = 0; //영화제목을 ++하면서 n번째 종말 수 구함
	int cnt = 0; //현재 몇번째 순서인지

	cin >> n;

	//현재 순서가 n이 아닐때 까지 진행
	while (cnt != n) {
		result++;
		temp = result;

		//temp를 통해 현재 수가 n번째 종말 수인지 판단
		//temp가 세자리수가 안되면 안쪽 while문 탈출
		while (temp != 0) {
			//종말 수라면 cnt를 증가시키고 안쪽 while문 탈출
			if (temp % 1000 == 666) {
				cnt++;
				break;
			}
			//뒤에 세자리가 종말 수가 아니라면, 뒤에 수를 뺌
			else temp /= 10;
		}
	}

	cout << result;
	return 0;
}