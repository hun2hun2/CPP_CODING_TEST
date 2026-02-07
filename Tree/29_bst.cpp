#include <vector>
#include <string>
#include <iostream>
#include <iterator>

using namespace std;

vector<bool> solution(vector<int> lst, vector<int> search_lst) {
    vector<int> tree(1000, -1);
    vector<bool> result;

    tree[1] = lst[0];
    for (int i = 1; i < lst.size(); i++) {
        int num = lst[i];
        int idx = 1;
        while (tree[idx] != -1) {
            if (num < tree[idx]) idx = idx * 2;
            else idx = idx * 2 + 1;
        }
        tree[idx] = num;
    }

    for (int i = 0; i < search_lst.size(); i++) {
        int num = search_lst[i];
        int idx = 1;
        while (tree[idx] != num && tree[idx] != -1) {
            if (num < tree[idx]) idx = idx * 2;
            else idx = idx * 2 + 1;
        }

        if (tree[idx] == num) result.push_back(true);
        else result.push_back(false);
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
    // bool을 출력할 때 true는 1 false는 0 입니다.
    print(solution({5, 3, 8, 4, 2, 1, 7, 10}, {1, 2, 5, 6})); //출력값 : 1 1 1 0
    print(solution({1, 3, 5, 7, 9}, {2, 4, 6, 8, 10})); //출력값 : 0 0 0 0 0    
    return 0;
}
