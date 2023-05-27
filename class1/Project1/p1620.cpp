#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	string name, quest;
	//숫자로 이름을 or 이름으로 숫자를 확인해야 하므로
	//두 상황 모두 검색이 가능한 map을 두개 생성
	map<int, string> keyInt;
	map<string, int> keyString;

	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> name;
		keyInt.insert({ i, name });
		keyString.insert({ name, i });
	}

	for (int i = 0; i < m; i++) {
		//입력이 문자열일수도 , 숫자일수도 있기 때문에
		//문자 배열로 입력 받고
		//[0]을 기준으로 문자열 or 숫자 검사
		char quest[21];
		cin >> quest;

		if (quest[0] < 'A') {
			int num = atoi(quest);
			cout << keyInt[num] << '\n';
		}
		else {
			cout << keyString[quest] << '\n';
		}
	}

	return 0;
}