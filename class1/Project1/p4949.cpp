#include <bits/stdc++.h>
using namespace std;

int main(void) {
    //프로그램이 종료되기 전까지의 판별
    while (true) {
        bool noSantence = false; //true이면, no 출력        
        string str;
        stack<char> st;

        getline(cin, str);

        //입력이 .이라면 프로그램 종료
        if (str == ".") break;

        for (auto c : str) {
            if (c == '[' || c == '(') st.push(c);
            else if (c == ']') {
                if (!st.empty() && st.top() == '[') st.pop();
                else {
                    noSantence = true;
                    break;
                }
            }
            else if (c == ')') {
                if (!st.empty() && st.top() == '(') st.pop();
                else {
                    noSantence = true;
                    break;
                }
            }
        }

        if (!noSantence && st.empty())
            cout << "yes\n";
        else
            cout << "no\n";
    }


    return 0;
}