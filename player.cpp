#include "player.h"

void Player::addGame(string gameName, string IGN){
	Game newGame(gameName, IGN);
	games.push_back(newGame);
}

void Player::printGames(){
	cout << "Games Played:\tIGN:\n";
	for(int i=0;i<games.size();i++){
		cout << games[i].getName() << "\t" << games[i].getIGN() << endl;
	}
	cout<< endl;
}

void Game::addAchievement(string name, int value, int ID){
	Achievement newAchievement(name,value,ID);
	achievements.push_back(newAchievement);
	
}
void Game::printAchievements(){
	cout << "achievements: ";
	for(int i=0;i<achievements.size();i++){
		cout << achievements[i].getAchievement() << " ";
	}
	cout<< endl;
}