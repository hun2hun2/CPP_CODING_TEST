#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <iterator>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    unordered_set<string> hash_set;
    vector<int> result;
    char last = words[0][(words[0].length() - 1)];
    hash_set.insert(words[0]);

    for (int i = 1; i < words.size(); i++) {
        char first = words[i][0];

        if (last != first) {
            result.push_back((i % n) + 1);
            result.push_back((i / n) + 1);
            return result;
        }

        if (!hash_set.insert(words[i]).second) {
            result.push_back((i % n) + 1);
            result.push_back((i / n) + 1);
            return result;
        } else {
            hash_set.insert(words[i]);
            last = words[i][(words[i].length() - 1)];
        }
    }

    result.push_back(0);
    result.push_back(0);
    return result;
}

void print(vector<int> vec)
{
  copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
  cout << endl;
}

int main()
{
  print(solution(3, {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"})); // 결과값 : 3 3
  print(solution(5, {"hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive"})); // 결과값 : 0 0
  print(solution(2, {"hello", "one", "even", "never", "now", "world", "draw"})); // 결과값 : 1 3
  
  return 0;
}
