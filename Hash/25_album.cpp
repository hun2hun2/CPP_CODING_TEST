#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iterator>

using namespace std;

bool compareGenre(const pair<string, int> &a, const pair<string, int> &b) {
    return a.second > b.second;
}

bool compareSong(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> result;
    unordered_map<string, vector<pair<int, int>>> genre_dict;
    unordered_map<string, int> play_count;
    
    for (int i = 0; i < genres.size(); i++) {
        play_count[genres[i]] += plays[i];
        genre_dict[genres[i]].push_back({i, plays[i]});
    }

    vector<pair<string, int>> sorted_genre(play_count.begin(), play_count.end());
    sort(sorted_genre.begin(), sorted_genre.end(), compareGenre);

    for (auto &genre : sorted_genre) {
        auto &songs = genre_dict[genre.first];
        sort(songs.begin(), songs.end(), compareSong);

        for (int i = 0; i < min(2, (int)songs.size()); i++) {
            result.push_back(songs[i].first);
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
    print(solution({"classic", "pop", "classic", "classic", "pop"}, {500, 600, 150, 800, 2500})); //출력값 :  1 0 0 1
    return 0;

}
