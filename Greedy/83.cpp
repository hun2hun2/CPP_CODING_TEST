#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int nums = people.size();
    int result = 0;
    sort(people.rbegin(), people.rend());

    int front_index = 0;
    int back_index = nums - 1;
    while (front_index <= back_index) {
        if (front_index == back_index) {
            result++;
            break;
        } else {
            if (people[front_index] + people[back_index] <= limit) {
                front_index++;
                back_index--;
                result++;
            } else {
                front_index++;
                result++;
            }
        }
    }

    return result;
}

#include <iostream>

int main()
{
  cout << solution({70, 50, 80, 50}, 100) << endl; //출력값 : 3
  cout << solution({70, 80, 50}, 100) << endl; //출력값 : 3
  
  return 0;
}
