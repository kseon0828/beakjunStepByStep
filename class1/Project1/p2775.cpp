#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int t;
    int k, n;

    cin >> t;

    while (t--) {
        int map[15][15] = { 0 };

        cin >> k >> n;

        //0�� - 1, 2, 3, 4, 5...
        //1�� - 1, 3, 6, 10, 15...
        //2�� - 1, 4, 10, 20, 35...

        for (int i = 1; i <= 14; i++) map[0][i] = i;

        //k, n�� ������ �����ϱ� ���Ʈ����...?
        //i�� ��, k�� ȣ
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= n; j++) {
                for (int p = 1; p <= j; p++) {
                    map[i][j] += map[i - 1][p];
                }
            }
        }

        cout << map[k][n] << '\n';
    }

    return 0;
}