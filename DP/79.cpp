#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <limits>

using namespace std;

int solution(vector<string> strs, string t) {
    int INF = numeric_limits<int>::max();
    int n = t.length();
    vector<long long> dp(n+1, INF);
    dp[0] = 0;

    unordered_set<int> sizes;
    for (const auto& s : strs) {
        sizes.insert(s.length());
    }

    unordered_set<string> strsSet(strs.begin(), strs.end());

    for (int i = 1; i <= n; ++i) {
        for (int size : sizes) {
            if (i >= size && strsSet.count(t.substr(i - size, size))) {
                dp[i] = min(dp[i], dp[i- size] + 1);
            }
        }
    }

    return dp[n] != INF ? dp[n] : -1;
}

#include <iostream>

using namespace std;

int main()
{
  cout << solution({"ba", "na", "n", "a"}, "banana") << endl; //출력값 : 3
  cout << solution({"app", "ap", "p", "l", "e", "ple", "pp"}, "apple") << endl; //출력값 : 2  
  cout << solution({"ba", "an", "nan", "ban", "n"}, "banana") << endl; //출력값 : -1 
  
  return 0;
}
