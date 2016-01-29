#include <iostream>
#include <vector>
#include <regex>
#include <stdio.h>
#include <string>

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
void summarizePlayer(int gameID);
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
		else if(command == "SummarizeAchievement"){
			cin >> gameID >> achievementID;
			cout << command << " " << gameID << " " << achievementID << endl;
		}
		else if(command == "AchievementRanking"){
			cout << command << endl;
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
	string achieveP1;
	string achieveP2;
	
	it_P1 = playerDatabase.find(playerID1);
	it_P2 = playerDatabase.find(playerID2);
	it_G = gameDatabase.find(gameID);
	Game gameP1 = it_P1->second.findPlayerGame(gameID);
	Game gameP2 = it_P2->second.findPlayerGame(gameID);
	//cout << "Bill achievements:" <<endl;
	//it_P1->second.findPlayerGame(gameID).printAchievements();
	//gameP1.printAchievements();
	//cout << "Andruid achievements:" <<endl;
	//it_P2->second.findPlayerGame(gameID).printAchievements();
	//gameP2.printAchievements();
	fullAchievementList = it_G->second.getAchievementList();
	cout << "Game: " << it_G->second.getGameName() << endl;
	cout << "\t\t\t\t" << it_P1->second.getPlayerName() << "\t\t\t\t" << it_P2->second.getPlayerName() << endl;
	for(int i=0;i<fullAchievementList.size();i++){
		achieveID = fullAchievementList[i].getAchieveID();
		achieveValue = fullAchievementList[i].getAchieveValue();
		achieveP1 = gameP1.findAchievementName(achieveID);
		//cout << "achieveID: " << achieveID << endl;
		cout << "Achievement: " << fullAchievementList[i].getAchieveName() << "\t";
		
		//cout << gameP1.findAchievementName(achieveID) << "\t\t\t\t";
		
		//cout << "Bill achievement 1: " << achieveP1 << "\t\t\t\t";
		if(!achieveP1.empty()){
			cout << achieveValue;
			cout << "\t\t\t\t";
		}
		else {
			cout << "--";
			cout << "\t\t\t\t";
		}
		if(!gameP2.findAchievementName(achieveID).empty()){
			cout << achieveValue;
			cout << "\t\t\t\t";
		}
		else {
			cout << "--";
			cout << "\t\t\t\t";
		}
			
		cout << endl;
	}
	
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

void summarizePlayer(int gameID){
	map<int,Player>::iterator it_P;
	it_P = playerDatabase.find(gameID);
	
	//for (map<int,Player>::iterator it=playerDatabase.begin(); it!=playerDatabase.end(); ++it){
		cout << it_P->first << " => " << it_P->second.getPlayerName() << '\n';
		
		it_P->second.printGames();
		it_P->second.printPlayerAchievements();
		it_P->second.printFriends();
		cout << "--------------------------------------" << endl;
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
