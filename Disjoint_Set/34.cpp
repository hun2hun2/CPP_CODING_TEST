#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

int solution(vector<int> nums) {
    unordered_set<int> mon;
    for (int i = 0; i < nums.size(); i++) {
        mon.insert(nums[i]);
    }

    return min(nums.size()/2, mon.size());
}

int main()
{
  cout << solution({3, 1, 2 ,3}) << endl; //출력값 : 2
  cout << solution({3, 3, 3, 2, 2, 4}) << endl; //출력값 : 3
  cout << solution({3, 3, 3, 2, 2, 2}) << endl; //출력값 : 2
  
  return 0;
}
