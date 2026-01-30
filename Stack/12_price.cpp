#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <iterator>

using namespace std;

vector<int> solution(vector<int> prices) {
    int size = prices.size();
    vector<int> result(size);
    stack<int> st;

    for (int i = 0; i < size; i++) {
        while (!st.empty() && prices[st.top()] > prices[i]) {
            result[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }

    while (!st.empty()) {
        result[st.top()] = size - st.top() - 1;
        st.pop();
    }

    return result;
}

void print(vector<int> vec)
{
    copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    print(solution({1, 2, 3, 2, 3})); // 4 3 1 1 0
    return 0;

}
