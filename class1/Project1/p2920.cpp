#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int arr[8];

	//for���� ���鼭 ���ǿ� �����Ǹ� �ϳ��� plus
	int asc = 0;
	int dsc = 0;

	for (int i = 0; i < 8; i++) {
		cin >> arr[i];

		if (arr[i] == i + 1)
			asc ++;
		else if (arr[i] == 8 - i)
			dsc++;
	}

	if (asc == 8) cout << "ascending";
	else if (dsc == 8) cout << "descending";
	else cout << "mixed";

	return 0;
}
