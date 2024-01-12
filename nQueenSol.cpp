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

int solver(int n) {
    int* q = new int[n];
    int c = 0;
    q[c] = -1;
    int Solution = 0;

    while (c >= 0) {
        q[c]++;

        if (q[c] == n) {
            c--;
        } else if (ok(q, c)) {
            if (c == n - 1) {
                Solution++;
            } else {
                c++;
                q[c] = -1;
            }
        }
    }

    delete [] q;
    return Solution;
}

int main() {
    int n;
    cout << "Enter the n# of queen for the n * n board: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int Solution = solver(i);
        cout << "There are " << Solution << " solutions to the " << i << " queens problem." << endl;
    }

    return 0;
}