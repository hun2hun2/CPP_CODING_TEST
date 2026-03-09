#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board) {
    int col = board[0].size();
    int row = board.size();

    for (int i = 1; i < row; ++i) {
        for (int j = 1; j < col; ++j) {
            if (board[i][j] == 1) {
                board[i][j] = min({board[i-1][j], board[i][j-1], board[i-1][j-1]}) + 1;
            }
        }
    }

    int max_val = 0;
    for (const auto &r : board) {
        max_val = max(max_val, *max_element(r.begin(), r.end()));
    }
    return max_val * max_val;
}

#include <iostream>

using namespace std;

int main()
{
  cout << solution({{0, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {0, 0, 1, 0}}) << endl; //출력값 : 9
  cout << solution({{0, 0, 1, 1}, {1, 1, 1, 1}}) << endl; //출력값 : 4  
  return 0;
}
