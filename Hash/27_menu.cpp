#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <iterator>

using namespace std;

map<string, int> combi;

void combination(string src, string dst, int depth) {
    if (dst.size() == depth) combi[dst]++;
    else {
        for (int i = 0; i < src.size(); i++) {
            combination(src.substr(i+1), dst + src[i], depth);
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> result;

    for (string &order : orders) {
        sort(order.begin(), order.end());
    }

    for (int len : course) {
        for (string order : orders) combination(order, "", len);

        int max_order = 0;
        for (auto it : combi) {
            max_order = max(max_order, it.second);
        }

        for (auto it : combi) {
            if (max_order >= 2 && it.second == max_order) {
                result.push_back(it.first);
            }
        }

        combi.clear();
    }

    sort(result.begin(), result.end());
    return result;
}

void print(vector<string> vec)
{
    copy(vec.begin(), vec.end(), std::ostream_iterator<string>(cout, " "));
    cout << endl;
}

int main()
{
    print(solution({"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"}, {2, 3, 4})); //출력값 :  AC ACDE BCFG CDE
    print(solution({"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"}, {2, 3, 5})); //출력값 : ACD AD ADE CD XYZ
    print(solution({"XYZ", "XWY", "WXA"}, {2, 3, 4})); //출력값 : WX XY 

    return 0;
}
