#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare_cost(const vector<int> &a, const vector<int> &b) {
    return a[2] < b[2];
}

int op_find(vector<int>& set, int n) {
    if (set[n] == n) return n;

    set[n] = op_find(set, set[n]);

    return set[n];
}

void op_union(vector<int>& set, vector<int>& rank, int rt1, int rt2) {
    if (rank[rt1] < rank[rt2]) {
        set[rt1] = rt2;
    } else if (rank[rt1] > rank[rt2]) {
        set[rt2] = rt1;
    } else {
        set[rt2] = rt1;
        rank[rt1]++;
    }
}

int solution(int n, vector<vector<int>> costs) {
    sort(costs.begin(), costs.end(), compare_cost);
    vector<int> disjoint_set(n);
    vector<int> rank_data(n, 0);
    for (int i = 0; i < n; i++) {
        disjoint_set[i] = i;
    }

    int result = 0;
    for (const auto& op : costs) {
        int root1 = op_find(disjoint_set, op[0]);
        int root2 = op_find(disjoint_set, op[1]);
        if (root1 != root2) {
            op_union(disjoint_set, rank_data, root1, root2);
            result += op[2];
        }
    }

    return result;
}

int main()
{
  //bool 반환할 때 true는 1, false는 0 입니다.
  cout << solution(4, {{0, 1, 1}, {0, 2, 2}, {1, 2, 5}, {1, 3, 1}, {2, 3, 8}}) << endl; //출력값 : 4

  return 0;
}
