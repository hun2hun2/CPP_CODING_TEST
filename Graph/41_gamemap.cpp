#include <vector>
#include <unordered_set>
#include <queue>
#include <tuple>

using namespace std;

struct pair_hash {
    size_t operator()(const pair<int, int>& p) const noexcept {
        return hash<int>{}(p.first) ^ (hash<int>{}(p.second) << 1);
    }
};

int bfs(vector<vector<int>>& maps) {
    int end_x = maps[0].size() - 1;
    int end_y = maps.size() - 1;
    queue<tuple<int, int, int>> q;
    unordered_set<pair<int, int>, pair_hash> visited;
    q.push({0, 0, 1});
    visited.insert({0, 0});
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    while (!q.empty()) {
        auto [x, y, degree] = q.front();
        q.pop();
        degree++;
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx > end_x || ny > end_y) continue;
            if (maps[ny][nx] == 0) continue;
            if (visited.count({nx, ny})) continue;

            if (nx == end_x && ny == end_y) return degree;
            q.push({nx, ny, degree});
            visited.insert({nx, ny});
        }
    }

    return -1;
}

int solution(vector<vector<int>> maps) {
    return bfs(maps);
}

#include <iostream>

int main()
{
  
  cout << solution({{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1}}) << endl; //출력값 : 11
  cout << solution({{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 0}, {0, 0, 0, 0, 1}}) << endl; //출력값 : -1

  return 0;
}
