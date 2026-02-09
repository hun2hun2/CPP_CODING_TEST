#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iterator>

using namespace std;

unordered_map<char, vector<char>> adj_list;
vector<char> result;
unordered_set<char> visited;

void dfs(char node) {
    visited.insert(node);
    result.push_back(node);

    for (char neighbor : adj_list[node]) {
        if (visited.find(neighbor) == visited.end()) dfs(neighbor);
    }
}

vector<char> solution(vector<pair<char, char>> graph, char start) {
    for (int i = 0; i < graph.size(); i++) {
        adj_list[graph[i].first].push_back(graph[i].second);
    }

    dfs(start);
    return result;
}

void init()
{
  adj_list.clear();
  result.clear();
  visited.clear();
}

void print(vector<char> vec)
{
  copy(vec.begin(), vec.end(), std::ostream_iterator<char>(cout, " "));
  cout << endl;
    
}

int main()
{
  //bool 반환할 때 true는 1, false는 0 입니다.
  print(solution({{'A', 'B'}, {'B', 'C'}, {'C', 'D'}, {'D', 'E'}}, 'A')); //출력값 : A B C D E
  init();
  print(solution({{'A', 'B'}, {'A', 'C'}, {'B', 'D'}, {'B', 'E'}, {'C', 'F'}, {'E', 'F'}}, 'A')); //출력값 : A B D E F C

  return 0;
}
