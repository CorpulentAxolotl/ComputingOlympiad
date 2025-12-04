#include <iostream>
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

int main() {
    int N; cin >> N;
    vector<int> cows;
    string s;
    cin >> s;
    for (char c: s) {
        cows.push_back(c - '0');
    }

    vector<pair<int,int>> groups;
    int currGroup = -1;
    for (int i = 0; i < N; i++) {
        if (cows[i] == 1 && currGroup < 0) currGroup = i;
        if (cows[i] == 0 && currGroup >= 0) {
            groups.push_back({currGroup, i-1});
            currGroup = -1;
        }
    }
    if (currGroup != -1) groups.push_back({currGroup, N-1});

    int maxNights = 1000000;
    for (auto group: groups) {
        if (group.first == 0 || group.second == N-1) {
            if (maxNights > group.second - group.first)
                maxNights = group.second - group.first;
            continue;
        }
        if ((group.second - group.first)/2 < maxNights) {
            maxNights = (group.second - group.first)/2;
        }
    }
    int answer = 0;

    for (auto group: groups) {
        answer += (int) ceil((double)(group.second - group.first + 1)/(2*maxNights+1));
    }
    cout << answer;
}