#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool solution(string s) {
    // bool answer = true;
    // int checker = 0;

    // for (int i = 0; i < s.length(); i++) {
    //     if (s[i] == '(') checker++;
    //     else if (s[i] == ')') checker--;

    //     if (checker < 0) {
    //         answer = false;
    //         return answer;
    //     }
    // }

    // if (checker == 0) return answer;
    // else {
    //     answer = false;
    //     return answer;
    // }
    stack<char> st;

    for (char c : s) {
        if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            if (st.empty()) return false;
            st.pop();
        }
    }

    return st.empty();
}

int main()
{
    //(true를 출력하면 1 이고, false를 출력하면 0입니다.
    
    cout << solution("(())()") << endl;  // 1
    cout << solution("((())()") << endl; // 0 
    cout << solution(")()") << endl;

    return 0;
}
