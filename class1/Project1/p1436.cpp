#include <iostream>
using namespace std;

int main(void) {
	int n, result, temp;
	int cnt = 0; //���� ���° ��������

	cin >> n;

	//���� ������ n�� �ƴҶ� ���� ����
	while (cnt != n) {
		result++;
		temp = result;

		//temp�� ���� ���� ���� n��° ���� ������ �Ǵ�
		//temp�� ���ڸ����� �ȵǸ� ���� while�� Ż��
		while (temp != 0) {
			//���� ����� cnt�� ������Ű�� ���� while�� Ż��
			if (temp % 1000 == 666) {
				cnt++;
				break;
			}
			//�ڿ� ���ڸ��� ���� ���� �ƴ϶��, �ڿ� ���� ��
			else temp /= 10;
		}
	}


	return 0;
}