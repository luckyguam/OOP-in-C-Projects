#include <iostream>
using namespace std;
int main(){
int board[8][8]={};
int r=0;
int c=0;
board[0][0]=1;
int solutions = 1;
coloumncheck:
	c++;
	if(c==8)goto printSol;
	r=-1;

rowcheck: 
	r++;
	if(r==8)goto backtracker;
	for(int i=0;i<c;i++){
		if(board[r][i]==1)goto rowcheck;
	}	
	for(int i=1;(r-i)>=0 && (c-i)>=0;i++){
		if(board[r-i][c-i]==1)goto rowcheck;
	}
	for(int i=1;((r+i)<8 && (c-i)>=0);i++){
		if(board[r+i][c-i]==1)goto rowcheck;
	}
	board[r][c]=1;
	goto coloumncheck;

backtracker:
	c--;
	if(c==-1){
		return 0;
	}
	r=0;
	while(board[r][c] !=1){
	r++;
	}
	board[r][c]=0;
	goto rowcheck;

printSol:
		cout<< "Solution " << solutions++ << ": " << endl;
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
		cout << board[i][j];
		}
		cout << endl;
	}
cout<< endl;
goto backtracker;
return 0;
}