#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <iterator>
// sstream 사용해보기

using namespace std;

vector<string> solution(vector<string> record) {
    unordered_map<string, string> nickname_map;
    vector<string> result;

    for (int i = 0; i < record.size(); i++) {
        if (record[i][0] == 'E') {
            string uid = "";
            string nickname = "";
            int j = 6;
            while (record[i][j] != ' ') {
                uid += record[i][j];
                j++;
            }
            j++;
            for (; j < record[i].length(); j++) {
                nickname += record[i][j];
            }

            nickname_map[uid] = nickname;
        } else if (record[i][0] == 'C') {
            string uid = "";
            string nickname = "";
            int j = 7;
            while (record[i][j] != ' ') {
                uid += record[i][j];
                j++;
            }
            j++;
            for (; j < record[i].length(); j++) {
                nickname += record[i][j];
            }

            nickname_map[uid] = nickname;
        }
    }

    for (int i = 0; i < record.size(); i++) {
        if (record[i][0] == 'E') {
            string uid = "";
            int j = 6;
            while (record[i][j] != ' ') {
                uid += record[i][j];
                j++;
            }

            string answer = nickname_map[uid] + "님이 들어왔습니다.";
            result.push_back(answer);
        } else if (record[i][0] == 'L') {
            string uid = "";
            for (int j = 6; j < record[i].length(); j++) {
                uid += record[i][j];
            }

            string answer = nickname_map[uid] + "님이 나갔습니다.";
            result.push_back(answer);
        }
    }

    return result;
}

void print(vector<string> vec)
{
  copy(vec.begin(), vec.end(), std::ostream_iterator<string>(cout, " "));
  cout << endl;
}

int main()
{
  print(solution( {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234", "Enter uid1234 Prodo","Change uid4567 Ryan"} ));
  // Prodo님이 들어왔습니다. Ryan님이 들어왔습니다. Prodo님이 나갔습니다. Prodo님이 들어왔습니다.    

  return 0;
}
