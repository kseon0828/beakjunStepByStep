#include <bits/stdc++.h>
using namespace std;

bool visited[10000];
int testCase, A, B;

//���� ������ ��ǥ���� ã�ƾ��ϹǷ�
void BFS(int a) {
    queue <pair<int, string>> q;
    q.push({ a, "" });
    visited[a] = true;

    while (!q.empty()) {
        int x = q.front().first;
        string s = q.front().second;
        q.pop();

        //ã�� ���� B�� ������ �� Ž�� ����
        if (x == B) cout << s << "\n";

        //D�� ������ ��
        int nx = (x * 2) % 10000;
        if (!visited[nx]) {
            visited[nx] = true;
            q.push({ nx, s + "D" });
        }

        //S�� ������ ��
        nx = x - 1;
        if (nx < 0) nx = 9999;
        if (!visited[nx]) {
            visited[nx] = true;
            q.push({ nx, s + "S" });
        }

        //L�� ������ ��
        //(x%1000)*10 ������ õ�� �ڸ����� ������ ��,��,���� ��ĭ�� �������� shift
        //x/1000�� õ�� �ڸ����� ���� �ڸ����� ����
        nx = (x % 1000) * 10 + (x / 1000);
        if (!visited[nx]) {
            visited[nx] = true;
            q.push({ nx, s + "L" });
        }

        //R�� ������ ��
        //(x%10)*1000 ������ ���� �ڸ����� õ�� �ڸ����� ����
        //x/10�� õ,��,���� �ڸ����� ��ĭ�� ���������� shift
        nx = (x % 10) * 1000 + (x / 10);
        if (!visited[nx]) {
            visited[nx] = true;
            q.push({ nx, s + "R" });
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> testCase;

    while (testCase--) {
        cin >> A >> B;

        for (int i = 0; i < 10000; i++) {
            visited[i] = false;
        }

        BFS(A);
    }

    return 0;
}