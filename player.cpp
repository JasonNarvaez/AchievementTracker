#include "player.h"

void Player::addGame(int playerID, int gameID, string IGN){
	//Game newGame()
	//games.pushback(newGame);
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