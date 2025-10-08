#include <set>
#include <iostream>
using namespace std; //do this every time

int value; //temporary variable for reading in values
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int N; //N cows
    int bTuition; //best tuition (part of answer) 
    long long mPaid = 0; //most paid (part of answer)
    cin >> N; //take in N
    multiset<int> cows; // automatic sorting
    for (int i = 0; i < N; i++) { //for each cow
        cin >> value; //read the into temp value
        cows.insert(value); //
    }
    long long i = 0; //index variable
    for (long long cTuition: cows) {
        if (cTuition*(N-i) > mPaid) { //if total paid > most paid (so far)
            mPaid = cTuition*(N-i); //update most paid to total paid
            bTuition = cTuition; //set best tuition to current tuition
        }
        i++; //increment
    }

    cout << mPaid << " " << bTuition; //print out answers

}
