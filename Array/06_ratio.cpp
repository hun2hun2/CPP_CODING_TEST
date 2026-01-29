#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

bool compare(pair<int, float>& a, pair<int, float>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> failUser;
    vector<int> result;
    failUser.assign(N, 0);
    int userNum = stages.size();

    for (int i = 0; i < userNum; i++) {
        failUser[stages[i] - 1]++;
    }

    vector<pair<int, float>> failRatio(N);
    float stageUser = userNum;
    for (int i = 0; i < N; i++) {
        failRatio[i].first = i + 1;
        if (stageUser == 0) failRatio[i].second = 0;
        else failRatio[i].second = failUser[i] / stageUser;
        stageUser -= failUser[i];
    }

    sort(failRatio.begin(), failRatio.end(), compare);
    for (int i = 0; i < N; i++) {
        result.push_back(failRatio[i].first);
    }

    return result;
}

void print(vector<int> vec)
{
    copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    print(solution(5, {2, 1, 2, 6, 2, 4, 3, 3})); // 3 4 2 1 5
    print(solution(4, {4, 4, 4, 4, 4}));          // 4 1 2 3 

    return 0;
}
