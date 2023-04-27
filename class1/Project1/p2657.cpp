#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int strNum, reNum;
	string str;

	cin >> strNum;

	for (int i = 0; i < strNum; i++) {
		cin >> reNum >> str;

		for (int k = 0; k < str.length(); k++) {
			for (int j = 0; j < reNum; j++) {
				cout << str[k];
			}
		}
		cout << "\n";

	}

	return 0;
}