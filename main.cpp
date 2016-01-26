#include <iostream>
#include <vector>
#include <regex>
#include <stdio.h>
#include <string>

#include "player.h"

using namespace std;

//Database PlayerDatabase();
map<int,Player> PlayerDatabase;
map<int,Game> GameDatabase;

void addPlayer(int PlayerID, string PlayerName);
void PrintMap();

int main(){
	string command;
	string PlayerName;
	string IGN;
	string GameName;
	string AchievementName;
	string temp;
	int GameID;
	int AchievementID;
	int PlayerID;
	int AchievementValue;
	cout << "Reading in input..." << endl;
	while(cin.good()){
		cin >> command;
		cout << "command: " << command << endl;
		
		if(command == "AddGame"){
			cin >> GameID;
			//getline(cin,GameName);
			getline(cin,temp,'\"');
			getline(cin,GameName,'\"');
			cout << command << " " << GameID << " " << GameName << endl;
		}
		else if(command == "AddAchievement"){
			string temp2;
			
			cin >> GameID >> AchievementID;
			cout << command << " " << GameID << " " << AchievementID << endl; 
			
			getline(cin,temp,'\"');//gets and discards the first quotation mark
			getline(cin,AchievementName,'\"');//read entire string before the next quotation mark
			cin >> AchievementValue;
			
			cout << "The achievement: " << AchievementName << endl;
			cout << "The achievement Value: " << AchievementValue << endl;
			cout << command << " " << GameID << " " << AchievementID << " " << AchievementName << " " << AchievementValue<<endl;
			cout << "--------------------------------------" << endl;
			
		}
		else if(command == "AddPlayer"){
			cin >> PlayerID;
			//getline(cin,PlayerName);
			getline(cin,temp,'\"');//gets and discards the first quotation mark
			getline(cin,PlayerName,'\"');
			cout << command << " " << PlayerID << " " << PlayerName << endl;
			/*
			size_t found;
			for(int i=0;i<2;i++){//get rid of quotation marks
				found = PlayerName.find("\"");
				if(found!=string::npos)
					PlayerName.replace(found,1,"");
			}
			*/
			addPlayer(PlayerID, PlayerName);
		}
		else if(command == "AddFriends"){
			int Player1;
			int Player2;
			cin >> Player1 >> Player2;
			cout << command << " " << Player1 << " " << Player2 << endl;
		}
		else if(command == "Plays"){
			cin >> PlayerID >> GameID;
			//getline(cin,IGN);
			getline(cin,temp,'\"');//gets and discards the first quotation mark
			getline(cin,IGN,'\"');
			cout << command << " " << PlayerID << " " << GameID << " " << IGN << endl;
		}
		else if(command == "Achieve"){
			cin>>PlayerID>>GameID>>AchievementID;
			cout << command << " " << PlayerID << " " << GameID << " " << AchievementID << endl;
		}
		else if(command == "FriendsWhoPlay"){
			cin >> PlayerID >> GameID;
			cout << command <<" "<< PlayerID <<" "<< GameID << endl;
		}
		else if(command == "ComparePlayers"){
			int Player1;
			int Player2;
			cin >> Player1 >> Player2;
			cout << command << " " << Player1 << " " << Player2 << endl;
		}
		else if(command == "SummarizePlayer"){
			cin >> GameID;
			cout << command << " " << GameID << endl;
		}
		else if(command == "SummarizeAchievement"){
			cin >> GameID >> AchievementID;
			cout << command << " " << GameID << " " << AchievementID << endl;
		}
		else if(command == "AchievementRanking"){
			cout << command << endl;
		}
		else{
			cout << "command not recognized: " << command<< endl;
		}
		
	}
	PrintMap();

}

void addPlayer(int PlayerID, string PlayerName){
	Player NewPlayer(PlayerName);
	PlayerDatabase.insert(pair<int,Player>(PlayerID,NewPlayer));

}

void addGame(int GameID, string GameName){
	//Player NewPlayer(PlayerName);
	//PlayerDatabase.insert(pair<int,Player>(PlayerID,NewPlayer));

}

void PrintMap(){
	for (map<int,Player>::iterator it=PlayerDatabase.begin(); it!=PlayerDatabase.end(); ++it){
		cout << it->first << " => " << it->second.get_name() << '\n';
	}
}
void AddGame(int GameID, string GameName){
	
}