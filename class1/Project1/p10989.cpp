#include <bits/stdc++.h>
using namespace std;

/*  input�Ǵ� ���� ���� ������ 1~10,000,000���� ũ����
	input�Ǵ� ���� ������ 10,000���� �����Ƿ�
	input�Ǵ� ���� �Է� �޴� ���� �켱 ���� ť�� �����ϸ� �޸� �ʰ� �߻�
	���� �Է� �޴� ���� ������ �迭�� ���� ������ �����ϴ� ������� Ǯ�� ����*/
int arr[10001];

int main() {
	int n, inputNum;
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	

	while (n--) {
		//�迭�� �ε����� �Է� �޴� ���� �Ǿ� 1�� ����
		cin >> inputNum;
		arr[inputNum]++;
	}

	//arr�̸� ó������ ���鼭 0�� �ƴ� ���� �� �� ��ŭ �ε����� �ݺ��ؼ� ���
	int cnt;
	for (int i = 1; i < 10001; i++) {
		cnt = arr[i];
		for (int j = 0; j < cnt; j++) cout << i << '\n';
	}
}