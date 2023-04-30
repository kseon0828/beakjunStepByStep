#include <bits/stdc++.h>
using namespace std;

int main() {
	int num;
	set<int> s;

	for (int i = 0; i < 10; i++) {
		cin >> num;
		s.insert(num% 42);
	}

	cout << s.size();


	return 0;
}