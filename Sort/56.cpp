#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int compare_int = 0;

bool compare_def(const string& a, const string& b) {
    if (a[compare_int] == b[compare_int]) return a < b;
    else return a[compare_int] < b[compare_int];
}

vector<string> solution(vector<string> strings, int n) {
    compare_int = n;
    sort(strings.begin(), strings.end(), compare_def);
    return strings;
}

#include <iostream>
#include <iterator>

using namespace std;

void print(vector<string> vec)
{
  copy(vec.begin(), vec.end(), std::ostream_iterator<string>(cout, " "));
  cout << endl;
}

int main()
{
  print(solution({"sun", "bed", "car"}, 1)); //출력값 : car bed sun
  print(solution({"abce", "abcd", "cdx"}, 2));  // 출력값 : abcd abce cdx

  return 0;
}
