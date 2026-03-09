#include <vector>

using namespace std;

int solution(vector<int> money) {
    int house = money.size();
    vector<int> dp1(house, 0);
    vector<int> dp2(house, 0);

    dp1[0] = money[0];
    dp1[1] = money[0];
    for (int i = 2; i < house-1; ++i) {
        dp1[i] = max(dp1[i-1], dp1[i-2] + money[i]);
    }

    dp2[1] = money[1];
    for (int i = 2; i < house; ++i) {
        dp2[i] = max(dp2[i-1], dp2[i-2] + money[i]);
    }

    int result = max(dp1[house-2], dp2[house-1]);
    return result;
}

#include <iostream>

using namespace std;

int main()
{
  cout << solution({1, 2, 3, 1}) << endl; //출력값 : 4
  
  return 0;
}
