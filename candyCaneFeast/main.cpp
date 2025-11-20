#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<long long> heights(N);
    vector<long long> candy(M);
    for (int i = 0; i < N; i++) cin >> heights[i];
    for (int i = 0; i < M; i++) cin >> candy[i];
    long long cane[2];
    long long original;
    for (int i = 0; i < M; i++) {
        cane[0] = 0;
        cane[1] = candy[i];
        for (int j = 0; j < N; j++) {
            if (cane[0] == cane[1]) {
                break;
            }
            if (heights[j] >= cane[1]) {
                heights[j] += cane[1] - cane[0];
                break;
            }
            if (heights[j] > cane[0]) {
                original = heights[j];
                heights[j] += heights[j] - cane[0];
                cane[0] = original;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << heights[i] << "\n";
    }
}
