#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n;
	//앞, 뒤로 push, pop할 수 있는 deque를 사용
	deque<int> dq;

	cin >> n;

	//1부터 입력 받은 수 n까지 dq에 삽입
	for (int i = 1; i < n + 1; i++) dq.push_back(i);

	//맨 위의 카드를 버리는 과정은 n-1번 발생
	int m = n - 1;
	while (m--) {
		//맨 위의 카드를 버림
		dq.pop_front();
		//버려진 후 맨 위의 카드의 수를 확인하고
		int topNum = dq.front();
		//맨 뒤에 삽입
		dq.push_back(topNum);
		//삽입한 후 맨 위의 카드를 버림
		dq.pop_front();
	}

	//맨위의 카드가 n-1번 버려지면 한장만 남게 됨
	//한장 남은 카드를 확인
	cout << dq.front();

	return 0;
}