#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int length = weak.size();

    for (int i = 0; i < length; ++i) {
        weak.push_back(weak[i] + n);
    }

    int answer = dist.size() + 1;

    for (int start = 0; start < length; ++start) {
        do {
            int cnt = 1;
            int position = weak[start] + dist[cnt - 1];
            for (int index = start; index < start + length; ++index) {
                if (position < weak[index]) {
                    cnt += 1;
                    if (cnt > dist.size()) break;
                    position = weak[index] + dist[cnt - 1];
                }
            }

            answer = min(answer, cnt);
        } while (next_permutation(dist.begin(), dist.end()));
    }

    return answer > dist.size() ? -1 : answer;
}

#include <iostream>

using namespace std;

int main()
{
   cout << solution(12, {1, 5, 6, 10},{1, 2, 3, 4}) << endl; //출력값 : 2
   cout << solution(12, {1, 3, 4, 9, 10},{3, 5, 7}) << endl; //출력값 : 1   
   
   return 0;
}
