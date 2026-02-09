#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <iterator>

using namespace std;

unordered_map<int, vector<int>> adj_list;
vector<int> result;

void bfs(int start) {
    queue<int> to_visit;
    unordered_set<int> visited;
    to_visit.push(start);
    visited.insert(start);
    result.push_back(start);

    while (!to_visit.empty()) {
        int now_visit = to_visit.front();
        to_visit.pop();
        for (const int node : adj_list[now_visit]) {
            if (visited.find(node) == visited.end()) {
                to_visit.push(node);
                visited.insert(node);
                result.push_back(node);
            }
        }
    }
}

vector<int> solution(vector<pair<int, int>> graph, int start) {
    for (const auto& edge : graph) {
        adj_list[edge.first].push_back(edge.second);
    }

    bfs(start);
    return result;
}

void init()
{
  adj_list.clear();
  result.clear();
}
void print(vector<int> vec)
{
  copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
  cout << endl;
    
}

int main()
{
  
  print(solution({{1, 2}, {1, 3}, {2, 4}, {2, 5}, {3, 6}, {3, 7}, {4, 8}, {5, 8}, {6, 9}, {7, 9}}, 1)); //출력값 : 1 2 3 4 5 6 7 8 9
  init();
  print(solution({{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 0}}, 1)); //출력값 : 1 2 3 4 5 0
  return 0;
}
