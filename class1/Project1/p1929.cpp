#include <bits/stdc++.h>
using namespace std;

int main(void) {

    int M, N;

    cin >> M >> N;

    bool arr[1000001] = { false };

    for (int i = 2; i <= N; i++) {
        if (arr[i] == true)
            continue;
        for (int j = 2 * i; j <= N; j += i) {
            if (arr[j] == false) {
                arr[j] = true;
            }
        }
    }

    for (int i = M; i <= N; i++) {
        if (!arr[i] && i != 1)
            cout << i << '\n';
    }

	return 0;
}