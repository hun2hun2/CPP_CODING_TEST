#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <iterator>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> hash_map;
    for (string s : completion) {
        hash_map[s]++;
    }

    for (string s : participant) {
        hash_map[s]--;

        if (hash_map[s] == 0) hash_map.erase(hash_map.find(s));
    }

    return hash_map.begin()->first;
}

int main()
{
    cout << solution({"leo", "kiki", "eden"}, {"eden", "kiki"}) << endl; // "leo"
    cout << solution({"marina", "josipa", "nikola", "vinko", "filipa"}, {"josipa", "filipa", "marina", "nikola"}) << endl; // "vinko"
    cout << solution({"mislav", "stanko", "mislav", "ana"}, {"stanko", "ana", "mislav"}) << endl; // "mislav"
    return 0;

}
