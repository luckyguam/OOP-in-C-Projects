#include<iostream>
#include<cmath>
using namespace std;

bool ok(int q[], int c){
    static int adj_table[8][5] = {
        {-1},
        {0,-1},
        {0,-1},
        {0,1,2,-1},
        {0,1,3,-1},
        {1,4,-1},
        {2,3,4,-1},
        {3,4,5,6,-1}
    }; 

    for(int i = 0; i  < c; i++){
        if(q[i] == q[c]) return false;
    }

    int i=0;
    int Neighbour_box = adj_table[c][i];
    while(Neighbour_box != -1) {
        if (abs(q[c]-q[Neighbour_box]) == 1) { 
            return false;
        } 
        Neighbour_box = adj_table[c][i++];
    }
    return true;
}
int solution = 1;
void print(int q[]) {
    cout << "Solution #" << solution++ << ":\n";
    cout << "  " << q[0]+1 << " " << q[1]+1 << endl;
    cout << q[2]+1 << " "<< q[3]+1 << " " << q[4]+1 << " " << q[5]+1 << endl;
    cout << " "<< " " << q[6]+1 << " " << q[7]+1 << endl;
    cout << endl;
}

int main() {
    int q[8] = {0}; 
    int c = 0; 
    q[c] = -1;
    while(c >= 0) {
        q[c]++; 
        if(q[c] == 8) {
            c--;
        }
        else if(ok(q, c)) { 
            if(c == 7) { 
                print(q);
                c--; 
            }
            else { 
                c++;
                q[c] = -1;
            }
        }
    }
    return 0;
}
