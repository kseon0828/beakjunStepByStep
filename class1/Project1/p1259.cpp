#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	vector<int> result;  //yse, no ���� �����̳�
	string str;
	int flag;  //no�϶�, while������ yes�� �߰��ϴ� ���� �ǳ� �پ�� �ϱ� ����

	while (true) {
		flag = 0;
		cin >> str;

		if (str == "0") {
			break;
		}

		for (int i = 0; i < str.length()/2; i++) {
			if (str[i] != str[str.length() -1 - i]) {
				result.push_back(0);  //0�� �Է��ϴ� �Ŵ� No
				flag = 1;
				break;
			}
		}

		if(!flag) result.push_back(1);   //1�� �Է��ϴ� �Ŵ� Yes

	}

	for (int i = 0; i < result.size(); i++) {
		if (result.at(i) == 0) printf("no\n");
		else printf("yes\n");
	}

	return 0;
}