#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        long long type;
        long long a, b;
        cin >> type >> a >> b;
        if (type == 1) {
            if (a > b/2) {
                cout << a << "\n";
                continue;
            }
            //check if the cow is greater than t/2, if so then just print a
            //position is (a, 2a - 1)
            long long pos = a;
            long long tpos = 2*a - 1;
            while (1) {
                if (tpos + pos >= b) {
                    cout << pos - (b - tpos) << "\n";
                    break;
                } else {
                    tpos += pos + 1;
                    pos = tpos/2;
                }
            }
        } else if (type == 2) {
            if (a > b/2) {
                cout << a << "\n";
                continue;
            }
            while (1) {
                if (b == 2*a - 1) {
                    cout << a << "\n";
                    break;
                }
                long long x = (b - 2*a + 1)/3;
                b -= x;
                a += x;
                if (a == b/2) {
                    a = 0;
                    b -= 1;
                }
            }
        }
    }
}