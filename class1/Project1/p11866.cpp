#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	vector<int> v;

	cin >> n >> k;

	//1~n�� ��� v�� ����
	for (int i = 0; i < n; i++) {
		v.push_back(i + 1);
	}

	//���Ÿ� ������ idx
	int idx = k - 1;

	string str = "<";

	vector<int> temp; //�ѹ��� pop�Ұ� ��Ƶ�
	vector<int> result; //������� ���(����)�� ����
	
	while (!v.empty()) {
		while (idx < v.size()) {
			temp.push_back(idx);
			result.push_back(v[idx]);
			idx += k;
		}

		idx -= v.size();

		for (int i = 0; i < temp.size(); i++) {
			//i�� ���� ������ v���� �ϳ��� ���ŵǸ� v�� ��ȭ�� ����
			//�ǵ��ϴ� idx�� ������ �� ���
			//������ idx���� ���ŵ� ����ŭ ���� �ǵ��� idx�� ���ŵ�
			v.erase(v.begin() + (temp[i]-i));
		}
		temp.clear();
	}

	//���
	cout << "<";
	for (int i = 0; i < n - 1; i++)
		cout << result[i] << ", ";

	cout << result[n - 1] << ">";


	return 0;
}