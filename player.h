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
	vector<Player> friends;
	vector<Game> games;
	vector<Achievement> playerAchievements;
	int gamerScore;
	public:
	Player();
	Player(string newplayer): playerName(newplayer), gamerScore(0) { }
	string getName(){ return playerName; }
	
	void addGame(string gameName, string IGN);
	void addPlayer();
	
	void printGames();

};

class Game{
	vector<Achievement> achievements;
	string IGN;
	string gameName;
	public:
	Game();
	Game(string gamename,string ign): gameName(gamename), IGN(ign) { }
	Game(string gamename): gameName(gamename) { }
	
	void setName(string name){ gameName = name; }
	void addAchievement(string name, int value, int ID);
	
	string getName(){ return gameName; }
	string getIGN() { return IGN; }
	
	void printAchievements();
	
};

class Achievement{
	string achievementName;
	int achievementValue;
	int achievementID;
	public:
	Achievement(string name, int value, int ID): achievementName(name), achievementValue(value), achievementID(ID) { }
	Achievement();
	string getAchievement() { return achievementName; }
};