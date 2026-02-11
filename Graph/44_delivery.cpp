#include <vector>
#include <queue>

using namespace std;

const int INF = 1000000;

int solution(int N, vector<vector<int>> road, int K) {
    vector<int> dis(N+1, INF);
    dis[1] = 0;
    vector<vector<pair<int, int>>> graph(N+1);
    vector<bool> visited(N+1, false);

    for (const auto &r : road) {
        int a = r[0], b = r[1], cost = r[2];
        graph[a].push_back({b, cost});
        graph[b].push_back({a, cost});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (visited[node]) continue;
        visited[node] = true;

        for (const auto& next : graph[node]) {
            if ((dist + next.second) < dis[next.first]) {
                dis[next.first] = dist + next.second;
                pq.push({dist + next.second, next.first});
            }
        }
    }

    int result = 0;

    for (int i = 1; i <= N; i++) {
        if (dis[i] <= K) result++;
    }
    return result;
}

#include <iostream>

using namespace std;

int main()
{
  
  cout << solution(5, {{1, 2, 1}, {2, 3, 3}, {5, 2, 2}, {1, 4, 2}, {5, 3, 1}, {5, 4, 2}}, 3) << endl; //출력값 : 4
  cout << solution(6, {{1, 2, 1}, {1, 3, 2}, {2, 3, 2}, {3, 4, 3}, {3, 5, 2}, {3, 5, 3}, {5, 6, 1}}, 4) << endl; //출력값 : 4
  return 0;
}
 