#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
#include <tuple>

using namespace std;

struct PairHash {
    size_t operator()(const pair<int, int>& p) const noexcept {
        return hash<int>{}(p.first) ^ (hash<int>{}(p.second) << 1);
    }
};

int bfs(vector<string>& maps, int start_x, int start_y, int end_x, int end_y) { 
    int degree = 0;
    queue<tuple<int, int, int>> q;
    unordered_set<pair<int, int>, PairHash> visited;
    q.push({start_x, start_y, degree});
    visited.insert({start_x, start_y});
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int x_limit = maps[0].size() - 1;
    int y_limit = maps.size() - 1;

    while (!q.empty()) {
        auto [x, y, degree] = q.front();
        q.pop();
        degree++;

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || ny < 0 || nx > x_limit || ny > y_limit) continue;
            if (maps[ny][nx] == 'X') continue;
            if (visited.count({nx, ny})) continue;

            if (nx == end_x && ny == end_y) return degree;
            visited.insert({nx, ny});
            q.push({nx, ny, degree});
        }
    //     if (x == 0 || x == x_limit) {
    //         if (x == 0) {
    //             if (y == 0) {
    //                 if ((x+1 == end_x && y == end_y) || (x == end_x && y+1 == end_y)) return degree;
    //                 if (maps[y][x+1] != 'X' && visited.find({x+1, y}) == visited.end()) {
    //                     q.push({x+1, y, degree});
    //                     visited.insert({x+1, y});
    //                 }
    //                 if (maps[y+1][x] != 'X' && visited.find({x, y+1}) == visited.end()) {
    //                     q.push({x, y+1, degree});
    //                     visited.insert({x, y+1});
    //                 }
    //             } else if (y == y_limit) {
    //                 if ((x+1 == end_x && y == end_y) || (x == end_x && y-1 == end_y)) return degree;
    //                 if (maps[y][x+1] != 'X' && visited.find({x+1, y}) == visited.end()) {
    //                     q.push({x+1, y, degree});
    //                     visited.insert({x+1, y});
    //                 }
    //                 if (maps[y-1][x] != 'X' && visited.find({x, y-1}) == visited.end()) {
    //                     q.push({x, y-1, degree});
    //                     visited.insert({x, y-1});
    //                 }
    //             } else {
    //                 if ((x+1 == end_x && y == end_y) || (x == end_x && y-1 == end_y) || (x == end_x && y+1 == end_y)) return degree;
    //                 if (maps[y][x+1] != 'X' && visited.find({x+1, y}) == visited.end()) {
    //                     q.push({x+1, y, degree});
    //                     visited.insert({x+1, y});
    //                 }
    //                 if (maps[y+1][x] != 'X' && visited.find({x, y+1}) == visited.end()) {
    //                     q.push({x, y+1, degree});
    //                     visited.insert({x, y+1});
    //                 }
    //                 if (maps[y-1][x] != 'X' && visited.find({x, y-1}) == visited.end()) {
    //                     q.push({x, y-1, degree});
    //                     visited.insert({x, y-1});
    //                 }
    //             }
    //         } else {
    //             if (y == 0) {
    //                 if ((x-1 == end_x && y == end_y) || (x == end_x && y+1 == end_y)) return degree;
    //                 if (maps[y][x-1] != 'X' && visited.find({x-1, y}) == visited.end()) {
    //                     q.push({x-1, y, degree});
    //                     visited.insert({x-1, y});
    //                 }
    //                 if (maps[y+1][x] != 'X' && visited.find({x, y+1}) == visited.end()) {
    //                     q.push({x, y+1, degree});
    //                     visited.insert({x, y+1});
    //                 }
    //             } else if (y == y_limit) {
    //                 if ((x-1 == end_x && y == end_y) || (x == end_x && y-1 == end_y)) return degree;
    //                 if (maps[y][x-1] != 'X' && visited.find({x-1, y}) == visited.end()) {
    //                     q.push({x-1, y, degree});
    //                     visited.insert({x-1, y});
    //                 }
    //                 if (maps[y-1][x] != 'X' && visited.find({x, y-1}) == visited.end()) {
    //                     q.push({x, y-1, degree});
    //                     visited.insert({x, y-1});
    //                 }
    //             } else {
    //                 if ((x-1 == end_x && y == end_y) || (x == end_x && y-1 == end_y) || (x == end_x && y+1 == end_y)) return degree;
    //                 if (maps[y][x-1] != 'X' && visited.find({x-1, y}) == visited.end()) {
    //                     q.push({x-1, y, degree});
    //                     visited.insert({x-1, y});
    //                 }
    //                 if (maps[y+1][x] != 'X' && visited.find({x, y+1}) == visited.end()) {
    //                     q.push({x, y+1, degree});
    //                     visited.insert({x, y+1});
    //                 }
    //                 if (maps[y-1][x] != 'X' && visited.find({x, y-1}) == visited.end()) {
    //                     q.push({x, y-1, degree});
    //                     visited.insert({x, y-1});
    //                 }
    //             }
    //         }
    //     } else {
    //         if (y == 0) {
    //                 if ((x+1 == end_x && y == end_y) || (x == end_x && y+1 == end_y) || (x-1 == end_x && y == end_y)) return degree;
    //                 if (maps[y][x+1] != 'X' && visited.find({x+1, y}) == visited.end()) {
    //                     q.push({x+1, y, degree});
    //                     visited.insert({x+1, y});
    //                 }
    //                 if (maps[y+1][x] != 'X' && visited.find({x, y+1}) == visited.end()) {
    //                     q.push({x, y+1, degree});
    //                     visited.insert({x, y+1});
    //                 }
    //                 if (maps[y][x-1] != 'X' && visited.find({x-1, y}) == visited.end()) {
    //                     q.push({x-1, y, degree});
    //                     visited.insert({x-1, y});
    //                 }
    //             } else if (y == y_limit) {
    //                 if ((x+1 == end_x && y == end_y) || (x == end_x && y-1 == end_y) || (x-1 == end_x && y == end_y)) return degree;
    //                 if (maps[y][x+1] != 'X' && visited.find({x+1, y}) == visited.end()) {
    //                     q.push({x+1, y, degree});
    //                     visited.insert({x+1, y});
    //                 }
    //                 if (maps[y-1][x] != 'X' && visited.find({x, y-1}) == visited.end()) {
    //                     q.push({x, y-1, degree});
    //                     visited.insert({x, y-1});
    //                 }
    //                 if (maps[y][x-1] != 'X' && visited.find({x-1, y}) == visited.end()) {
    //                     q.push({x-1, y, degree});
    //                     visited.insert({x-1, y});
    //                 }
    //             } else {
    //                 if ((x+1 == end_x && y == end_y) || (x == end_x && y-1 == end_y) || (x == end_x && y+1 == end_y) || (x-1 == end_x && y == end_y)) return degree;
    //                 if (maps[y][x+1] != 'X' && visited.find({x+1, y}) == visited.end()) {
    //                     q.push({x+1, y, degree});
    //                     visited.insert({x+1, y});
    //                 }
    //                 if (maps[y+1][x] != 'X' && visited.find({x, y+1}) == visited.end()) {
    //                     q.push({x, y+1, degree});
    //                     visited.insert({x, y+1});
    //                 }
    //                 if (maps[y-1][x] != 'X' && visited.find({x, y-1}) == visited.end()) {
    //                     q.push({x, y-1, degree});
    //                     visited.insert({x, y-1});
    //                 }
    //                 if (maps[y][x-1] != 'X' && visited.find({x-1, y}) == visited.end()) {
    //                     q.push({x-1, y, degree});
    //                     visited.insert({x-1, y});
    //                 }
    //             }
    //     }
    }

    return -1;
}   

int solution(vector<string> maps) {
    int start_x = 0, start_y = 0;
    int lever_x = 0, lever_y = 0;
    int exit_x = 0, exit_y = 0;
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[0].size(); j++) {
            if (maps[i][j] == 'S') {
                start_x = j;
                start_y = i;
            } else if (maps[i][j] == 'L') {
                lever_x = j;
                lever_y = i;
            } else if (maps[i][j] == 'E') {
                exit_x = j;
                exit_y = i;
            }
        }
    }

    int result_sl = bfs(maps, start_x, start_y, lever_x, lever_y);
    if (result_sl == -1) return -1;
    int result_le = bfs(maps, lever_x, lever_y, exit_x, exit_y);
    if (result_le == -1) return -1;

    return result_sl + result_le;
}

#include <iostream>

using namespace std;

int main()
{
  cout << solution({"SOOOL", "XXXXO", "OOOOO", "OXXXX", "OOOOE"}) << endl; //출력값 : 16
  cout << solution({"LOOXS", "OOOOX", "OOOOO", "OOOOO", "EOOOO"}) << endl; //출력값 : -1
  
  return 0;
}
