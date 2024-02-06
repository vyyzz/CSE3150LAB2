#include <iostream>
#include <cstdlib>
#include "fisher_yates.h"

using namespace std;

int main() {
    int n = 10;

    // cout << "Enter a number of parens: " << endl;
    // cin >> n;
    int arrVal[2 * n];

    for (int i = 0; i < n; i++) {
        arrVal[i] = 1;
    }

    for (int i = 0; i < n; i++) {
        arrVal[i + n] = -1;
    }

    int bal = 0;
    int ttl = 0;
    srand(time(NULL));

    for (int i = 0; i < 100000; i++) {
        fisher_yates(arrVal, 2 * n, rand);
        ttl++;

        if (non_neg_prefix_sum(arrVal, 2 * n) || non_pos_prefix_sum(arrVal, 2 * n)) {
            bal++;
        }
    }

    cout << "You have this many balanced: " << bal << endl;
    cout << "You have this many total trials:" << ttl << endl;
    return 0;
}



