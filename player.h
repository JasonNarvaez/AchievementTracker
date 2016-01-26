#include <vector>
#include <map>
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
	string PlayerName;
	vector<Player> Friends;
	vector<Game> Games;
	vector<Achievement> PlayerAchievements;
	int GamerScore;
	public:
	Player();
	Player(string NewPlayer): PlayerName(NewPlayer), GamerScore(0) { }
	string get_name(){ return PlayerName; }

};

class Game{
	vector<Achievement> Achievements;
	string IGN;
	string GameName;
	public:
	Game();
	Game(string gamename,string ign): GameName(gamename), IGN(ign) { }
	
};

class Achievement{
	string AchievementName;
	int AchievementValue;
	
};