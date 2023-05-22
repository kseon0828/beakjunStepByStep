#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, string> x, pair<int, string> y) {
	//첫번째 원소를 기준으로 오름차순 정렬
	return x.first < y.first;
}

int main(void) {
	vector<pair<int, string>> v;

	int n, age;
	string name;

	cin >> n;

	while (n--) {
		cin >> age >> name;
		//입력 받은 나이와 이름을 pair로 vector에 push함
		v.push_back({ age, name });
	}

	//stabel_sort는 입력 순서를 보장하여 정렬함
	stable_sort(v.begin(), v.end(), compare);

	for (auto i : v) {
		cout << i.first << ' ' << i.second << '\n';
	}
}