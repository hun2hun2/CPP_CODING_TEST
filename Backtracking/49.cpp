#include <vector>

using namespace std;

int max_count = 0;
bool visited[8] = { false, };

void explore_dungeon(int count, int power, vector<vector<int>>& dungeons) {
    if (max_count < count) max_count = count;

    for (int i = 0; i < dungeons.size(); i++) {
        if (visited[i] == true || dungeons[i][0] > power) continue;

        visited[i] = true;
        explore_dungeon(count + 1, power - dungeons[i][1], dungeons);
        visited[i] = false;
    }
}

int solution(int initialPower, vector<vector<int>> dungeons) {
    explore_dungeon(0, initialPower, dungeons);
    return max_count;
}

#include <iostream>

using namespace std;

int main()
{
  cout << solution(80, {{80, 20}, {50, 40}, {30, 10}}) << endl; // 출력값 : 3
  return 0;
}
