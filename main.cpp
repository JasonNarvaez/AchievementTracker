#include <iostream>
#include <vector>
#include <regex>
#include <stdio.h>
#include <string>
#include <algorithm>

#include "player.h"

using namespace std;

//Database PlayerDatabase();
map<int,Player> playerDatabase;
map<int,Game> gameDatabase;

void comparePlayers(int playerID1, int playerID2, int gameID);
void friendsWhoPlay(int playerID, int gameID);
void playsGame(int playerID, int gameID, string IGN);
void playerAchieves(int playerID, int gameID, int achievementID);
void addPlayer(int playerID, string playerName);
void addGame(int gameID, string gameName);
void addFriends(int playerID1, int playerID2);
void summarizeGame(int gameID);
void summarizePlayer(int gameID);
void summarizeAchievement(int gameID, int achieveID);
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
	while(cin.good()){
		cin >> command;
		cout << "command: " << command << endl;
		
		if(command == "AddGame"){
			cin >> gameID;
			//getline(cin,GameName);
			getline(cin,temp,'\"');
			getline(cin,gameName,'\"');
			cout << command << " " << gameID << " " << gameName << endl;
			addGame(gameID, gameName);
		}
		else if(command == "AddAchievement"){
			string temp2;
			map<int,Game>::iterator it;
			
			cin >> gameID >> achievementID;
			cout << command << " " << gameID << " " << achievementID << endl; 
			
			getline(cin,temp,'\"');//gets and discards the first quotation mark
			getline(cin,achievementName,'\"');//read entire string before the next quotation mark
			cin >> achievementValue;
			
			cout << "The achievement: " << achievementName << endl;
			cout << "The achievement Value: " << achievementValue << endl;
			cout << command << " " << gameID << " " << achievementID << " " << achievementName << " " << achievementValue<<endl;
			
			it = gameDatabase.find(gameID);
			if(it != gameDatabase.end()){//add achievement if game is found
				it->second.addAchievement(achievementName, achievementValue, achievementID);
			}
			/*
			for (map<int,Game>::iterator it=gameDatabase.begin(); it!=gameDatabase.end(); ++it){
				if(it->first == gameID){
					it->second.addAchievement(achievementName, achievementValue, achievementID);
				}
				
			}
			*/
			cout << "--------------------------------------" << endl;
			
		}
		else if(command == "AddPlayer"){
			cin >> playerID;
			//getline(cin,PlayerName);
			getline(cin,temp,'\"');//gets and discards the first quotation mark
			getline(cin,playerName,'\"');
			cout << command << " " << playerID << " " << playerName << endl;
			
			addPlayer(playerID, playerName);
		}
		else if(command == "AddFriends"){
			int player1;
			int player2;
			cin >> player1 >> player2;
			cout << command << " " << player1 << " " << player2 << endl;
			addFriends(player1, player2);
		}
		else if(command == "Plays"){
			cin >> playerID >> gameID;
			//getline(cin,IGN);
			getline(cin,temp,'\"');//gets and discards the first quotation mark
			getline(cin,IGN,'\"');
			cout << command << " " << playerID << " " << gameID << " " << IGN << endl;
			playsGame(playerID, gameID, IGN);
			
		}
		else if(command == "Achieve"){
			cin>>playerID>>gameID>>achievementID;
			cout << command << " " << playerID << " " << gameID << " " << achievementID << endl;
			playerAchieves(playerID, gameID, achievementID);
		}
		else if(command == "FriendsWhoPlay"){
			cin >> playerID >> gameID;
			cout << command <<" "<< playerID <<" "<< gameID << endl;
			friendsWhoPlay(playerID, gameID);
		}
		else if(command == "ComparePlayers"){
			int player1;
			int player2;
			cin >> player1 >> player2 >> gameID;
			cout << command << " " << player1 << " " << player2 << " " << gameID << endl;
			comparePlayers(player1, player2, gameID);
		}
		else if(command == "SummarizePlayer"){
			cin >> gameID;
			cout << command << " " << gameID << endl;
			cout << "--------------------------------------" << endl;
			summarizePlayer(gameID);
		}
		else if(command == "SummarizeGame"){
			cin >> gameID;
			cout << command << " " << gameID << endl;
			cout << "--------------------------------------" << endl;
			summarizeGame(gameID);
		}
		else if(command == "SummarizeAchievement"){
			cin >> gameID >> achievementID;
			cout << command << " " << gameID << " " << achievementID << endl;
			cout << "--------------------------------------" << endl;
			summarizeAchievement(gameID, achievementID);
		}
		else if(command == "AchievementRanking"){
			cout << command << endl;
			achievementRanking();
		}
		else{
			cout << "command not recognized: " << command<< endl;
		}
		
	}
	//printMap();

}

void comparePlayers(int playerID1, int playerID2, int gameID){
	map<int,Player>::iterator it_P1;
	map<int,Player>::iterator it_P2;
	map<int,Game>::iterator it_G;
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
	
	fullAchievementList = it_G->second.getAchievementList();
	cout << "Game: " << it_G->second.getGameName() << endl;
	cout << "\t\t\t\t" << it_P1->second.getPlayerName() << "\t\t\t\t" << it_P2->second.getPlayerName() << endl;
	
	for(int i=0;i<fullAchievementList.size();i++){
		achieveID = fullAchievementList[i].getAchieveID();
		achieveValue = fullAchievementList[i].getAchieveValue();
		achieveP1 = gameP1.findAchievementName(achieveID);
		achieveP2 = gameP2.findAchievementName(achieveID);
		cout << "Achievement: " << fullAchievementList[i].getAchieveName() << "\t";
		
		if(!achieveP1.empty()){
			cout << achieveValue;
			cout << "\t\t\t\t";
			gameGamerScore1 += achieveValue;
		}
		else {
			cout << "--";
			cout << "\t\t\t\t";
		}
		if(!achieveP2.empty()){
			cout << achieveValue;
			cout << "\t\t\t\t";
			gameGamerScore2 += achieveValue;
		}
		else {
			cout << "--";
			cout << "\t\t\t\t";
		}
			
		cout << endl;
	}
	cout << "\t\t\t\t" << gameGamerScore1 << "\t\t\t\t" << gameGamerScore2 << endl;
}

void friendsWhoPlay(int playerID, int gameID){
	map<int,Player>::iterator it_P;
	map<int,Game>::iterator it_G;
	it_G = gameDatabase.find(gameID);
	it_P = playerDatabase.find(playerID);
	vector<Player*> friendsList;//temporarily hold the player's friends list
	vector<Game> gamesList;//local copy of player's games list
	
	if(it_G != gameDatabase.end() && it_P != playerDatabase.end()){
		cout << it_P->second.getPlayerName() <<"'s friends who play: " << it_G->second.getGameName() << endl;
		friendsList = it_P->second.getFriendsList();
		
		
		for(int i=0;i<friendsList.size();i++){
			
			if(friendsList[i]->hasGame(gameID))
				cout << friendsList[i]->getPlayerName() << ", ";
		}
		cout << endl;
	}
	cout << endl;
}

void playerAchieves(int playerID, int gameID, int achievementID){
	map<int,Game>::iterator it_G;
	map<int,Player>::iterator it_P;
	string achieveName;
	int achieveValue;
	it_G = gameDatabase.find(gameID);
	if(it_G != gameDatabase.end()){//add achievement if game is found
		/*
		for(int i=0;i<it_G->second.achievements.size();i++){
			if(it_G->second.achievements[i].getAchieveID() == achievementID){
				achieveName = achievements[i].getAchieveName();
				achieveValue = achievements[i].getAchieveValue();
			}
		}*/
		achieveName = it_G->second.findAchievementName(achievementID);
		achieveValue = it_G->second.findAchievementValue(achievementID);
		
	}	
	it_P = playerDatabase.find(playerID);
	if(it_P != playerDatabase.end() && !achieveName.empty()){//make sure achievement is found (and game/player)
		it_P->second.addPlayerAchievement(achieveName, achieveValue, achievementID, gameID);
	}
	
	
}

void playsGame(int playerID, int gameID, string IGN){
	map<int,Game>::iterator it_G;
	map<int,Player>::iterator it_P;
	string gameName;
	it_G = gameDatabase.find(gameID);
	
	if(it_G != gameDatabase.end()){//add achievement if game is found
		gameName = it_G->second.getGameName();
		
	}	
	it_P = playerDatabase.find(playerID);
	if(it_G != gameDatabase.end() && it_P != playerDatabase.end()){//make sure both game and player exist
		it_P->second.addPlayerGame(gameID, gameName, IGN);
	}
	
	
}

void addPlayer(int playerID, string playerName){
	Player newPlayer(playerName);
	playerDatabase.insert(pair<int,Player>(playerID,newPlayer));

}

void addGame(int gameID, string gameName){
	Game newGame(gameID, gameName);
	gameDatabase.insert(pair<int,Game>(gameID,newGame));

}
//should we check if they try to add themselves or the same person twice???
void addFriends(int playerID1, int playerID2){
	map<int,Player>::iterator it_P1;
	map<int,Player>::iterator it_P2;
	
	it_P1 = playerDatabase.find(playerID1);
	it_P2 = playerDatabase.find(playerID2);
	if(it_P1 != playerDatabase.end() && it_P2 != playerDatabase.end()){//make sure both players exist
		Player* p1 = &it_P1->second;
		Player* p2 = &it_P2->second;
		
		it_P1->second.makeFriend(p2);
		it_P2->second.makeFriend(p1);
	}
	
}

void summarizeGame(int gameID){
	map<int,Game>::iterator it_G;
	it_G = gameDatabase.find(gameID);
	int playerCounter = 0;
	int achieveCounter = 0;
	vector<Achievement> achieveList = it_G->second.getAchievementList();
	
	cout << "Players who play: " << it_G->second.getGameName() << endl;
	for (map<int,Player>::iterator it=playerDatabase.begin(); it!=playerDatabase.end(); ++it){
		if(it->second.hasGame(gameID)){
			cout << it->second.getPlayerName() << ", ";
			playerCounter++;
		}
		
	}
	cout << endl;
	
	cout << "Achievement Statistics: " << endl;
	for(int i=0;i<achieveList.size();i++){
		achieveCounter = 0;
		for (map<int,Player>::iterator it=playerDatabase.begin(); it!=playerDatabase.end(); ++it){
			int achieveID = achieveList[i].getAchieveID();
			int gameIndex=-1;
			vector<Game> playerGame = it->second.getGamesList();
			gameIndex = it->second.getGameIndex(gameID);
			if(gameIndex != -1){//make sure they have the game
				if(playerGame[gameIndex].hasAchievement(achieveID)){//check if they have the achievement
					achieveCounter++;
				}
			}
		}
		cout << i+1 << ". " << achieveList[i].getAchieveName() << setw(20) << achieveCounter
			 << "/" << playerCounter << endl;
	}
}

void summarizeAchievement(int gameID, int achieveID){
	map<int,Game>::iterator it_G;
	it_G = gameDatabase.find(gameID);
	int playerCounter = 0;
	int achieveCounter = 0;
	int counter = 1;
	vector<Achievement> achieveList = it_G->second.getAchievementList();
	
	for (map<int,Player>::iterator it=playerDatabase.begin(); it!=playerDatabase.end(); ++it){
		if(it->second.hasGame(gameID)){
			playerCounter++;
		}
		
	}
	cout << "Game: " << it_G->second.getGameName() << endl;
	cout << "Achievement Statistics: " << endl;
	cout << "Achievement Name: " << it_G->second.findAchievementName(achieveID) << endl;
	cout << "Players who obtained Achievement: " << endl;
	//achieveCounter = 0;
	for (map<int,Player>::iterator it=playerDatabase.begin(); it!=playerDatabase.end(); ++it){
		
		int gameIndex=-1;
		vector<Game> playerGame = it->second.getGamesList();
		gameIndex = it->second.getGameIndex(gameID);
		if(gameIndex != -1){//make sure they have the game
			if(playerGame[gameIndex].hasAchievement(achieveID)){//check if they have the achievement
				cout << counter << ". " << it->second.getPlayerName() << endl;
				achieveCounter++;
				counter++;
			}
		}
	}
	cout << "Completion percentage: " <<(1.0*achieveCounter/playerCounter)*100 <<"%";
	cout << endl;
	
	
}
bool playerSortFunction(Player p1, Player p2){ return p1.getGamerScore() > p2.getGamerScore(); }
void achievementRanking(){
	map<int,Player>::iterator it_P;
	//it_P = playerDatabase.find(playerID);
	vector<Player> playerID;//holds playerIDs for sorting
	for (map<int,Player>::iterator it=playerDatabase.begin(); it!=playerDatabase.end(); ++it){
		playerID.push_back(it->second);
	}
	
	sort(playerID.begin(),playerID.end(),playerSortFunction);
	cout << "Players" << setw(20) << "Gamerscore" << endl;
	cout << "-----------------------------------------------" << endl;
	for(int i=0;i<playerID.size();i++){
		cout << i+1 << ". " << playerID[i].getPlayerName() << setw(20) << playerID[i].getGamerScore() 
			 << " pts" << endl;
	}
	
}
void summarizePlayer(int gameID){
	map<int,Player>::iterator it_P;
	map<int,Game>::iterator it_G;
	it_G = gameDatabase.find(gameID);
	it_P = playerDatabase.find(gameID);
	string achievementFraction;//holds the fraction of achievements completed, as a string
	string gamerScore;
	vector<Game> playerGameList = it_P->second.getGamesList();
	cout << setw(3) << left << " ";
	cout << setw(30) << left << "Game" << setw(20) << "Achievements" << setw(20) << "Gamerscore" << "IGN" << endl;
	cout << "-------------------------------------------------------------------------------------" << endl;
	//for (map<int,Player>::iterator it=playerDatabase.begin(); it!=playerDatabase.end(); ++it){
	for(int i=0;i<playerGameList.size();i++){
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
	
	//cout << it_P->first << " => " << it_P->second.getPlayerName() << '\n';
		
	//it_P->second.printGames();
	//it_P->second.printPlayerAchievements();
	//it_P->second.printFriends();
	//cout << "--------------------------------------" << endl;
	//}
}

void printMap(){
	for (map<int,Player>::iterator it=playerDatabase.begin(); it!=playerDatabase.end(); ++it){
		cout << it->first << " => " << it->second.getPlayerName() << '\n';
		
		it->second.printGames();
		it->second.printPlayerAchievements();
		it->second.printFriends();
		cout << "--------------------------------------" << endl;
	}
	cout << endl;
	for (map<int,Game>::iterator it=gameDatabase.begin(); it!=gameDatabase.end(); ++it){
		cout << it->first << " => " << it->second.getGameName() << '\n';
		//cout << "gameID: " << it->second.getGameID() << endl;
		it->second.printAchievements();
	}
}
