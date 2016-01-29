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

/*
struct Database{//maybe use a set?
	map<int,Player> PlayerDB;
	vector<Player> PlayerNames;
	vector<int> PlayerIDs;
	Database();
};
*/
class Player{
	string playerName;
	
	vector<Game> games;
	vector<Achievement> playerAchievements;
	int gamerScore;
	public:
	vector<Player*> friends;
	Player();
	Player(string newplayer): playerName(newplayer), gamerScore(0) { }
	string getPlayerName() { return playerName; }
	int getGamerScore() { return gamerScore; }
	
	void addPlayerGame(int gameID, string gameName, string IGN);
	void makeFriend(Player* p);
	void addPlayerAchievement(string achieveName, int achieveValue, int achieveID, int gameID);
	
	
	vector<Player*> getFriendsList() { return friends; }
	vector<Game> getGamesList() { return games; }
	Game findPlayerGame(int gameID);
	bool hasGame(int gameID);
	
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
	Game();
	Game(int gameid, string gamename,string ign): gameID(gameid), gameName(gamename), IGN(ign) { }
	Game(int gameid, string gamename): gameID(gameid), gameName(gamename) { }//called when creating database
	
	void setName(string name){ gameName = name; }
	void addAchievement(string name, int value, int ID);
	
	vector<Achievement> getAchievementList() { return achievements; }
	string getGameName(){ return gameName; }
	string getIGN() { return IGN; }
	int getGameID() { return gameID; }
	
	string findAchievementName(int achievementID);
	int findAchievementValue(int achievementID);
	void printAchievements();
	
};

class Achievement{
	string achievementName;
	int achievementValue;
	int achievementID;
	public:
	Achievement(string name, int value, int ID): achievementName(name), achievementValue(value), achievementID(ID) { }
	Achievement();
	string getAchieveName() { return achievementName; }
	int getAchieveValue() { return achievementValue; }
	int getAchieveID() { return achievementID; }
	
};