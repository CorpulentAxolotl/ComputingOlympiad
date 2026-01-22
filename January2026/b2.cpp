#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T, x; 
    cin >> T >> x;

    for (int t = 0; t < T; t++) {
        int N;
        string S;

        cin >> N;
        cin >> S;

        if (N % 2 != 0) {
            cout << -1 << "\n";
            continue;
        }

        int M = 1;
        vector<int> ans(N * 3, 1);
        for (int i = 0; i < N / 2; i++) {
            string l = S.substr(i * 3, 3);
            string r = S.substr((i + N / 2) * 3, 3);
            if (l != r) {
                if (l.substr(0, 2) == r.substr(1, 2)) {
                    ans[i * 3 + 2] = 2;
                    ans[(i + N / 2) * 3] = 2;
                    M = 2;
                } else if (l.substr(1, 2) == r.substr(0, 2)) {
                    ans[i * 3] = 2;
                    ans[(i + N / 2) * 3 + 2] = 2;
                    M = 2;
                }  
            }
        }

        cout << M << "\n";

        for (int i = 0; i < N * 3; i++) {
            cout << ans[i];
            if (i == N * 3 - 1) cout << "\n";
            else cout << " ";
        }

    }
}
