#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int num, first, beforeNum;

	cin >> first;
	beforeNum = first;

	if(first==8){
		for (int i = 0; i < 7; i++) {
			cin >> num;
			beforeNum--;
			if (num != beforeNum) {
				cout << "mixed";
				return 0;
			}
		}
		cout << "descending";
	}
	else if (first == 1) {
		for (int i = 0; i < 7; i++) {
			cin >> num;
			beforeNum++;
			if (num != beforeNum) {
				cout << "mixed";
				return 0;
			}
		}
		cout << "ascending";
	}

	return 0;
}