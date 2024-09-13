#include"game.h"

using namespace std;


int main()
{
	Game game;
	while (game.running()&&lives)
	{
		game.update();
		game.render();
	}
	cout << "PAC-MAN COMPLETED SUCCESS-FULLY" << endl;
	return 0;
}