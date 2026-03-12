#include <vector>

using namespace std;

int solution(int N, vector<int> stations, int W) {
    int result = 0;
    int location = 1;
    int idx = 0;

    while (location <= N) {
        if (idx < stations.size() && location >= stations[idx] - W) {
            location = stations[idx] + W + 1;
            idx++;
        } else {
            location += 2 * W + 1;
            result++;
        }
    }

    return result;

    // unordered_set<int> on;
    // for (int station : stations) {
    //     for (int i = max(1, station-W); i <= min(N, station+W); ++i) {
    //         on.insert(i);
    //     }
    // }

    // int power = W * 2 + 1;
    // int result = 0;
    // int now_place = 1;
    // while (now_place <= N) {
    //     if (on.find(now_place) == on.end()) {
    //         result++;
    //         now_place += power;
    //     } else {
    //         now_place++;
    //     }
    // }

    // return result;
}

#include <iostream>

int main()
{
    cout << solution(11, {4, 11}, 1) << endl; // 3
    cout << solution(16, {9}, 1) << endl;   // 5
    return 0;
}
