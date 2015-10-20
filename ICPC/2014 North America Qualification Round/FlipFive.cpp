/*
Brute Force Problem:

1> Figure out that you either flip a cell, or don't flip it. You will not flip a cell twice or more.

2> Enumerate through every cell on the board, and:
	1. "not flip" it, move to next cell; 
	2. "flip" it: counterFlip++, also flip the surrounding cells,
		move to next cell,
		clean up;

3> When at the last cell, check whether the board has became the target board. 

Hints:
	We use a linear array to record the 3x3 cells on board, for simplicity.
	
	The index assigned to each cell:
	0 1 2
	3 4 5
	6 7 8

	Then, for an cell i, i-1 is its left neighbor, i+3 is its down neighbor, etc.
*/

#include <cstdio>
#include <iostream>
using namespace std;

int n,countFlip, result;
bool map[9],target[9];

void check(){
	for(int i=0;i<9;++i) if(map[i]!=target[i]) return;
	if(countFlip < result) result = countFlip;
}

void reverse(int i){
	if(i>=0 && i<9) map[i]=!map[i];
}

void flip(int i){
	countFlip++;
	reverse(i); // Flip the cell
	reverse(i-3); // Flip the one above it
	reverse(i+3); // Flip the one below
	if(i%3!=0) reverse(i-1); // Flip the left
	if(i%3!=2) reverse(i+1); // Flip the right
}

void unflip(int i){
	countFlip--;
	reverse(i);
	reverse(i-3);
	reverse(i+3);
	if(i%3!=0) reverse(i-1);
	if(i%3!=2) reverse(i+1); 
}

void sol(int pos){
	if(countFlip > result) return;
	if(pos == 9){
		check();
	}
	else{
		sol(pos+1);
		flip(pos);
		sol(pos+1);
		unflip(pos);
	}
}

int main() {
	int m;
	cin>>m;
	while(m--){
		result = 10;
		countFlip = 0;
		string input;
		for(int i=0;i<3;++i){
			cin>>input;
			for(int j=0;j<3;++j) target[i*3+j]=(input[j]=='*');
		}
		for(int i=0;i<9;++i) map[i]=false;
		sol(0);
	cout<<result<<endl;
	}
	return 0;
}