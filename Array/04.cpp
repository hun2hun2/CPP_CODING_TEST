#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> first = {1, 2, 3, 4, 5};
    vector<int> second = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> third = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    vector<int> result;
    vector<int> matchCnt(3);

    int len = answers.size();
    int len1 = first.size();
    int len2 = second.size();
    int len3 = third.size();

    int i = 0;
    while (i < len) {
        int correct = answers[i];
        if (correct == first[i % len1]) {
            matchCnt[0]++;
        }

        if (correct == second[i % len2]) {
            matchCnt[1]++;
        }

        if (correct == third[i % len3]) {
            matchCnt[2]++;
        }
        i++;
    }

    int max_score = *max_element(matchCnt.begin(), matchCnt.end());

    for (int i = 0; i < 3; i++) {
        if (matchCnt[i] == max_score) {
            result.push_back(i+1);
        }
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
    print(solution({1, 2, 3, 4, 5}));     // 1 
    print(solution({1, 3, 2, 4, 2}));     // 1 2 3 
    
    return 0;
}
