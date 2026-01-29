#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

vector<int> solution(vector<int> lst) {
    sort(lst.rbegin(), lst.rend());
    lst.erase(unique(lst.begin(), lst.end()), lst.end());
    return lst;
}

void print(vector<int> vec)
{
    copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    print(solution({4, 2, 2, 1, 1, 3, 4})); // 4 3 2 1  
    print(solution({2, 1, 1, 3, 2, 5, 4})); // 5 4 3 2 1
    
    return 0;
}
