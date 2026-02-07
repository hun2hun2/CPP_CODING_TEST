#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <iterator>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> result(enroll.size(), 0);
    unordered_map<string, int> idx_map;
    for (int i = 0; i < enroll.size(); i++) {
        idx_map[enroll[i]] = i;
    }

    unordered_map<string, int> ref_idx;
    for (int i = 0; i < referral.size(); i++) {
        if (referral[i] == "-") {
            ref_idx[enroll[i]] = -1;
        } else {
            ref_idx[enroll[i]] = idx_map[enroll[i]];
        }
    }

    for (int i = 0; i < seller.size(); i++) {
        int surplus = amount[i] * 100;
        string now_seller = seller[i];
        result[idx_map[now_seller]] += surplus;
        while (ref_idx[now_seller] != -1 && surplus != 0) {
            int up = surplus / 10;
            result[idx_map[now_seller]] -= up;
            now_seller = referral[idx_map[now_seller]];
            surplus = up;
            result[idx_map[now_seller]] += surplus;
        }

        if (ref_idx[now_seller] == -1) {
            result[idx_map[now_seller]] -= surplus / 10;
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
    print(solution({"john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"}, 
                   {"-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"},
                   {"young", "john", "tod", "emily", "mary"},
                   {12, 4, 2, 5, 10}
                  )); //출력값 : 360 958 108 0 450 18 180 1080
                  
        print(solution({"john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"}, 
                       {"-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"},
                       {"sam", "emily", "jaimie", "edward"},
                        {2, 3, 5, 4}
                      )); //출력값 : 0 110 378 180 270 450 0 0 
    return 0;
}
