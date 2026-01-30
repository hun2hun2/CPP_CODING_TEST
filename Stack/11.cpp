#include <string>
#include <iostream>
#include <stack>

using namespace std;

int solution(string s) {
    stack<char> st;

    for (char c : s) {
        if (st.empty()) st.push(c);
        else {
            if (st.top() == c) {
                st.pop();
            } else {
                st.push(c);
            }
        }
    }

    return st.empty();
}

int main()
{
    cout << solution("baabaa") << endl; // 1
    cout << solution("cdcd") << endl;   // 0 
    return 0;
}
