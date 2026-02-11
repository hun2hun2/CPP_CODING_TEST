#include <vector>
#include <queue>

using namespace std;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
const int ST_COST = 100;
const int CR_COST = 600;

struct Path {
    int y, x, direction;
};

int solution(vector<vector<int>> board) {
    int N = board.size();
    int dist[26][26][4];
    memset(dist, -1, sizeof(dist));
    queue<Path> q;

    q.push({0, 0, 0});
    q.push({0, 0, 2});

    dist[0][0][0] = 0;
    dist[0][0][2] = 0;

    while (!q.empty()) {
        auto [y, x, dir] = q.front();
        q.pop();

        int last_cost = dist[y][x][dir];

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N || board[ny][nx] == 1) continue;

            int new_cost = last_cost + (i == dir ? ST_COST : CR_COST);

            if (dist[ny][nx][i] == -1 || dist[ny][nx][i] > new_cost) {
                dist[ny][nx][i] = new_cost;
                q.push({ny, nx, i});
            }
        }
    }

    int result = 10000000;
    for (int i = 0; i < 4; i++) {
        if (dist[N-1][N-1][i] != -1) {
            result = min(result, dist[N-1][N-1][i]);
        }
    }

    return result;
}

#include <iostream>

using namespace std;

int main()
{
  
  cout << solution({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}) << endl; //출력값 : 900
  cout << solution({{0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0},{0, 0, 0, 1, 0, 0, 0, 1}, {0, 0, 1, 0, 0, 0, 1, 0}, {0, 1, 0, 0, 0, 1, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0}}
) << endl; //출력값 : 3800
  cout << solution({{0, 0, 1, 0}, {0, 0, 0, 0}, {0, 1, 0, 1}, {1, 0, 0, 0}}) << endl; //출력값 : 2100
  cout << solution({{0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 0}, {0, 0, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 1}, {0, 1, 0, 0, 0, 1},{0, 0, 0, 0, 0, 0}}) << endl; //출력값 : 3200

  return 0;
}
