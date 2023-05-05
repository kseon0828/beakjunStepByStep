#include <bits/stdc++.h>
using namespace std;

int n, breakCnt, num;
int now = 100;
bool availdNum[10] = { false };

int check(int n) {
	//n이 0일때, 아닐때를 나누는 이유는
	//한자리 수를 10으로 나누어 0이 되었을때 while문이 끝나야 하지만,
	//while(n>=0)으로 하면, 0이 있어 while문이 끝나지 않음
	if(n == 0) {
		if (availdNum[0]) return 0;
		else return 1;
	}

	int len = 0; //해당 번호까지 몇번 눌러야 하는지(자리수)
	while (n > 0) {
		if (availdNum[n % 10])return 0;
		n /= 10;
		len++;
	}
	return len;
}

int main(void) {
	cin >> n;
	cin >> breakCnt;

	for (int i = 0; i < breakCnt; i++) {
		cin >> num;
		availdNum[num] = true;
	}

	//경우1 - 100에서 +,-하는 경우
	int result = abs(100 - n);
	
	//경우2 - 고장나지 않은 수를 조합해서 +,-하는 경우
	//1,000,000까지 하는 이유는 리모컨 500,000보다 큰 수에서 --할 수가 있어서
	for (int i = 0; i < 1000000; i++) {
		//i는 리모컨 번호로 check를 통해 누를 수 있는지 확인
		int len = check(i);

		//len이 0보다 크다는 것은 누를 수 있는 번호라는 의미로
		//i에서 이동하려는 번호가 얼마나 차이나는지 확인하고
		//최소값 갱신
		if (len > 0) {
			int cnt = abs(i - n);
			
			if (result > cnt + len) result = cnt + len;
		}
	}

	cout << result;

	return 0;

}