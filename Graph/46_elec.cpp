#include <vector>
#include <iterator>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int result = 101;

    for (const auto& wire : wires) {
        vector<bool> visited(n+1, false);
        vector<vector<int>> new_wires = wires;
        for (auto iter = new_wires.begin(); iter != new_wires.end(); ++iter) {
            if ((*iter) == wire) {
                new_wires.erase(iter);
                break;
            }
        }

        vector<vector<int>> graph(n+1);
        for (const auto& new_wire : new_wires) {
            graph[new_wire[0]].push_back(new_wire[1]);
            graph[new_wire[1]].push_back(new_wire[0]);
        }

        queue<int> q;
        int first_elec = wire[0];
        int first_result = 0;
        q.push(first_elec);
        visited[first_elec] = true;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            first_result++;
            for (const int connects : graph[node]) {
                if (!visited[connects]) {
                    q.push(connects);
                    visited[connects] = true;
                }
            }
        }

        int temp_result = ((n - first_result) < first_result ? (first_result - (n - first_result)) : ((n - first_result) - first_result));
        result = min(result, temp_result);
    }

    return result;
}

#include <iostream>

using namespace std;

int main()
{
  
  cout << solution(9, {{1, 3}, {2, 3}, {3, 4}, {4, 5}, {4, 6}, {4, 7}, {7, 8}, {7, 9}}) << endl; //출력값 : 3
  cout << solution(4, {{1, 2}, {2, 3}, {3, 4}}) << endl; //출력값 : 0
  cout << solution(7, {{1, 2}, {2, 7}, {3, 7}, {3, 4}, {4, 5}, {6, 7}}) << endl; //출력값 : 1
  return 0;
}
