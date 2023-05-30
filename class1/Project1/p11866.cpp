#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	vector<int> v;

	cin >> n >> k;

	//1~n이 담긴 v를 생성
	for (int i = 0; i < n; i++) {
		v.push_back(i + 1);
	}

	//제거를 시작할 idx
	int idx = k - 1;

	string str = "<";

	vector<int> temp; //한번에 pop할거 모아둠
	vector<int> result; //순서대로 출력(제거)할 수들
	
	while (!v.empty()) {
		while (idx < v.size()) {
			temp.push_back(idx);
			result.push_back(v[idx]);
			idx += k;
		}

		idx -= v.size();

		for (int i = 0; i < temp.size(); i++) {
			//i를 빼는 이유는 v에서 하나씩 제거되면 v에 변화가 생겨
			//의도하는 idx를 제거할 수 없어서
			//기존에 idx에서 제거된 수만큼 빼야 의도한 idx가 제거됨
			v.erase(v.begin() + (temp[i]-i));
		}
		temp.clear();
	}

	//출력
	cout << "<";
	for (int i = 0; i < n - 1; i++)
		cout << result[i] << ", ";

	cout << result[n - 1] << ">";


	return 0;
}