#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> v;

	int n, inputNum, sum=0;
	
	cin >> n;

	while (n--) {
		cin >> inputNum;

		//0이면 맨 끝값 pop
		if (inputNum == 0) {
			v.pop_back();
		}

		//0이 아니면 값 push
		else {
			v.push_back(inputNum);
		}
	}

	//accumulate를 사용해 v의 총합 구함
	cout << accumulate(v.begin(), v.end(), 0);

	return 0;
}