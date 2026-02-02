#include <iostream>
#include <vector>

using namespace std;

void mapping(vector<int>& hash, const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > target) continue;
        hash[arr[i]] = 1;
    }
}

bool solution(vector<int> arr, int target) {
    vector<int> hash(target + 1, 0);
    bool result = false;

    mapping(hash, arr, target);

    for (int i = 0; i < arr.size(); i++) {
        int num = target - arr[i];
        if (arr[i] == num) continue;
        if (num < 0) continue;

        if (hash[num] == 1) {
            result = true;
            return result;
        }
    }

    return result;
}

int main()
{
    //true를 출력하면 1이되고 false를 출력하면 0
    cout<< solution({1, 2, 3, 4, 8}, 6) << endl; // 1
    cout<< solution({2, 3, 5,9}, 10) << endl; // 0
    return 0;

}
