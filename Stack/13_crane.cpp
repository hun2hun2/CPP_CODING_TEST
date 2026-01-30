#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    stack<int> basket;
    int len = board[0].size();
    vector<int> index(len, len);

    int cnt = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (board[i][j] != 0 && index[j] == len) {
                index[j] = i;
                cnt++;
            }
            if (cnt == len) break;
        }
        if (cnt == len) break;
    }

    int result = 0;
    for (int i = 0; i < moves.size(); i++) {
        if (index[moves[i] - 1] != len) {
            int realPlace = moves[i] - 1;
            int doll = board[index[realPlace]][realPlace];
            if (basket.empty()) {
                basket.push(doll);
                doll = 0;
                index[realPlace]++;
            } else {
                if (basket.top() == doll) {
                    basket.pop();
                    result += 2;
                    doll = 0;
                    index[realPlace]++;
                } else {
                    basket.push(doll);
                    doll = 0;
                    index[realPlace]++;
                }
            }
        }
    }

    return result;
} 

int main()
{
    
    cout << solution( { {0, 0, 0, 0, 0}, {0, 0, 1, 0, 3}, {0, 2, 5, 0, 1}, {4, 2, 4, 4, 2}, {3, 5, 1, 3, 1} }, {1, 5, 3, 5, 1, 2, 1, 4} ) << endl; // 4
    return 0;
}
