#include <string>
#include <iostream>
#include <stack>

using namespace std;

int solution(string s) {
    int result = 0;
    int len = s.length();

    for (int i = 0; i < len; i++) {
        int bp = 1;
        stack<char> small;
        stack<char> middle;
        stack<char> big;

        for (int j = 0; j < len; j++) {
            char check = s[(i + j) % len];
            if (check == '(' || check == ')') {
                if (check == '(') {
                    small.push('(');
                } else {
                    if (small.empty()) {
                        bp = 0;
                        break;
                    } else {
                        small.pop();
                    }
                }
            } else if (check == '{' || check == '}') {
                if (check == '{') {
                    middle.push('{');
                } else {
                    if (middle.empty()) {
                        bp = 0;
                        break;
                    } else {
                        middle.pop();
                    }
                }
            } else if (check == '[' || check == ']') {
                if (check == '[') {
                    big.push('[');
                } else {
                    if (big.empty()) {
                        bp = 0;
                        break;
                    } else {
                        big.pop();
                    }
                }
            }
        }

        if (bp == 1 && small.empty() && middle.empty() && big.empty()) result++;
    }

    return result;
}

int main()
{
    cout << solution("[](){}") << endl; // 3
    cout << solution("}]()[{") << endl; // 2 
    cout << solution("[)(]") << endl;   // 0 
    cout << solution("}}}") << endl;    // 0   
    return 0;
}
