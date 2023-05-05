#include <bits/stdc++.h>
using namespace std;

int n, breakCnt, num;
int now = 100;
bool availdNum[10] = { false };

int check(int n) {
	//n�� 0�϶�, �ƴҶ��� ������ ������
	//���ڸ� ���� 10���� ������ 0�� �Ǿ����� while���� ������ ������,
	//while(n>=0)���� �ϸ�, 0�� �־� while���� ������ ����
	if(n == 0) {
		if (availdNum[0]) return 0;
		else return 1;
	}

	int len = 0; //�ش� ��ȣ���� ��� ������ �ϴ���(�ڸ���)
	while (n > 0) {
		if (availdNum[n % 10])return 0;
		n /= 10;
		len++;
	}
	return len;
}

int main(void) {
	cin >> n;
	cin >> breakCnt;

	for (int i = 0; i < breakCnt; i++) {
		cin >> num;
		availdNum[num] = true;
	}

	//���1 - 100���� +,-�ϴ� ���
	int result = abs(100 - n);
	
	//���2 - ���峪�� ���� ���� �����ؼ� +,-�ϴ� ���
	//1,000,000���� �ϴ� ������ ������ 500,000���� ū ������ --�� ���� �־
	for (int i = 0; i < 1000000; i++) {
		//i�� ������ ��ȣ�� check�� ���� ���� �� �ִ��� Ȯ��
		int len = check(i);

		//len�� 0���� ũ�ٴ� ���� ���� �� �ִ� ��ȣ��� �ǹ̷�
		//i���� �̵��Ϸ��� ��ȣ�� �󸶳� ���̳����� Ȯ���ϰ�
		//�ּҰ� ����
		if (len > 0) {
			int cnt = abs(i - n);
			
			if (result > cnt + len) result = cnt + len;
		}
	}

	cout << result;

	return 0;

}