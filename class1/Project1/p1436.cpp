#include <iostream>
using namespace std;

int main(void) {
	int n, temp;
	int result = 0; //��ȭ������ ++�ϸ鼭 n��° ���� �� ����
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

	cout << result;
	return 0;
}