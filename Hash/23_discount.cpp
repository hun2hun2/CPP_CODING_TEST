#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <iterator>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    // unordered_map<string, int> dc_table;
    // int result = 0;
    // for (int i = 0; i < want.size(); i++) {
    //     dc_table[want[i]] = number[i];
    // }

    // for (int i = 0; i < 10; i++) {
    //     if (dc_table[discount[i]]) {
    //         dc_table[discount[i]]--;
    //     }
    // }

    // int bp = 0;
    // for (auto iter = dc_table.begin(); iter != dc_table.end(); ++iter) {
    //     if (iter->second > 0) {
    //         bp = 1;
    //         break;
    //     }
    // }

    // if (bp == 0) result++;

    // for (int i = 1; i < discount.size() - 9; i++) {
    //     if (dc_table[discount[i - 1]]) dc_table[discount[i - 1]]++;
    //     if (dc_table[discount[i + 9]]) dc_table[discount[i + 9]]--;

    //     bp = 0;
    //     for (auto iter = dc_table.begin(); iter != dc_table.end(); ++iter) {
    //         if (iter->second > 0) {
    //             bp = 1;
    //             break;
    //         }
    //     }

    //     if (bp == 0) result++;
    // }

    // return result;
    
    unordered_map<string, int> want_table;
    int result = 0;
    for (int i = 0; i < want.size(); i++) {
        want_table[want[i]] = number[i];
    }

    unordered_map<string, int> dc_table;

    for (int i = 0; i < 9; i++) {
        dc_table[discount[i]]++;
    }

    for (int i = 9; i < discount.size(); i++) {
        dc_table[discount[i]]++;
        if (want_table == dc_table) result++;
        if (--dc_table[discount[i - 9]] == 0) {
            dc_table.erase(discount[i - 9]);
        }
    }

    return result;
}

int main()
{
  cout << solution( {"banana", "apple", "rice", "pork", "pot"}, 
                    {3, 2, 2, 2, 1}, 
                    {"chicken", "apple", "apple", "banana", "rice","apple", "pork", "banana", "pork", "rice", "pot","banana", "apple", "banana"}) << endl; // 3
                      
  cout << solution( {"apple"}, 
                    {10}, 
                    {"banana", "banana", "banana", "banana","banana", "banana", "banana", "banana", "banana","banana"}) << endl; // 0
  return 0;
}
