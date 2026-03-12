#include <vector>

using namespace std;

vector<int> solution(int amount) {
    vector<int> result;
    while (amount != 0) {
        if (amount >= 100) {
            result.push_back(100);
            amount -= 100;
        } else if (amount >= 50) {
            result.push_back(50);
            amount -= 50;
        } else if (amount >= 10) {
            result.push_back(10);
            amount -= 10;
        } else {
            result.push_back(1);
            amount -= 1;
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
  print(solution(123)); //출력값 : 100 10 10 1 1 1
  print(solution(350)); //출력값 : 100 100 100 50
  
  return 0;
}
