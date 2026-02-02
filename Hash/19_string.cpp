#include <iostream>
#include <vector>
#include <unordered_set>
#include <iterator>
#include <string>

using namespace std;

long long polynomial_hash(const string s) {
    long long num = 0;
    const int p = 31;
    const long long m = 1000000007;
    
    for (char c : s) {
        num = (num * p + c) % m;
    }

    return num;
}

vector<bool> solution(vector<string> string_list, vector<string> query_list) {
    unordered_set<long long> hash_set;
    vector<bool> result;

    for (string s : string_list) {
        hash_set.insert(polynomial_hash(s));
    }

    for (string s : query_list) {
        long long query_hash = polynomial_hash(s);
        bool found = (hash_set.find(query_hash) != hash_set.end());
        result.push_back(found);
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
    //true를 출력하면 1이되고 false를 출력하면 0
    print(solution({"apple", "banana", "cherry"}, {"banana", "kiwi", "melon", "apple"})); // 1 0 0 1
    return 0;

}
