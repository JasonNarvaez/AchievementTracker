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

void playsGame(int playerID, int gameID, string IGN);
void addPlayer(int playerID, string playerName);
void addGame(int gameID, string gameName);
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
			
			cin >> gameID >> achievementID;
			cout << command << " " << gameID << " " << achievementID << endl; 
			
			getline(cin,temp,'\"');//gets and discards the first quotation mark
			getline(cin,achievementName,'\"');//read entire string before the next quotation mark
			cin >> achievementValue;
			
			cout << "The achievement: " << achievementName << endl;
			cout << "The achievement Value: " << achievementValue << endl;
			cout << command << " " << gameID << " " << achievementID << " " << achievementName << " " << achievementValue<<endl;
			
			for (map<int,Game>::iterator it=gameDatabase.begin(); it!=gameDatabase.end(); ++it){
				if(it->first == gameID){
					it->second.addAchievement(achievementName, achievementValue, achievementID);
				}
				
			}
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
		}
		else if(command == "FriendsWhoPlay"){
			cin >> playerID >> gameID;
			cout << command <<" "<< playerID <<" "<< gameID << endl;
		}
		else if(command == "ComparePlayers"){
			int player1;
			int player2;
			cin >> player1 >> player2;
			cout << command << " " << player1 << " " << player2 << endl;
		}
		else if(command == "SummarizePlayer"){
			cin >> gameID;
			cout << command << " " << gameID << endl;
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
	printMap();

}



void playsGame(int playerID, int gameID, string IGN){
	
	
	for (map<int,Player>::iterator it=playerDatabase.begin(); it!=playerDatabase.end(); ++it){
		if(it->first == playerID){
			//it->second.addGame(playerID, gameID, IGN);
		}
	
	}
	
}

void addPlayer(int playerID, string playerName){
	Player newPlayer(playerName);
	playerDatabase.insert(pair<int,Player>(playerID,newPlayer));

}

void addGame(int gameID, string gameName){
	Game newGame(gameName);
	gameDatabase.insert(pair<int,Game>(gameID,newGame));

}

void printMap(){
	for (map<int,Player>::iterator it=playerDatabase.begin(); it!=playerDatabase.end(); ++it){
		cout << it->first << " => " << it->second.getName() << '\n';
	}
	cout << endl;
	for (map<int,Game>::iterator it=gameDatabase.begin(); it!=gameDatabase.end(); ++it){
		cout << it->first << " => " << it->second.getName() << '\n';
		it->second.printAchievements();
	}
}
