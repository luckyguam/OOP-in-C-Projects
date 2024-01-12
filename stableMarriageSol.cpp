#include<iostream>
using namespace std;
bool ok(int q[], int colm) { 
	static int mp[3][3] = {0,2,1,0,2,1,1,2,0};
	static int wp[3][3] = {2,1,0,0,1,2,2,0,1};
	for(int i = 0; i < colm; i++){
	    if(q[i]==q[colm] || mp[i][q[colm]] < mp[i][q[i]] && wp[q[colm]][i] < wp[q[colm]][colm] || wp[q[i]][colm] < wp[q[i]][i] && mp[q[i]][i] < mp[q[i]][colm]) return false;
	}
	return true;
}
int count = 1;
void PrintSol(int q[]) {
	cout << "Solution: " << count++ << endl;
	cout << "Man Woman" << endl;
	for(int i = 0;  i < 3; i++){
	    cout << i << "   " << q[i] << endl;
	}
}


int main() {
	int q[3] = {};
	int c = 0;
	q[c] = 0;
	
	while(c >= 0){
	    c++;
	    if(c == 3){
	        PrintSol(q); 
	        cout << endl;
	        c--;
	    } else {
	        q[c] = -1;
	    }
	    while(c >= 0){
	        q[c]++;
	        if(q[c] == 3){
	            c--;
	        } else if(ok(q,c)){
	            break;
	        }
	    }
	}
	return 0;
}
