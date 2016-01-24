#include <iostream>
#include <vector>

using namespace std;

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
	cout<<"Reading in input..."<<endl;
	while(cin.good()){
		cin>>command;
		cout<<"command: "<<command<<endl;
		
		if(command == "AddGame"){
			cin>>GameID;
			getline(cin,GameName);
			cout<<command<<" "<<GameID<<" "<<GameName<<endl;
		}
		else if(command == "AddAchievement"){
			cin>>GameID>>AchievementID;
			getline(cin,temp);
			int pos1;
			int pos2;
			/* 
			for(int i=0;i<temp.size();i++){
				if(temp[i] == "\"" && i>0)
					pos2 = i;
				else if(temp[i] == "\""&& i==0)
					pos1 = i;
			}
			AchievementName = temp.substr(pos1,pos2);
			 */
		}
		else if(command == "AddPlayer"){
			cin>>PlayerID;
			getline(cin,PlayerName);
			cout<<command<<" "<<PlayerID<<" "<<PlayerName<<endl;
			
		}
		else if(command == "AddFriends"){
			int Player1;
			int Player2;
			cin>>Player1>>Player2;
			cout<<command<<" "<<Player1<<" "<<Player2<<endl;
		}
		else if(command == "Plays"){
			cin>>PlayerID>>GameID;
			getline(cin,IGN);
			cout<<command<<" "<<PlayerID<<" "<<GameID<<" "<<IGN<<endl;
		}
		else if(command == "Achieve"){
			cin>>PlayerID>>GameID>>AchievementID;
			cout<<command<<" "<<PlayerID<<" "<<GameID<<" "<<AchievementID<<endl;
		}
		else if(command == "FriendsWhoPlay"){
			cin>>PlayerID>>GameID;
			cout<<command<<" "<<PlayerID<<" "<<GameID<<endl;
		}
		else if(command == "ComparePlayers"){
			int Player1;
			int Player2;
			cin>>Player1>>Player2;
			cout<<command<<" "<<Player1<<" "<<Player2<<endl;
		}
		else if(command == "SummarizePlayer"){
			cin>>GameID;
			cout<<command<<" "<<GameID<<endl;
		}
		else if(command == "SummarizeAchievement"){
			cin>>GameID>>AchievementID;
			cout<<command<<" "<<GameID<<" "<<AchievementID<<endl;
		}
		else if(command == "AchievementRanking"){
			cout<<command<<endl;
		}
		else{
			cout<<"command not recognized."<<endl;
		}
		
	}

}

void Addplayer(){


}
void AddGame(int GameID, string GameName){
	
}