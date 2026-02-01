#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <iterator>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int n = progresses.size();
    vector<int> days_left(n);

    for (int i = 0; i < n; i++) {
        days_left[i] = ceil((100.0 - progresses[i]) / speeds[i]);
    }

    int count = 0;
    int max_day = days_left[0];

    for (int i = 0; i < n; i++) {
        if (days_left[i] <= max_day) {
            count++;
        } else {
            answer.push_back(count);
            count = 1;
            max_day = days_left[i];
        }
    }

    answer.push_back(count);
    return answer;

    // queue<int> q;
    // int index = 0;
    // vector<int> result;

    // int len = progresses.size();
    // while (index < len) {
    //     while (progresses[index] < 100) {
    //         for (int i = 0; i < len; i++) {
    //             progresses[i] += speeds[i];
    //         }
    //     }

    //     q.push(index);
    //     index++;
    //     while (progresses[index] >= 100 && index < len) {
    //         q.push(index);
    //         index++;
    //     }

    //     result.push_back(q.size());
    //     while (!q.empty()) {
    //         q.pop();
    //     }
    // }

    // return result;
}

void print(vector<int> vec)
{
    copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    
    print(solution({93, 30, 55}, {1, 30, 5})); // 2 1
    print(solution({95, 90, 99, 99, 80, 99}, {1, 1, 1, 1, 1, 1})); // 1 3 2
    
    return 0;

}
