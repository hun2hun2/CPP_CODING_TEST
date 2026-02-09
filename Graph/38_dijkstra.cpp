// #include <iostream>
// #include <vector>
// #include <tuple>
// #include <algorithm>
// #include <limits>
// #include <iterator>

// using namespace std;

// const int INF = numeric_limits<int>::max();
// const int MAX_NODES = 100;
// int graph[MAX_NODES][MAX_NODES];
// bool visited[MAX_NODES];

// vector<int> solution(int start, int numNodes, vector<tuple<int, int, int>> edges) {
//     for (int i = 0; i < MAX_NODES; i++) {
//         fill_n(graph[i], MAX_NODES, INF);
//         visited[i] = false;
//     }

//     for (const auto& [from, to, weight] : edges) {
//         graph[from][to] = weight;
//     }

//     vector<int> distances(numNodes, INF);
//     distances[start] = 0;

//     for (int i = 0; i < numNodes - 1; i++) {
//         int minDistance = INF;
//         int closestNode = -1;

//         for (int j = 0; j < numNodes; j++) {
//             if (!visited[j] && distances[j] < minDistance) {
//                 minDistance = distances[j];
//                 closestNode = j;
//             }
//         }

//         visited[closestNode] = true;

//         for (int j = 0; j < numNodes; j++) {
//             int newDistance = distances[closestNode] + graph[closestNode][j];
//             if (!visited[j] && graph[closestNode][j] != INF && newDistance < distances[j]) {
//                 distances[j] = newDistance;
//             }
//         }
//     }

//     return distances;
// }

#include <vector>
#include <tuple>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    }
};

vector<int> solution(int start, int numNodes, vector<tuple<int, int, int>> edges) {
    vector<vector<pair<int, int>>> adj_list(numNodes);
    for (const auto& [from, to, weight] : edges) {
        adj_list[from].emplace_back(to, weight);
    }

    vector<int> distances(numNodes, INF);
    distances[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    pq.push({0, start});

    vector<bool> visited(numNodes, false);

    while (!pq.empty()) {
        int cur_dis = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if (visited[cur_node]) continue;

        visited[cur_node] = true;

        for (const auto& [neighbor, weight] : adj_list[cur_node]) {
            int new_dis = distances[cur_node] + weight;
            if (new_dis < distances[neighbor]) {
                distances[neighbor] = new_dis;
                pq.push({new_dis, neighbor});
            }
        }
    }

    return distances;
}

#include <iostream>
#include <iterator>

void print(vector<int> vec)
{
  copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
  cout << endl;
    
}

int main()
{
  
  print(solution(0, 3, {{0, 1, 9},{0, 2, 3},{1, 0, 5},{2, 1, 1}})); //출력값 : 0 4 3
  print(solution(0, 4, {{0, 1, 1}, {1, 2, 5}, {2, 3, 1}})); //출력값 : 0 1 6 7
  return 0;
}
