#include <bits/stdc++.h>
using namespace std;

bool visited[10000];
int testCase, A, B;

//가장 빠르게 목표값을 찾아야하므로
void BFS(int a) {
    queue <pair<int, string>> q;
    q.push({ a, "" });
    visited[a] = true;

    while (!q.empty()) {
        int x = q.front().first;
        string s = q.front().second;
        q.pop();

        //찾는 것이 B와 같아질 때 탐색 종료
        if (x == B) cout << s << "\n";

        //D를 진행할 때
        int nx = (x * 2) % 10000;
        if (!visited[nx]) {
            visited[nx] = true;
            q.push({ nx, s + "D" });
        }

        //S를 진행할 때
        nx = x - 1;
        if (nx < 0) nx = 9999;
        if (!visited[nx]) {
            visited[nx] = true;
            q.push({ nx, s + "S" });
        }

        //L을 진행할 때
        //(x%1000)*10 연산은 천의 자리수를 제외한 백,십,일을 한칸씩 왼쪽으로 shift
        //x/1000은 천의 자리수를 일의 자리수로 변경
        nx = (x % 1000) * 10 + (x / 1000);
        if (!visited[nx]) {
            visited[nx] = true;
            q.push({ nx, s + "L" });
        }

        //R을 진행할 때
        //(x%10)*1000 연산은 일의 자리수를 천의 자리수로 변경
        //x/10은 천,백,십의 자리수를 한칸씩 오른쪽으로 shift
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