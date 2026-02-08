#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

int op_find(vector<int>& set, int n) {
    if (set[n] == n) return n;

    set[n] = op_find(set, set[n]);

    return set[n];
}

void op_union(vector<int>& set, vector<int>& rank_data, int n1, int n2) {
    int root1 = op_find(set, n1);
    int root2 = op_find(set, n2);

    if (root1 != root2) {
        if (rank_data[root1] < rank_data[root2]) {
            set[root1] = root2;
        } else if (rank_data[root1] > rank_data[root2]) {
            set[root2] = root1;
        } else {
            set[root2] = root1;
            rank_data[root1]++;
        }
    }
}

vector<bool> solution(int k, vector<vector<char>> operations) {
    vector<int> disjoint_set(k);
    vector<int> rank_data(k, 0);

    for (int i = 0; i < k; i++) {
        disjoint_set[i] = i;
    }

    vector<bool> result;
    for (const auto& op : operations) {
        if (op[0] == 'u') {
            int n1 = op[1] - '0';
            int n2 = op[2] - '0';
            op_union(disjoint_set, rank_data, n1, n2);
        } else {
            int n1 = op[1] - '0';
            int n2 = op[2] - '0';
            result.push_back(op_find(disjoint_set, n1) == op_find(disjoint_set, n2));
        }
    }

    return result;
}

void print(vector<bool> vec)
{
  copy(vec.begin(), vec.end(), std::ostream_iterator<bool>(cout, " "));
  cout << endl;
}

int main()
{
  print(solution(3, {{'u', '0', '1'}, {'u', '1', '2'}, {'f', '0', '2'}})); // 결과값 : 1
  print(solution(4, {{'u', '0', '1'}, {'u', '2', '3'}, {'f', '0', '1'}, {'f', '0', '2'}})); // 결과값 : 1 0
  
  return 0;
}
