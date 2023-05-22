#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n, m, getNum, findNum;
	vector<int> v;

	cin >> n;

	while (n--) {
		cin >> getNum;
		//입력받은 수들을 vector에 삽입
		v.push_back(getNum);
	}

	//vector를 정렬함
	sort(v.begin(), v.end());

	cin >> m;
	while (m--) {
		cin >> findNum;
		//정렬한 값을 가지고
		//그 값에 최소 인덱스와 최대 인덱스의 차이를 구하면, 그 값의 개수를 구할 수 있음
		cout << upper_bound(v.begin(), v.end(), findNum) - lower_bound(v.begin(), v.end(), findNum) << ' ';
	}

	return 0;
}