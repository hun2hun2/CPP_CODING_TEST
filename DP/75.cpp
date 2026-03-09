#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int length = triangle.size();
    vector<vector<int>> dp;
    for (int i = 0; i < length; ++i) {
        dp.push_back(vector<int>(i+1, 0));
    }

    for (int i = 0; i < dp[length-1].size(); ++i) {
        dp[length-1][i] = triangle[length-1][i];
    }

    for (int i = length-2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            dp[i][j] = max(dp[i+1][j+1] + triangle[i][j], dp[i+1][j] + triangle[i][j]);
        }
    }

    return dp[0][0];
    // int length = triangle.size();
    // vector<vector<int>> dp;
    // for (int i = 0; i < length; ++i) {
    //     dp.push_back(vector<int>(i+1, 0));
    // }
    // dp[0][0] = triangle[0][0];
    // for (int i = 0; i < length - 1; ++i) {
    //     for (int j = 0; j <= i; ++j) {  
    //         dp[i+1][j] = max(dp[i][j] + triangle[i+1][j], dp[i+1][j]);
    //         dp[i+1][j+1] = max(dp[i][j] + triangle[i+1][j+1], dp[i+1][j+1]);
    //     }
    // }

    // int result = 0;
    // for (int i = 0; i < dp[length-1].size(); ++i) {
    //     if (dp[length-1][i] > result) result = dp[length-1][i];
    // }
    // return result;
}

#include <iostream>

using namespace std;

int main()
{
  cout << solution({{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}}) << endl; //출력값 : 30
  
  return 0;
}
