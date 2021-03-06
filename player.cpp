#include "player.h"

void Player::addPlayerGame(	int gameID, string gameName, string IGN	){
	Game newGame(gameID, gameName, IGN);
	games.push_back(newGame);
}

void Player::makeFriend( Player* p ){
	friends.push_back(p);
}

void Player::addPlayerAchievement( string achieveName, int achieveValue, int achieveID, int gameID ){
	Achievement newAchievement(	achieveName, achieveValue, achieveID	);
	playerAchievements.push_back( newAchievement );
	
	for( int i = 0; i < games.size(); i++ ){//store the game specific achievement into the Player's own Game class
		if( games[i].getGameID() == gameID ){
			games[i].addAchievement( achieveName, achieveValue, achieveID );
		}
	}
	
	gamerScore += achieveValue;
}

Game Player::findPlayerGame( int gameID ){//returns the player's own Game object
	for( int i = 0; i < games.size(); i++ ){
		if( games[i].getGameID() == gameID ){
			return games[i];
		}
	}
	
	//cout << "Game ID " << gameID << " not found for player!" << endl;
}

int Player::getGameIndex( int gameID ){//returns the index of the target game
	for(int i = 0; i < games.size(); i++ ){
		if(games[i].getGameID() == gameID){
			return i;			
		}
	}
	
	return -1;
}

//check if the player has played the game before
bool Player::hasGame( int gameID ){
	for( int i = 0; i < games.size(); i++ ){
		if( games[i].getGameID() == gameID ){ 
			return true;
		}
	}
	
	return false;
}

void Player::printGames(){
	cout << "GameID:\tGames Played:\tIGN:\n";
	
	for( int i = 0; i < games.size(); i++ ){
		cout << games[i].getGameID() << "\t" << games[i].getGameName() << "\t" << games[i].getIGN() << endl;
	}
	
	cout<< endl;
}

void Player::printFriends(){
	cout << "Friends:\n";
	
	for( int i = 0; i < friends.size(); i++ ){
		cout << friends[i]->getPlayerName() << ", ";
	}
	
	cout<< endl;
}

void Player::printPlayerAchievements(){
	cout << "Achievements:\n";
	
	for( int i = 0; i < playerAchievements.size(); i++ ){
		cout << playerAchievements[i].getAchieveName() << " " << playerAchievements[i].getAchieveValue() << endl;
	}
	
	cout << "GamerScore: " << gamerScore << endl;
	cout << endl;
}

void Game::addAchievement( string name, int value, int ID ){
	Achievement newAchievement( name, value, ID );
	achievements.push_back( newAchievement );
	
}

int Game::tallyAchievementValue(){
	int totalValue = 0;
	
	for( int i = 0; i < achievements.size(); i++ ){
		totalValue += achievements[i].getAchieveValue();
	}
	
	return totalValue;
}

bool Game::hasAchievement( int achievementID ){
	for( int i = 0; i < achievements.size(); i++ ){
		if( achievements[i].getAchieveID() == achievementID ){ 
			return true;
		}
	}
	
	return false;
}

string Game::findAchievementName( int achievementID ){
	for( int i = 0; i < achievements.size(); i++ ){
		if( achievements[i].getAchieveID() == achievementID ){
			return achievements[i].getAchieveName();
		}
	}
	
	//cout << "Achievement not found!" << endl;
	return "";
}

int Game::findAchievementValue( int achievementID ){
	for( int i = 0; i < achievements.size(); i++ ){
		if( achievements[i].getAchieveID() == achievementID ){
			return achievements[i].getAchieveValue();
		}
	}
	
	cout << "Achievement not found!" << endl;
	return 0;
}

void Game::printAchievements(){
	cout << "achievements: ";
	
	for( int i = 0; i < achievements.size(); i++ ){
		cout << achievements[i].getAchieveName() << " ";
	}
	
	cout<< endl;
}