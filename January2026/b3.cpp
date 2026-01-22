#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int Q;
    cin >> Q;
    vector<vector<int>> values(N, vector<int>(N, 0));
    vector<vector<int>> pictures(N-K+1, vector<int>(N-K+1, 0));
    int maxPhoto = 0;
    for (int q = 0; q < Q; q++) {
        int r, c, v;
        cin >> r >> c >> v;
        int diff = v - values[r-1][c-1];
        values[r-1][c-1] = v;
        for (int idx = max(0, r - K); idx <= min(N - K, r - 1); idx++) {
            for (int idy = max(0, c - K); idy <= min(N - K, c - 1); idy++) {
                pictures[idx][idy] += diff;
                maxPhoto = max(maxPhoto, pictures[idx][idy]);
                
            }
        }
        cout << maxPhoto << "\n";
    }
}
