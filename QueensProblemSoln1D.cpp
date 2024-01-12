#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c) {
    for (int i = 0; i < c; i++) {
        if (q[i] == q[c] || abs(q[c] - q[i]) == (c - i)) {
            return false;
        }
    }
    return true;
}

int solve(int n) {
    int* q = new int[n];
    int c = 0;
    q[c] = -1;
    int count = 0;

    while (c >= 0) {
        q[c]++;

        if (q[c] == n) {
            c--;
        } else if (ok(q, c)) {
            if (c == n - 1) {
                count++;
            } else {
                c++;
                q[c] = -1;
            }
        }
    }

    delete [] q;
    return count;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int count = solve(i);
        cout << "There are " << count << " solutions to the " << i << " queens problem." << endl;
    }

    return 0;
}
