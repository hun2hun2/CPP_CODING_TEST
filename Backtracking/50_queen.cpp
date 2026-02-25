#include <vector>
#include <algorithm>

using namespace std;

bool isSameRow(int placedRow, int currentRow) { return placedRow == currentRow; }

bool isDiagonalAttack(int placedCol, int placedRow, int currentCol, int currentRow) {
    return abs(placedCol - currentCol) == abs(placedRow - currentRow);
}

bool isSafePosition(const vector<int> &queen, int col, int row) {
    for (int i = 0; i < col; i++) {
        if (isSameRow(queen[i], row) || isDiagonalAttack(i, queen[i], col, row)) return false;
    }
    return true;
}

long long placeQueens(vector<int> &queen, int col) {
    int n = queen.size();
    if (col == n) return 1;

    long long count = 0;
    for (int row = 0; row < n; row++) {
        if (isSafePosition(queen, col, row)) {
            queen[col] = row;
            count += placeQueens(queen, col + 1);
            queen[col] = -1;
        }
    }
    return count;
}

long long solution(int n) {
    vector<int> queen(n, -1);

    return placeQueens(queen, 0);
}

#include <iostream>

using namespace std;

int main()
{
  cout << solution(4) << endl; // 출력값 : 2
  return 0;
}
