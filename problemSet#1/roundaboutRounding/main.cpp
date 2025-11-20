#include <iostream>
#include <cmath>

using namespace std;

int repeated1s(int l) {
    int s = 0;
    for (int i = 0; i < l; i++) {
        s += pow(10,i);
    }
    return s;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int sum = 0;
        int N;
        cin >> N;
        int L = log10(N);

        for (int i = 0; i < L-1; i++) {
            sum += 5 * repeated1s(i + 1);
        }
        for (int i = 0; i < L; i++) {
            if (N >= 4 * repeated1s(L-i)*pow(10, i+1) + 5*pow(10, i)) {
                sum += min(5*pow(10, i), N - (4 * repeated1s(L-i)*pow(10, i+1) + 5*pow(10, i)) + 1);
            } else break;
        }
        cout << sum << "\n";
    }
}
