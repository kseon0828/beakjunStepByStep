#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n, inputNum, sum=0;
	priority_queue<int> pq;
	vector<int> q;
	int cnt[8001] = { 0 };
	int maxCnt = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> inputNum;
		sum += inputNum;
		pq.push(inputNum);
		q.push_back(inputNum);

		cnt[inputNum + 4000]++;
	}

	int flag;
	for (int i = 0; i < 8001; i++)
	{
		if (cnt[i] > maxCnt) {
			maxCnt = cnt[i];
			flag = i;
		}
	}

	//두번째로 작은 값이 있는지 flag로 판별
	for (int i = flag+1; i < 8001; i++) {
		if (cnt[i] == maxCnt) {
			flag = i;
			break;
		}
	}

	int min = *min_element(q.begin(), q.end());
	int max = *max_element(q.begin(), q.end());

	int a = round(double(sum) / n);
	if (a == -0) a=abs(a);

	cout << a<<'\n';
	
	for (int i = 0; i < n / 2; i++) pq.pop();
	cout << pq.top()<<'\n';
	cout<< flag-4000 <<'\n';
	cout << max - min;

	return 0;
}