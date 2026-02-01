#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string result = "Yes";
    int index1 = 0;
    int index2 = 0;

    int i = 0;
    while (i < goal.size()) {
        if (goal[i] == cards1[index1]) {
            index1++;
        } else if (goal[i] == cards2[index2]) {
            index2++;
        } else {
            result = "No";
            return result;
        }
        i++;
    }

    return result;
}

int main()
{
    cout<< solution({"i", "drink", "water"}, {"want", "to"}, {"i", "want", "to", "drink", "water"}) << endl; // "Yes"
    cout<< solution({"i", "water", "drink"}, {"want", "to"}, {"i", "want", "to", "drink", "water"}) << endl; // "No"
    return 0;

}
