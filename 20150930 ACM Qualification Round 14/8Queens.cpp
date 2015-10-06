/*
The solution has a simple logic:
	Read in the positions of the queen.
	For every pair of queens, check whether the queen is on the same row / column / diagnol.
	If not, check whether there are 8 queens.
*/

#include <iostream> 
#include <vector>

using namespace std;
typedef pair<int,int> ii;

int main(){
	string aux;
	vector <ii> queens;
	for (int i = 0; i < 8; i++) {
		cin >> aux;
		for (int j = 0; j < 8; j++) {
			if (aux[j] == '*') 
				queens.push_back(ii(i,j));
		}
	}

	for (int i = 0; i < queens.size(); i++)
		for (int j = i+1; j < queens.size(); j++)
			if (queens[i].first == queens[j].first || 
				queens[i].second == queens[j].second ||
				abs(queens[i].first - queens[j].first) == abs(queens[i].second - queens[j].second))
			{
				cout << "invalid" << endl;
				return 0;
			}

	if(queens.size()==8) cout << "valid" << endl;
	else cout << "invalid" << endl;
	return 0;
}