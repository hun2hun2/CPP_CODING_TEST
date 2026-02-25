#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> results;
vector<int> selected_nums;

void backtrack(int N, int sum, int start) {
    if (sum == 10) {
        results.push_back(selected_nums);
        return;
    }
    for (int i = start; i <= N; i++) {
        if (sum + i <= 10) {
            selected_nums.push_back(i);
            backtrack(N, sum + i, i + 1);
            selected_nums.pop_back();
        }
    }
}

vector<vector<int>> solution(int N) {
    backtrack(N, 0, 1);
    return results;
}

#include <iterator>
#include <iostream>

using namespace std;

void init()
{
  results.clear();
  selected_nums.clear();    
}

void print(vector<vector<int>> vec)
{
    
  for(int i = 0; i < vec.size(); i++ ){
    copy(vec[i].begin(), vec[i].end(), std::ostream_iterator<int>(cout, " "));
    cout << endl;
  }
    
}

int main()
{
  print(solution(5));
  init();
  /*
    출력값
    1 2 3 4 
    1 4 5 
    2 3 5 
  */
  print(solution(2));
  init();
  /*
    출력값(없음)
  */  
  print(solution(7));
  /*
    출력값
    1 2 3 4 
    1 2 7 
    1 3 6 
    1 4 5 
    2 3 5 
    3 7 
    4 6 
  */
  return 0;
}
