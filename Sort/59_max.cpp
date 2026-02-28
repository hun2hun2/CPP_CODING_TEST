#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare_strs(const string& a, const string& b) {
    return (a + b) > (b + a);
}

string solution(vector<int> numbers) {
    vector<string> num_strs;
    for (int num : numbers) {
        num_strs.push_back(to_string(num));
    }

    sort(num_strs.begin(), num_strs.end(), compare_strs);
    string result = "";
    for (int i = 0; i < num_strs.size(); ++i) {
        result += num_strs[i];
    }

    return result[0] == '0' ? "0" : result;
}

#include <iostream>

using namespace std;

int main()
{
  cout << solution({6, 10, 2}) << endl; // 출력값 : 6210
  cout << solution({3, 30, 34, 5, 9}) << endl; // 출력값 : 9534330
  return 0;
}
