#include <vector>
#include <algorithm>

using namespace std;

bool compare_pair(pair<int, double>& a, pair<int, double>& b) {
    return a.second > b.second;
}

double solution(vector<vector<double>> items, double weight_limit) {
    int length = items.size();
    vector<pair<int, double>> values;
    for (int i = 0; i < length; ++i) {
        values.push_back({i, items[i][1] / items[i][0]});
    }

    sort(values.begin(), values.end(), compare_pair);
    double result = 0;
    double now_weight = 0;
    int index = 0;
    while (now_weight < weight_limit) {
        int items_index = values[index].first;
        if (items[items_index][0] > weight_limit - now_weight) {
            result += items[items_index][1] * (weight_limit - now_weight) / items[items_index][0];
            break;
        } else {
            result += items[items_index][1];
            now_weight += items[items_index][0];
        }
        index++;
    }

    return result;
}

#include <iostream>

int main()
{
  cout << solution({{10, 19}, {7, 10}, {6, 10}}, 15) << endl; //출력값 : 27.3333
  cout << solution({{10, 60}, {20, 100}, {30, 120}}, 50) << endl; //출력값 : 240
  
  return 0;
}
