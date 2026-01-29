#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> result;
    int row = arr1.size();
    int col = arr2[0].size();
    result.assign(row, vector<int>(col, 0));

    int num = arr1[0].size();

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            for (int r = 0; r < num; r++) {
                result[i][j] += arr1[i][r] * arr2[r][j];
            }
        }
    }

    return result;
}

void print2D(vector<vector<int>> vec)
{
    for(const auto& innerVec : vec){
        copy(innerVec.begin(), innerVec.end(), std::ostream_iterator<int>(cout, " "));
        cout << endl;
    }
    
    cout << endl;
}

int main()
{
    print2D(solution({{1, 4}, {3, 2}, {4, 1}} ,{{3, 3}, {3,3}}));
    /*
      15 15
      15 15
      15 15
    */
    print2D(solution({{2, 3, 2}, {4, 2, 4}, {3, 1,4}}, {{5, 4, 3}, {2, 4, 1}, {3, 1, 1}} ));     // 1 2 3 
    /*
      22 22 11
      36 28 18
      29 20 14
    */
    
    return 0;
}
