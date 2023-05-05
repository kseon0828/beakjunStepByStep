#include <bits/stdc++.h>
using namespace std;

bool compare(string a, string b) {
	if (a.length() < b.length())
		return true;
	else if (a.length() == b.length())
		if (a < b) return true;

	return false;
}

int main(void) {
	int n;
	set<string> s;
	vector<string> v;
	string inputStr;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> inputStr;
		s.insert(inputStr);
	}

	for (auto i : s) v.push_back(i);
	
	sort(v.begin(), v.end(), compare);

	for (auto i : v) cout << i << '\n';

	return 0;
}