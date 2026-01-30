#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    stack<int> deleted;

    vector<int> up;
    vector<int> down;

    for (int i = 0; i < n + 2; i++) {
        up.push_back(i - 1);
        down.push_back(i + 1);
    }

    k++;

    for (int i = 0; i < cmd.size(); i++) {
        if (cmd[i][0] == 'C') {
            deleted.push(k);
            up[down[k]] = up[k];
            down[up[k]] = down[k];

            if (down[k] == n + 1) k = up[k];
            else k = down[k];
        } else if (cmd[i][0] == 'Z') {
            int restore = deleted.top();
            deleted.pop();
            up[down[restore]] = restore;
            down[up[restore]] = restore;
        } else {
            int size = stoi(cmd[i].substr(2));

            if (cmd[i][0] == 'U') {
                for (int j = 0; j < size; j++) {
                    k = up[k];
                }
            } else {
                for (int j = 0; j < size; j++) {
                    k = down[k];
                }
            }
        }
    }

    string answer(n, 'O');
    while (!deleted.empty()) {
        answer[deleted.top() - 1] = 'X';
        deleted.pop();
    }

    return answer;

    // stack<int> st;
    // int index = k;
    // int len = cmd.size();
    // string result(n, 'O');

    // for (int i = 0; i < len; i++) {
    //     if (cmd[i][0] == 'U') {
    //         int changer = 0;
    //         int multi = 1;
    //         for (int j = cmd[i].length() - 1; j >= 2; j--) {
    //             changer += multi * (cmd[i][j] - 48);
    //             multi *= 10;
    //         }
    //         while (changer > 0) {
    //             index--;
    //             if (result[index] == 'X') changer++;
    //             changer--;
    //         }
    //     } else if (cmd[i][0] == 'D') {
    //         int changer = 0;
    //         int multi = 1;
    //         for (int j = cmd[i].length() - 1; j >= 2; j--) {
    //             changer += multi * (cmd[i][j] - 48);
    //             multi *= 10;
    //         }
    //         while (changer > 0) {
    //             index++;
    //             if (result[index] == 'X') changer++;
    //             changer--;
    //         }
    //     } else if (cmd[i][0] == 'C') {
    //         result[index] = 'X';
    //         st.push(index);
    //         int new_index = index;
    //         if (index == (n - 1)) {
    //             int changer = 1;
    //             while (changer > 0) {
    //                 new_index--;
    //                 if (result[new_index] == 'X') changer++;
    //                 changer--;
    //             }
    //         } else {
    //             int changer = 1;
    //             while (changer > 0) {
    //                 new_index++;
    //                 if (result[new_index] == 'X') changer++;
    //                 changer--;
    //             }
    //         }
    //         index = new_index;
    //     } else if (cmd[i][0] == 'Z') {
    //         result[st.top()] = 'O';
    //         st.pop();
    //     }
    // }

    // return result;
}

int main()
{
    
    cout << solution(8, 2, {"D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z"}) << endl;              //OOOOXOOO
    cout << solution(8, 2, {"D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z", "U 1", "C"}) << endl;  //OOXOXOOO
    return 0;
}
