#include <vector>
#include <unordered_set>

using namespace std;

vector<int> visited;

void dfs(vector<vector<int>>& computers, int start, int n) {
    if (visited[start]) return;
    visited[start] = 1;
    for (int i = 0; i < n; i++) {
        if (computers[start][i] == 1) {
            if (start == i) continue;
            dfs(computers, i, n);
        }
    }
}   

int solution(int n, vector<vector<int>> computers) {
    int result = 0;
    visited.resize(n, 0);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(computers, i, n);
            result++;
        }
    }

    return result;
}

#include <iostream>

using namespace std;

void init()
{
  visited.clear();
}
int main()
{
  
  cout << solution(3, {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}) << endl; //출력값 : 2
  init();
  cout << solution(3, {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}}) << endl; //출력값 : 1

  return 0;
}
