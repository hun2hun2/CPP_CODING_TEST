#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool solution(vector<string> phoneBook) {
    sort(phoneBook.begin(), phoneBook.end());
    bool result = true;

    for (int i = 0; i < phoneBook.size() - 1; i++) {
        if (phoneBook[i] == phoneBook[i + 1].substr(0, phoneBook[i].size())) {
            result = false;
            return result;
        }
    }

    return result;
}

int main()
{
  //bool 반환할 때 true는 1, false는 0 입니다.
  cout << solution({"119", "97674223", "1195524421"}) << endl; //출력값 : 0
  cout << solution({"123", "456", "789"}) << endl; //출력값 : 1
  cout << solution({"12", "123", "1235", "567", "88"}) << endl; //출력값 : 0
  
  return 0;
}
