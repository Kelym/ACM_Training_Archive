/*
Create an array to store the positions of the wall-divisor.
Remeber to also put '0' representing the left wall and N representing the right wall to the array.
For every pair of positions in the array record the space between them.
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	vector <int> divisions;
	int N, m, aux; 
	cin >> N >> m; 
	divisions.push_back(0);
	for (int i = 0; i < m; i++) {
		cin >> aux;
		divisions.push_back(aux);
	}
	divisions.push_back(N);
	set <int> ans;
	for(int i = 0; i < divisions.size(); i++)
		for (int j = i+1; j < divisions.size(); j++) {
			ans.insert(divisions[j] - divisions[i]);
		}
	
	auto a = ans.begin();
	if(a != ans.end()) cout << *a;
	a++;
	for(; a != ans.end(); a++)
		cout << " " << *a; 
	return 0;
}