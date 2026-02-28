#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool compare_pair(pair<int, int>& a, pair<int, int>& b) {
    return a.second > b.second;
}

vector<int> solution(string s) {
    int index = 1;
    unordered_map<int, int> counts;
    while (index < s.size()) {
        if (s[index] == '{') {
            index++;
            string num = "";
            while (s[index] != '}') {
                if (s[index] != ',') {
                    num += s[index];
                    index++;
                } else {
                    counts[stoi(num)]++;
                    num = "";
                    index += 2;
                }
            }
            counts[stoi(num)]++;
            index++;
        } else if (s[index] == ',') {
            index += 2;
        } else {
            break;
        }
    }

    vector<pair<int, int>> sorted_map(counts.begin(), counts.end());
    sort(sorted_map.begin(), sorted_map.end(), compare_pair);

    vector<int> result;
    for (auto e : sorted_map) {
        result.push_back(e.first);
    }

    return result;
}

#include <iterator>
#include <iostream>

using namespace std;

void print(vector<int> vec)
{
  copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
  cout << endl;
}


int main()
{
  print(solution("{{2}, {2, 1}, {2, 1, 3}, {2, 1, 3, 4}}")); // 출력값 : 2 1 3 4
  print(solution("{{1, 2, 3}, {2, 1}, {1, 2, 4, 3}, {2}}")); // 출력값 : 2 1 3 4
  print(solution("{{20, 111}, {111}}")); // 출력값 : 111 20
  print(solution("{{123}}")); // 출력값 : 123
  print(solution("{{4, 2, 3}, {3}, {2, 3, 4, 1}, {2, 3}}")); // 출력값 : 3 2 4 1 
  
  return 0;
}
