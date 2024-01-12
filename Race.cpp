#include <iostream>
#include <string>
using namespace std;

void printArr(int arr[], int capacity) {
    int teams = 0;
    for (int i = 0; i < capacity; i++) {
        if (arr[i] > 0) {
            teams++;
        }
    }
    cout << "There are " << teams << " teams." << endl;
    cout << "Team Score" << endl;

    int winnerIndex = 0;
    double maxScore = 0;
    for (int i = 0; i < capacity; i++) {
        if (arr[i] > 0) {
            double score = 0;
            for (int j = 0; j < arr[i]; j++) {
                score += (j + 1) * 1.0 / (arr[i] + 1);
            }
            cout << char(65 + i) << " " << score << endl;
            if (score > maxScore) {
                maxScore = score;
                winnerIndex = i;
            }
        }
    }
    cout << "The winning team is team " << char(65 + winnerIndex) << " with a score of " << maxScore << "." << endl;
}

int main() {
    string result;
    cout << "Enter the outcome of the race: ";
    cin >> result;
    int count[26] = { 0 };

    for (int i = 0; i < result.length(); i++) {
        char isoChar = result[i];
        count[isoChar - 'A']++;
    }
    printArr(count, 26);

    return 0;
}