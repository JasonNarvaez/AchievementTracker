#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;
class Player;
class Game;
class Achievement;

class Player{
	string playerName;
	vector<Game> games;
	vector<Achievement> playerAchievements;
	int gamerScore;
	
	public:
	vector<Player*> friends;
	
	//constructors
	Player(string newplayer): playerName(newplayer), gamerScore(0) { }
	Player();
	
	//getter functions
	string getPlayerName() { return playerName; }
	int getGamerScore() { return gamerScore; }
	vector<Player*> getFriendsList() { return friends; }
	vector<Game> getGamesList() { return games; }
	
	//helping functions
	Game findPlayerGame(int gameID);
	int getGameIndex(int gameID);
	bool hasGame(int gameID);
	
	//functions
	void addPlayerGame(int gameID, string gameName, string IGN);
	void makeFriend(Player* p);
	void addPlayerAchievement(string achieveName, int achieveValue, int achieveID, int gameID);
	
	void printGames();
	void printFriends();
	void printPlayerAchievements();

};

class Game{
	vector<Achievement> achievements;
	string IGN;
	string gameName;
	int gameID;
	
	public:
	//constructors
	Game(int gameid, string gamename,string ign): gameID(gameid), gameName(gamename), IGN(ign) { }
	Game(int gameid, string gamename): gameID(gameid), gameName(gamename) { }//called when creating database
	Game();
	
	//getter functions
	vector<Achievement> getAchievementList() { return achievements; }
	string getIGN() { return IGN; }
	string getGameName(){ return gameName; }
	int getGameID() { return gameID; }
	
	//helper functions
	int tallyAchievementValue();
	int findAchievementValue(int achievementID);
	bool hasAchievement(int achievementID);
	string findAchievementName(int achievementID);
	
	//functions
	void setName(string name){ gameName = name; }
	void addAchievement(string name, int value, int ID);
	
	void printAchievements();
	
};

class Achievement{
	string achievementName;
	int achievementValue;
	int achievementID;
	
	public:
	//constructors
	Achievement(string name, int value, int ID): achievementName(name), achievementValue(value), achievementID(ID) { }
	Achievement();
	
	//getter functions
	string getAchieveName() { return achievementName; }
	int getAchieveValue() { return achievementValue; }
	int getAchieveID() { return achievementID; }
	
};