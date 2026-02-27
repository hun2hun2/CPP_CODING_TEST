#include <vector>
#include <string>

using namespace std;

long long solution(long long n) {
    vector<int> count(10, 0);

    while (n > 0) {
        count[n % 10]++;
        n = n / 10;
    }

    long long result = 0;
    string s = "";
    for (int i = 9; i >= 0; --i) {
        s += string(count[i], i + '0');
    }

    result = stoll(s);
    return result;
}

#include <iostream>

using namespace std;

int main()
{
  cout << solution(118372) << endl; // 출력값 : 873211

  return 0;
}
