#include <bits/stdc++.h>
using namespace std;

int arr[500][500];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//b�� �κ��丮��, �κ��丮�� �ִ� ����� ����ؼ� ������ ��
	int n, m, b, inputNum;
	int minSec = INT_MAX, resultHeight;

	cin >> n >> m >> b;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	//���̰� 0���� 256������ �������� ��� ��츦 �����
	for (int h = 0; h <= 256; h++) {
		int build = 0; //�׾ƾ� �ϴ� ��� ���� �̶�, �κ��丮�� �ִ� ���� �ʰ��ϸ� X
		int remove = 0; //�����ؾ� �ϴ� ��� ����

		//arr�� Ž���ϸ鼭 ������ 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int diff = arr[i][j] - h; //���� ������ ���� h�� arr[i][j]�� ���� ����
				//���̰� 0���� ũ�� �׸�ŭ ����� ���� ��
				if (diff > 0) remove += diff;
				//���̰� 0���� ������ �׸�ŭ ����� �׾ƾ� ��
				else if (diff < 0) build -= diff;
			}
		}

		//�κ��丮(���� + ����� �����ؼ� �߰�)�� �����ϴ� ������ 
		//���Ӱ� �׾ƾ� �ϴ� ��� �������� Ŀ�� ��
		//��ũ�� ���� ���ϰ� ���� ���̷�
		if (remove + b >= build) {
			//���� ������ ����(h)�� ������ �� �ɸ��� �ð� ���
			int time = 2 * remove + build;
			//�ּ� �ð����� ���� �ð��� �۰ų� ������ ����
			if (minSec >= time) {
				minSec = time;
				resultHeight = h;
			}
		}
	}

	cout << minSec << ' ' << resultHeight;

	return 0;
}