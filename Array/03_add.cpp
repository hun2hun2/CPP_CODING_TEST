#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    set<int> add_set;
    int len = numbers.size();
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            add_set.insert(numbers[i] + numbers[j]);
        }
    }

    vector<int> result(add_set.begin(), add_set.end());
    return result;
}

void print(vector<int> vec)
{
    copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    print(solution({2, 1, 3, 4, 1}));     // 2 3 4 5 6 7 
    print(solution({5, 0, 2, 7}));        // 2 5 7 9 12 
    
    return 0;
}
