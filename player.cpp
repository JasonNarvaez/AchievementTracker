#include "player.h"

void Player::addGame(string gameName, string IGN){
	Game newGame(gameName, IGN);
	games.push_back(newGame);
}

void Player::makeFriend(Player* p){
	friends.push_back(p);
}
//check for duplicate achievements???
void Player::addAchievement(string achieveName, int achieveValue, int achieveID){
	Achievement newAchievement(achieveName, achieveValue, achieveID);
	playerAchievements.push_back(newAchievement);
	gamerScore += achieveValue;
}

void Player::printGames(){
	cout << "Games Played:\tIGN:\n";
	for(int i=0;i<games.size();i++){
		cout << games[i].getName() << "\t" << games[i].getIGN() << endl;
	}
	cout<< endl;
}

void Player::printFriends(){
	cout << "Friends:\n";
	for(int i=0;i<friends.size();i++){
		cout << friends[i]->getName() << ", ";
	}
	
	cout<< endl;
}

void Player::printPlayerAchievements(){
	cout << "Achievements:\n";
	for(int i=0;i<playerAchievements.size();i++){
		cout << playerAchievements[i].getAchieveName() << " " << playerAchievements[i].getAchieveValue() << endl;
	}
	cout << "GamerScore: " << gamerScore << endl;
	cout<< endl;
}

void Game::addAchievement(string name, int value, int ID){
	Achievement newAchievement(name,value,ID);
	achievements.push_back(newAchievement);
	
}
string Game::findAchievementName(int achievementID){
	for(int i=0;i<achievements.size();i++){
		if(achievements[i].getAchieveID() == achievementID)
			return achievements[i].getAchieveName();
	}
	cout << "Achievement not found!" << endl;
	return "";
}

int Game::findAchievementValue(int achievementID){
	for(int i=0;i<achievements.size();i++){
		if(achievements[i].getAchieveID() == achievementID)
			return achievements[i].getAchieveValue();
	}
	cout << "Achievement not found!" << endl;
	return 0;
}

void Game::printAchievements(){
	cout << "achievements: ";
	for(int i=0;i<achievements.size();i++){
		cout << achievements[i].getAchieveName() << " ";
	}
	cout<< endl;
}