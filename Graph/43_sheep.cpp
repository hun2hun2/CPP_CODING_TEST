#include <vector>

using namespace std;

vector<vector<int>> tree;
vector<int> visited, comp;
int n, answer = 0;

void dfs(vector<int> cur) {
    int sheep = 0, wolf = 0;
    for (int c : cur) {
        if (comp[c] == 1) wolf++;
        else sheep++;
    }

    if (sheep <= wolf) return;

    answer = max(answer, sheep);

    for (int i = 0; i < cur.size(); i++) {
        int node = cur[i];
        for (int g : tree[node]) {
            if (visited[g]) continue;
            
            visited[g] = true;
            cur.push_back(g);
            dfs(cur);
            cur.pop_back();
            visited[g] = false;
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    n = info.size();
    tree.resize(n);
    visited.resize(n, false);
    comp = info;

    for (auto e : edges) {
        tree[e[0]].push_back(e[1]);
    }

    visited[0] = true;
    dfs({0});
    return answer;
}

#include <iostream>
using namespace std;

void init()
{
    tree.clear();
    visited.clear();
    comp.clear();
    n = 0;
    answer = 0;
    
}

int main()
{
  cout << solution({0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1}, 
                   {{0, 1}, {1, 2}, {1, 4}, {0, 8}, {8, 7}, {9, 10}, {9, 11}, {4, 3}, {6, 5}, {4, 6}, {8, 9}}
                  ) << endl; //출력값 : 5

  init(); // 전역변수를 초기화 해야함
  
  cout << solution({0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0}, 
                   {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {3, 7}, {4, 8}, {6, 9}, {9, 10}}
                  ) << endl; //출력값 : 5
    return 0;
}
