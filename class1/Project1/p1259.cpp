#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	vector<int> result;  //yse, no 넣을 컨테이너
	string str;
	int flag;  //no일때, while문에서 yes를 추가하는 것을 건너 뛰어야 하기 때문

	while (true) {
		flag = 0;
		cin >> str;

		if (str == "0") {
			break;
		}

		for (int i = 0; i < str.length()/2; i++) {
			if (str[i] != str[str.length() -1 - i]) {
				result.push_back(0);  //0을 입력하는 거는 No
				flag = 1;
				break;
			}
		}

		if(!flag) result.push_back(1);   //1을 입력하는 거는 Yes

	}

	for (int i = 0; i < result.size(); i++) {
		if (result.at(i) == 0) printf("no\n");
		else printf("yes\n");
	}

	return 0;
}