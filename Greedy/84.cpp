#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    unordered_map<int, int> count;
    int result = 0;
    for (int size : tangerine) {
        count[size]++;
    }
    vector<int> counts;
    for (auto& e : count) {
        counts.push_back(e.second);
    }

    sort(counts.rbegin(), counts.rend());
    int now_count = 0;
    int index = 0;
    while (now_count < k) {
        result++;
        now_count += counts[index];
        index++;
    }

    return result;
}

#include <iostream>

using namespace std;

int main()
{
  cout << solution(6, {1, 3, 2, 5, 4, 5, 2, 3}) << endl; //출력값 : 3
  cout << solution(4, {1, 3, 2, 5, 4, 5, 2, 3}) << endl; //출력값 : 2
  cout << solution(2, {1, 1, 1, 1, 2, 2, 2, 3}) << endl; //출력값 : 1
  
  return 0;
}
