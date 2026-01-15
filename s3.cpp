#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N, K;
        cin >> N >> K;
        string input_str;
        cin >> input_str;
        int curr = -1;
        int nn;
        int first = input_str[0] - '0';
        vector<bool> change;
        for (char c : input_str) {
            nn = c - '0';
            if (curr >= 0) {
                if (nn == curr) {
                    change.push_back(0);
                } else {
                    change.push_back(1);
                }
            }
            curr = nn;
        }
        int least_diff_index = 0;
        int least_diff = 2147483647;
        vector<pair<int, int>> initial;
        for (int i = 0; i < K; i++) {
            int level = 0;
            int a = 1;
            int b = 0;
            bool on_same = 1;
            while (i + level*K < N-K) {
                if (change[i + level*K]) {
                    on_same = !on_same;
                }
                a += on_same;
                b += !on_same;
                level ++;
            }
            if (abs(a-b) < least_diff) {
                least_diff = abs(a-b);
                least_diff_index = i;
            }
            initial.push_back({a, b});
        }
        int countmost = 0;
        int countleast = 0;
        int most = 0;
        int least = 0;
        for (pair<int,int> a: initial) {
            if (a.first > a.second) {
                countmost += 1;
                most += a.first;
                least += a.second;
            } else {
                countleast += 1;
                most += a.second;
                least += a.first;
            }
        }
        if (countmost%2 != first) {
            most -= least_diff;
        }
        if (countleast%2 != first) {
            least += least_diff;
        }
        cout << least << " " << most << "\n";
    }
}