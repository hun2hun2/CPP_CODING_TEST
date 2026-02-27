#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    vector<int> sorted(26, 0);
    for (char c : s) {
        sorted[c - 'a']++;
    }
    
    string result = "";
    for (int i = 0; i < 26; ++i) {
        result += string(sorted[i], i + 'a');
    }

    return result;
}

#include <iostream>

using namespace std;

int main()
{
  cout << solution("hello") << endl; // 출력값 : ehllo
  cout << solution("algorithm") << endl; // 출력값 : aghilmort
  
  return 0;
}
