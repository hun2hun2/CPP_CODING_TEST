#include <vector>

using namespace std;

int max_score = -1;
vector<int> answer;
vector<int> ryan(11, 0);

int calcScoreDiff(const vector<int> &apeach) {
    int score_apeach = 0;
    int score_ryan = 0;

    for (int i = 0; i < 11; ++i) {
        if (apeach[i] == 0 && ryan[i] == 0) continue;
        if (apeach[i] >= ryan[i]) score_apeach += 10 - i;
        else score_ryan += 10 - i;
    }

    return score_ryan - score_apeach;
}

void dfs(const vector<int> apeach, int score, int arrow) {
    if (score == -1 || arrow == 0) {
        ryan[10] = arrow;
        int score_diff = calcScoreDiff(apeach);
        if (score_diff > 0 && max_score < score_diff) {
            max_score = score_diff;
            answer = ryan;
        }
        ryan[10] = 0;
        return;
    }

    if (arrow > apeach[score]) {
        ryan[score] = apeach[score] + 1;
        dfs(apeach, score - 1, arrow - apeach[score] - 1);
        ryan[score] = 0;
    }

    dfs(apeach, score - 1, arrow);
}

vector<int> solution(int n, vector<int> info) {
    dfs(info, 10, n);

    if (max_score == -1) answer.push_back(-1);

    return answer;
}

#include <iostream>
#include <iterator>
using namespace std;

void init(){
  answer.clear();
  max_score = -1;
  
  for(int i = 0 ; i < ryan.size(); i++)
    ryan[i] = 0;
}

void print(vector<int> vec)
{
  copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
  cout << endl;
}

int main()
{
  print(solution(5, {2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0})); //출력값 : 0 2 2 0 1 0 0 0 0 0 0 
  init();
  print(solution(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0})); //출력값 : -1
  init();
  print(solution(9, {0, 0, 1, 2, 0, 1, 1, 1, 1, 1, 1})); //출력값 : 1 1 2 0 1 2 2 0 0 0 0 
  return 0;
}
