#include <iostream>
#include <iterator>
#include <string>
#include <unordered_set>

using namespace std;

struct PathHash {
    size_t operator()(const pair<pair<int, int>, pair<int, int>>& p) const {
        return ((p.first.first * 31 + p.first.second) * 31 + p.second.first) * 31
            + p.second.second;
    }
};

int solution(string dirs) {
    int len = dirs.length();
    pair<int, int> point = {0, 0};
    unordered_set<pair<pair<int, int>, pair<int,int>>, PathHash> newPath;

    for (int i = 0; i < len; i++) {
        if (dirs[i] == 'U') {
            if (point.second == 5) continue;
            else {
                pair<int, int> cur = point;
                pair<int, int> next = {point.first, point.second + 1};
                if (cur > next) swap(cur, next);
                newPath.insert({cur, next});
                point.second++;
            }
        } else if (dirs[i] == 'D') {
            if (point.second == -5) continue;
            else {
                pair<int, int> cur = point;
                pair<int, int> next = {point.first, point.second - 1};
                if (cur > next) swap(cur, next);
                newPath.insert({cur, next});
                point.second--;
            }
        } else if (dirs[i] == 'R') {
            if (point.first == 5) continue;
            else {
                pair<int, int> cur = point;
                pair<int, int> next = {point.first + 1, point.second};
                if (cur > next) swap(cur, next);
                newPath.insert({cur, next});
                point.first++;
            }
        } else if (dirs[i] == 'L') {
            if (point.first == -5) continue;
            else {
                pair<int, int> cur = point;
                pair<int, int> next = {point.first - 1, point.second};
                if (cur > next) swap(cur, next);
                newPath.insert({cur, next});
                point.first--;
            }
        }
    }

    int result = newPath.size();
    return result;
}

int main()
{
    cout << solution("ULURRDLLU") << endl; // 7
    cout << solution("LULLLLLLU") << endl; // 7 

    return 0;
}
