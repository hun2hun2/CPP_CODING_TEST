#include <vector>

using namespace std;

vector<int> solution(vector<int> arr1, vector<int> arr2) {
    int i1 = 0, i2 = 0;
    vector<int> result;
    while (i1 < arr1.size() && i2 < arr2.size()) {
        if (arr1[i1] < arr2[i2]) {
            result.push_back(arr1[i1]);
            i1++;
        } else {
            result.push_back(arr2[i2]);
            i2++;
        }
    }

    if (i1 < arr1.size()) {
        for (; i1 < arr1.size(); ++i1) {
            result.push_back(arr1[i1]);
        }
    } else if (i2 < arr2.size()) {
        for (; i2 < arr2.size(); ++i2) {
            result.push_back(arr2[i2]);
        }
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
  print(solution({1, 3, 5}, {2, 4, 6})); // 출력값 : 1 2 3 4 5 6
  print(solution({1, 2, 3}, {4, 5, 6})); // 출력값 : 1 2 3 4 5 6
  
  return 0;
}
