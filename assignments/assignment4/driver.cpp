#include "Insect.hpp"
#include "Player.hpp"
using namespace std;

int main(){
	Player p;
	vector<vector<Insect*> > board(10); 
	p.runGame(board);
	// p.deleteBoard(board);
	return 0;
}

