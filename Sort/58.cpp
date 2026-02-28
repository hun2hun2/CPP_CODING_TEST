#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> result;
    for (auto command : commands) {
        vector<int> new_array(array.begin() + command[0] - 1, array.begin() + command[1]);
        sort(new_array.begin(), new_array.end());
        result.push_back(new_array[command[2] - 1]);
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
  print(solution({1, 5, 2, 6, 3, 7, 4}, {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}})); // 출력값 : 5 6 3

  return 0;
}
