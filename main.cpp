#include <iostream>
#include <vector>
#include <regex>
#include <stdio.h>
#include <string>
#include <algorithm>

#include "player.h"

using namespace std;

map<int,Player> playerDatabase;
map<int,Game> gameDatabase;

typedef map<int,Player>::iterator iteratorPlay;//keep code clean for Player and Game map iterators
typedef map<int,Game>::iterator iteratorGame;

void comparePlayers( int playerID1, int playerID2, int gameID );
void friendsWhoPlay( int playerID, int gameID );
void playsGame( int playerID, int gameID, string IGN );
void playerAchieves( int playerID, int gameID, int achievementID );
void addPlayer( int playerID, string playerName );
void addGame( int gameID, string gameName );
void addFriends( int playerID1, int playerID2 );
void summarizeGame( int gameID );
void summarizePlayer( int playerID );
void summarizeAchievement( int gameID, int achieveID );
void achievementRanking();
void printMap();

int main(){
	string command;
	string playerName;
	string IGN;
	string gameName;
	string achievementName;
	string temp;
	int gameID;
	int achievementID;
	int playerID;
	int achievementValue;
	
	cout << "Reading in input..." << endl;
	
	while( cin.good() ){
		
		cin >> command;
		
		
		if( command == "AddGame" ){
			cin >> gameID;
			
			getline(cin,temp,'\"');
			getline(cin,gameName,'\"');
			
			addGame(gameID, gameName);
		}
		else if(command == "AddAchievement"){
			string temp2;
			iteratorGame it_G;
			
			cin >> gameID >> achievementID;
			
			
			getline(cin,temp,'\"');//gets and discards the first quotation mark
			getline(cin,achievementName,'\"');//read entire string before the next quotation mark
			
			cin >> achievementValue;
			
			
			it_G = gameDatabase.find(gameID);
			if(it_G != gameDatabase.end()){//add achievement if game is found
				it_G->second.addAchievement(achievementName, achievementValue, achievementID);
			}
			
			
			
		}
		else if(command == "AddPlayer"){
			cin >> playerID;
			
			getline(cin,temp,'\"');//gets and discards the first quotation mark
			getline(cin,playerName,'\"');
			
			addPlayer(playerID, playerName);
		}
		else if(command == "AddFriends"){
			int player1;
			int player2;
			cin >> player1 >> player2;
			
			addFriends(player1, player2);
		}
		else if(command == "Plays"){
			cin >> playerID >> gameID;
			
			getline(cin,temp,'\"');//gets and discards the first quotation mark
			getline(cin,IGN,'\"');
			
			playsGame(playerID, gameID, IGN);
			
		}
		else if(command == "Achieve"){
			cin>>playerID>>gameID>>achievementID;
			
			playerAchieves(playerID, gameID, achievementID);
		}
		else if(command == "FriendsWhoPlay"){
			cin >> playerID >> gameID;
			
			cout << endl;
			cout << "[Friends Who Play]" << endl;
			
			friendsWhoPlay(playerID, gameID);
		}
		else if(command == "ComparePlayers"){
			int player1;
			int player2;
			cin >> player1 >> player2 >> gameID;
			
			cout << endl;
			cout << "[Compare Players]" << endl;
			
			comparePlayers(player1, player2, gameID);
			cout << endl;
		}
		else if(command == "SummarizePlayer"){
			cin >> gameID;
			
			cout << endl;
			cout << "[Summarize Player]" << endl;
			
			summarizePlayer(gameID);
			cout << endl;
		}
		else if(command == "SummarizeGame"){
			cin >> gameID;
			
			cout << endl;
			cout << "[Summarize Game]" << endl;
			
			summarizeGame(gameID);
			cout << endl;
		}
		else if(command == "SummarizeAchievement"){
			cin >> gameID >> achievementID;
			
			cout << endl;
			cout << "[Summarize Achievement]" << endl;
			
			summarizeAchievement(gameID, achievementID);
			cout << endl;
		}
		else if(command == "AchievementRanking"){
			
			cout << endl;
			cout << "[Achievement Ranking]" << endl;
			achievementRanking();
			cout << endl;
		}
		else{
			cout << "command not recognized: " << command<< endl;
			cout << endl;
		}
		
	}
	

}

void comparePlayers(int playerID1, int playerID2, int gameID){
	iteratorPlay it_P1;
	iteratorPlay it_P2;
	iteratorGame it_G;
	
	vector<Achievement> fullAchievementList;
	int achieveID;
	int achieveValue;
	int gameGamerScore1 = 0;
	int gameGamerScore2 = 0;
	string achieveP1;
	string achieveP2;
	
	it_P1 = playerDatabase.find(playerID1);
	it_P2 = playerDatabase.find(playerID2);
	it_G = gameDatabase.find(gameID);
	
	Game gameP1 = it_P1->second.findPlayerGame(gameID);
	Game gameP2 = it_P2->second.findPlayerGame(gameID);
	
	fullAchievementList = it_G->second.getAchievementList();//master list of achievements
	
	cout << "Game: " << it_G->second.getGameName() << endl;
	
	cout << setw(3) << left << " ";
	cout << setw(30) << left << "Achievement" << setw(20) << it_P1->second.getPlayerName() << it_P2->second.getPlayerName() << endl;
	cout << "--------------------------------------------------------------------" << endl;
	
	for( int i = 0; i < fullAchievementList.size(); i++ ){
		achieveID = fullAchievementList[i].getAchieveID();
		achieveValue = fullAchievementList[i].getAchieveValue();
		
		achieveP1 = gameP1.findAchievementName(achieveID);//if achievement name is return as empty ("")
		achieveP2 = gameP2.findAchievementName(achieveID);//then it was not found
		
		cout << i + 1 <<". " << setw(30) << left << fullAchievementList[i].getAchieveName();
		
		if( !achieveP1.empty() ){//if we have the achievement, print out the value in the column
			cout << setw(20) << left << achieveValue;
			gameGamerScore1 += achieveValue;
		}
		else {
			cout << setw(20) << left << "--";
		}
		if( !achieveP2.empty() ){
			cout << setw(20) << left << achieveValue;
			gameGamerScore2 += achieveValue;
		}
		else {
			cout << setw(20) << left << "--";
		}
			
		cout << endl;
	}
	
	cout << setw(3) << left << " ";
	cout << setw(30) << left<< "Total Gamerscore:" << setw(20) << gameGamerScore1 << gameGamerScore2 << endl;
}

void friendsWhoPlay( int playerID, int gameID ){
	iteratorPlay it_P;
	iteratorGame it_G;
	
	it_G = gameDatabase.find(gameID);
	it_P = playerDatabase.find(playerID);
	
	vector<Player*> friendsList;//temporarily hold the player's friends list
	vector<Game> gamesList;//local copy of player's games list
	
	if( it_G != gameDatabase.end() && it_P != playerDatabase.end() ){
		cout << it_P->second.getPlayerName() <<"'s friends who play: " << it_G->second.getGameName() << endl;
		cout << "---------------------------------------------------" << endl;
		friendsList = it_P->second.getFriendsList();
		
		int counter = 0;
		for( int i = 0; i < friendsList.size(); i++ ){
			if( friendsList[i]->hasGame(gameID) ){
				cout << counter + 1 << ". " << friendsList[i]->getPlayerName() << endl;
				counter++;
			}
		}
		
		cout << endl;
	}
	
	cout << endl;
}

void playerAchieves( int playerID, int gameID, int achievementID ){
	iteratorGame it_G;
	iteratorPlay it_P;
	string achieveName;
	int achieveValue;
	
	it_G = gameDatabase.find(gameID);
	
	if( it_G != gameDatabase.end() ){//add achievement if game is found
		
		achieveName = it_G->second.findAchievementName(achievementID);
		achieveValue = it_G->second.findAchievementValue(achievementID);
		
	}
	
	it_P = playerDatabase.find(playerID);
	
	if( it_P != playerDatabase.end() && !achieveName.empty() ){//make sure achievement is found (and game/player)
		it_P->second.addPlayerAchievement(achieveName, achieveValue, achievementID, gameID);
	}
	
	
}

void playsGame( int playerID, int gameID, string IGN ){
	iteratorGame it_G;
	iteratorPlay it_P;
	string gameName;
	
	it_G = gameDatabase.find(gameID);
	
	if( it_G != gameDatabase.end() ){//add achievement if game is found
		gameName = it_G->second.getGameName();		
	}
	
	it_P = playerDatabase.find(playerID);
	
	if( it_G != gameDatabase.end() && it_P != playerDatabase.end() ){//make sure both game and player exist
		it_P->second.addPlayerGame(gameID, gameName, IGN);
	}
}

void addPlayer( int playerID, string playerName ){
	Player newPlayer(playerName);
	playerDatabase.insert(pair<int,Player>(playerID,newPlayer));
}

void addGame( int gameID, string gameName ){
	Game newGame(gameID, gameName);
	gameDatabase.insert(pair<int,Game>(gameID,newGame));
}

void addFriends( int playerID1, int playerID2 ){
	iteratorPlay it_P1;
	iteratorPlay it_P2;
	
	it_P1 = playerDatabase.find(playerID1);
	it_P2 = playerDatabase.find(playerID2);
	
	if( it_P1 != playerDatabase.end() && it_P2 != playerDatabase.end() ){//make sure both players exist
		Player* p1 = &it_P1->second;
		Player* p2 = &it_P2->second;
		
		it_P1->second.makeFriend(p2);
		it_P2->second.makeFriend(p1);
	}	
}

void summarizeGame( int gameID ){
	iteratorGame it_G;
	it_G = gameDatabase.find( gameID );
	string gameName = it_G->second.getGameName();
	
	int playerCounter = 0;
	int achieveCounter = 0;
	
	vector<Achievement> achieveList = it_G->second.getAchievementList();//local (complete) list of achievement
	
	cout << "Players who play: " << gameName << endl;
	
	for ( iteratorPlay it_P = playerDatabase.begin(); it_P != playerDatabase.end(); ++it_P ){
		if( it_P->second.hasGame(gameID) ){
			cout << playerCounter + 1 << ". " << it_P->second.getPlayerName() << endl;
			
			playerCounter++;
		}
	}
	
	cout << endl;
	
	cout << gameName << " achievement Statistics: " << endl;
	cout << setw(3) << left << " ";
	cout << setw(30) << left << "Achievements" << "Total Completed" << endl;
	cout << "---------------------------------------------------" << endl;
	
	for( int i = 0; i < achieveList.size(); i++ ){
		achieveCounter = 0;
		
		for ( iteratorPlay it_P = playerDatabase.begin(); it_P != playerDatabase.end(); ++it_P ){
			int achieveID = achieveList[i].getAchieveID();
			int gameIndex=-1;
			vector<Game> playerGame = it_P->second.getGamesList();
			gameIndex = it_P->second.getGameIndex(gameID);
			
			if( gameIndex != -1 ){//make sure they have the game
				if( playerGame[gameIndex].hasAchievement(achieveID) ){//check if they have the achievement
					achieveCounter++;
				}
			}
		}
		
		cout << i+1 << ". " << setw(30) << left << achieveList[i].getAchieveName() 
			 << achieveCounter << "/" << playerCounter << endl;
	}
}

void summarizeAchievement( int gameID, int achieveID ){
	iteratorGame it_G;
	it_G = gameDatabase.find(gameID);
	
	int playerCounter = 0;
	int achieveCounter = 0;
	int counter = 1;
	vector<Achievement> achieveList = it_G->second.getAchievementList();
	
	for ( iteratorPlay it_P = playerDatabase.begin(); it_P != playerDatabase.end(); ++it_P){
		if(it_P->second.hasGame(gameID)){
			playerCounter++;
		}
		
	}
	cout << "Game: " << it_G->second.getGameName() << endl;
	cout << "Achievement Statistics: " << endl << endl;
	
	cout << "Players who obtained Achievement: " << it_G->second.findAchievementName(achieveID) << endl;
	cout << "---------------------------------------------------" << endl;
	for ( iteratorPlay it_P = playerDatabase.begin(); it_P != playerDatabase.end(); ++it_P ){
		int gameIndex = -1;
		vector<Game> playerGame = it_P->second.getGamesList();
		gameIndex = it_P->second.getGameIndex(gameID);
		
		if( gameIndex != -1 ){//make sure they have the game
			if( playerGame[gameIndex].hasAchievement(achieveID) ){//check if they have the achievement
				cout << counter << ". " << it_P->second.getPlayerName() << endl;
				
				achieveCounter++;
				counter++;
			}
		}
	}
	
	cout << endl;
	cout << "Achievement completion percentage: " <<(1.0*achieveCounter/playerCounter)*100 <<"%";
	cout << endl;
}

bool playerSortFunction(Player p1, Player p2){//for sorting players in achievementRanking
	return p1.getGamerScore() > p2.getGamerScore(); 
}

void achievementRanking(){
	iteratorPlay it_P;
	string gamerScore;//holds the string equivalent of the gamerscore (for easier output manipulation)
	vector<Player> playerID;//holds playerIDs for sorting
	
	for ( iteratorPlay it_P = playerDatabase.begin(); it_P != playerDatabase.end(); ++it_P ){
		playerID.push_back(it_P->second);
	}
	
	sort(playerID.begin(),playerID.end(),playerSortFunction);
	
	cout << setw(3) << left << " ";
	cout << setw(20) << left << "Players" << "Gamerscore" << endl;
	cout << "---------------------------------------" << endl;
	
	for( int i = 0; i < playerID.size(); i++ ){
		gamerScore = to_string(playerID[i].getGamerScore()) + " pts";
		
		cout << i+1 << ". " << setw(20) << playerID[i].getPlayerName() << gamerScore << endl;
	}
}
void summarizePlayer( int playerID ){
	iteratorPlay it_P;
	iteratorGame it_G;
	
	it_P = playerDatabase.find(playerID);
	
	string achievementFraction;//holds the fraction of achievements completed, as a string
	string gamerScore;
	
	vector<Game> playerGameList = it_P->second.getGamesList();
	vector<Player*> friendsList = it_P->second.getFriendsList();
	
	cout << "Player: " << it_P->second.getPlayerName() << endl;
	cout << "Total Gamerscore: " << it_P->second.getGamerScore() << " pts" << endl << endl;
	
	cout << setw(3) << left << " ";
	cout << setw(30) << left << "Game" << setw(20) << "Achievements" << setw(20) << "Gamerscore" << "IGN" << endl;
	cout << "------------------------------------------------------------------------------------------------" << endl;
	
	for( int i = 0; i < playerGameList.size(); i++ ){
		int gameID = playerGameList[i].getGameID();
		it_G = gameDatabase.find(gameID);
		
		achievementFraction = to_string(playerGameList[i].getAchievementList().size()) + "/";//concatenate strings
		achievementFraction += to_string(it_G->second.getAchievementList().size());
		
		gamerScore = to_string(playerGameList[i].tallyAchievementValue()) + " pts";//concatenate gamerscore string
		
		cout << i+1 << ". " << setw(30) << playerGameList[i].getGameName()
			 << setw(20) << achievementFraction
			 << setw(20) << gamerScore
			 << playerGameList[i].getIGN() << endl;
	}
	
	cout << endl;
	cout << setw(3) << left << " ";
	cout << it_P->second.getPlayerName() << "'s Friends" << endl;
	cout << "------------------------------" << endl;
	
	for( int i = 0; i < friendsList.size(); i++ ){
		cout << i+1 << ". " << friendsList[i]->getPlayerName() <<endl;
	}
}

void printMap(){//debugging print function
	for ( iteratorPlay it = playerDatabase.begin(); it != playerDatabase.end(); ++it ){
		cout << it->first << " => " << it->second.getPlayerName() << '\n';
		
		it->second.printGames();
		it->second.printPlayerAchievements();
		it->second.printFriends();
		cout << "--------------------------------------" << endl;
	}
	cout << endl;
	for (iteratorGame it=gameDatabase.begin(); it!=gameDatabase.end(); ++it){
		cout << it->first << " => " << it->second.getGameName() << '\n';
		
		it->second.printAchievements();
	}
}
