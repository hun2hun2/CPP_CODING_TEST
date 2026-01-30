#include <string>
#include <iostream>
#include <stack>

using namespace std;

string solution(int decimal) {
    if (decimal == 0) return 0;

    // stack<char> bi;
    // while (decimal != 0) {
    //     char tr = decimal % 2 + 48;
    //     bi.push(tr);
    //     decimal /= 2;
    // }

    // string result = "";
    // while (!bi.empty()) {
    //     result.push_back(bi.top());
    //     bi.pop();
    // }
    stack<int> bi;
    while (decimal != 0) {
        bi.push(decimal % 2);
        decimal /= 2;
    }

    string result = "";
    while (!bi.empty()) {
        result += to_string(bi.top());
        bi.pop();
    }

    return result;
}

int main()
{
    cout << solution(10) << endl;       // 1010
    cout << solution(27) << endl;       // 11011 
    cout << solution(12345) << endl;    // 11000000111001 
   
    return 0;
}
