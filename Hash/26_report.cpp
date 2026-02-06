#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <iterator>

using namespace std;

// struct PairHash {
//     size_t operator()(const pair<string, string>& p) const noexcept {
//         size_t h1 = hash<string>{}(p.first);
//         size_t h2 = hash<string>{}(p.second);
//         return h1 ^ (h2 << 1);  // 간단한 조합
//     }
// };

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    // unordered_map<string, int> report_count;
    // unordered_map<string, int> id_index;
    // vector<int> result(id_list.size(), 0);
    // int i = 0;
    // for (string id : id_list) {
    //     report_count[id] = 0;
    //     id_index[id] = i;
    //     i++;
    // }

    // unordered_map<pair<string, string>, int, PairHash> id_checker;
    // unordered_map<string, vector<int>> reported_list;
    // for (string message : report) {
    //     stringstream ss(message);
    //     string user_id = "";
    //     string report_id = "";
    //     ss >> user_id >> report_id;
    //     if (id_checker[{user_id, report_id}] == 1) {
    //         continue;
    //     } else {
    //         id_checker[{user_id, report_id}] = 1;
    //         report_count[report_id]++;
    //         reported_list[report_id].push_back(id_index[user_id]);
    //     }
    // }

    // for (auto iter = report_count.begin(); iter != report_count.end(); ++iter) {
    //     if (iter->second >= k) {
    //         for (int index : reported_list[iter->first]) {
    //             result[index]++;
    //         }
    //     }
    // }

    // return result;

    unordered_map<string, unordered_set<int>> reported_list;
    unordered_map<string, int> id_index;
    vector<int> result(id_list.size(), 0);

    for (int i = 0; i < id_list.size(); i++) {
        id_index[id_list[i]] = i;
    }

    for (string message : report) {
        stringstream ss(message);
        string user_id;
        string report_id;
        ss >> user_id >> report_id;
        reported_list[report_id].insert(id_index[user_id]);
    }

    for (auto iter = reported_list.begin(); iter != reported_list.end(); ++iter) {
        if (iter->second.size() >= k) {
            for (int index : iter->second) {
                result[index]++;  
            }
        }
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
    print(solution({"muzi", "frodo","apeach", "neo"}, {"muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"}, 2)); //출력값 : 2 1 1 0
    print(solution({"con", "ryan"}, {"ryan con", "ryan con", "ryan con", "ryan con"}, 3)); //출력값 : 0 0 

    return 0;
}
