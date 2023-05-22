#include <bits/stdc++.h>
using namespace std;

int main(void) {
    //���α׷��� ����Ǳ� �������� �Ǻ�
    while (true) {
        bool noSantence = false; //true�̸�, no ���        
        string str;
        stack<char> st;

        getline(cin, str);

        //�Է��� .�̶�� ���α׷� ����
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