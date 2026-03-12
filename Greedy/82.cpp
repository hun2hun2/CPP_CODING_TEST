#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    sort(d.begin(), d.end());
    int result = 0;
    int now_budget = 0;
    for (int i = 0; i < d.size(); ++i) {
        if (now_budget + d[i] <= budget) {
            result++;
            now_budget += d[i];
        } else break;
    }

    return result;
}

#include <iostream>

int main()
{
  cout << solution({1, 3, 2, 5, 4}, 9) << endl; //출력값 : 3
  cout << solution({2, 2, 3, 3}, 10) << endl; //출력값 : 4
  
  return 0;
}
