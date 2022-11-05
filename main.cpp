//Abil Shrestha - Midterm project for CSC 211 (Prof. Anthony Catalano)
#include "Player.h"
#include <iostream>
#include <vector>
#include <fstream>
#include<iomanip>
#include<algorithm>
#include <sstream>

using namespace std;
void showMenu(); //funtion for showing menu
void readData(vector<Player>* PlayerStats); //function for reading data
void writeData(vector<Player>* updatePlayerStats); // function prototype for writing data
void showPlayers(); // function prototype for showing players
void showSpecificPlayer(); //function prototype for showing specific players
void showSpecificTeam();//function prototype for showing specific team
void updateDataForPlayer();//function prototype for updating players stats
void addNewPlayer();//function prototype for adding new player
void addData( vector<Player>* addPlayerStats); //function prototype for adding data
void exportFile(); // function prototype for exporting file
string removeSpecialCharacter(string s);//function prototype for removing special characters from a string

int main() {
    cout<<setw(40)<<"\t\t\t\tHi Welcome to the League Of Legends Stat-Checking App"<<endl;
    char option;
    do{
        showMenu();//Function to Show the main menu
        OPT:
        cin>>option; //Taking input from user
        if(cin.fail() || cin.bad()){ //error handling
            cout<<"Invalid Input! Please try again. "<<endl;
            cin.clear();
            cin.ignore(10000, '\n');
            goto OPT;
        }
        switch(option) {
            case '1':
                showPlayers();
                break;
            case '2': {
                showSpecificPlayer();
                break;
            }
            case '3': {
                showSpecificTeam();
                break;
            }
            case '4':{
                updateDataForPlayer();
                break;
            }
            case '5':{
                addNewPlayer();
                break;
            }
            case '6':{
                exportFile();
                break;
            }
            case'0':{
                cout<<"Thank you for using this app."<<endl;
                break;
            }
            default:{
                cout<<"Invalid Input! Please try again"<<endl;
                break;
            };
        }
    } while (option != '0');
}
void showMenu(){
    cout<<"\n"<<endl;
    cout<<"\t\t\t\t\tMenu"<<endl;
    cout<<endl;
    cout<<"1 Show all the players"<<endl;
    cout<<"2 Show Statistics for a specific player"<<endl;
    cout<<"3 Show Statistics for a specific team"<<endl;
    cout<<"4 Update data for a specific player"<<endl;
    cout<<"5 Input a New player "<<endl;
    cout<<"6 Export data to the output file"<<endl;
    cout<<"0 Exit"<<endl;
    cout<<"Type in the number of option you want to choose :  "<<endl;
}
void readData( vector<Player>* PlayerStats){
    string name,team;
    int age,highestKills,averageDeaths;
    double kda,csd,firstBloodRate;
    ifstream Players;
    Players.open("playerStats.txt",ios::in);
    if(Players.fail()|| Players.bad()){
        cerr<<"Failed to open file "<<endl;
    }
    if(Players.is_open()){
        while(!Players.eof()){
            if(Players.fail()){
                cerr<<"File error "<<endl;
                break;
            }
            Players>>team;
            Players>>name>>age>>kda>>csd>>highestKills>>firstBloodRate>>averageDeaths;
            Player PlayersObject(team,name,age,kda,csd,highestKills,firstBloodRate,averageDeaths); // creating PlayerObject using constructor
            PlayerStats->push_back(PlayersObject); // storing PlayerObject on vector
        }
        Players.clear();
        Players.close();
    }
}
void writeData( vector<Player>* updatePlayerStats){
    fstream Playersout;
    Playersout.open("playerStats.txt", ios::out);
    if(Playersout.fail()){
        cerr<<"Failed to open file "<<endl;
    }
    if(Playersout.is_open()){
        for(int i = 0; i< updatePlayerStats->size()-1;i++){ // loop to write files to output file
            Playersout<<updatePlayerStats->at(i).getTeam()<<setw(15)<<updatePlayerStats->at(i).getName()<<setw(15)<<updatePlayerStats->at(i).getAge()<<setw(10)<<updatePlayerStats->at(i).getKda()<<setw(10)<<updatePlayerStats->at(i).getCsd()<<setw(10)<<updatePlayerStats->at(i).getHighestKills()<<setw(10)<<updatePlayerStats->at(i).getFirstBloodRate()<<setw(10)<<updatePlayerStats->at(i).getAverageDeaths()<<endl; // using Class function to get Data
        }
        Playersout.clear();
        Playersout.close();
    }

}
void addData( vector<Player>* addPlayerStats){
    fstream Playersout;
    Playersout.open("playerStats.txt",ios::out);
    if(Playersout.fail()){
        cerr<<"Failed to open file "<<endl;
    }
    if(Playersout.is_open()){
        for(int i = 0; i< addPlayerStats->size()-1;i++){ // loop to write files to output file
            Playersout<<addPlayerStats->at(i).getTeam()<<"\t"<<addPlayerStats->at(i).getName()<<"\t"<<addPlayerStats->at(i).getAge()<<"\t"<<addPlayerStats->at(i).getKda()<<"\t"<<addPlayerStats->at(i).getCsd()<<"\t"<<addPlayerStats->at(i).getHighestKills()<<"\t"<<addPlayerStats->at(i).getFirstBloodRate()<<"\t"<<addPlayerStats->at(i).getAverageDeaths()<<endl; // using Class function to get Data
        }
        Playersout.clear();
        Playersout.close();
    }

}
void showPlayers(){
    vector<Player> PlayerStats;//Vector to store all the Player Objects
    readData( &PlayerStats ); //Function to read data from file and store in vector
    cout<<"Team"<<setw(12)<<"Name"<<setw(12)<<"Age"<<setw(9)<<"KDA"<<setw(6)<<"CSD"<<setw(17)<<"Highest Kills"<<setw(15)<<"FirstBloodRate"<<setw(15)<<"Average Deaths"<<endl;
    for(int i = 0; i< PlayerStats.size()-1;i++){
        PlayerStats[i].printData();//Class Function to print Data
    }
}
void showSpecificPlayer(){
    vector<Player> PlayerStats;//Vector to store all the Player Objects
    readData( &PlayerStats ); //Function to read data from file and store in vector
    string playerNames;
    bool found = false; // boolean to keep tack if the player exists or not
    cout << "Enter the Name of the player" << endl;
    cin.ignore();
    getline(cin,playerNames);
    if(cin.fail()||cin.bad()){ //error handling
        cout<<"Invalid input!"<<endl;
    }
    //Converting input string to uppercase to compare with the name in file.
    transform(playerNames.begin(), playerNames.end(),playerNames.begin(), ::toupper);
    for (int i = 0; i < PlayerStats.size()-1; i++) {
        if (playerNames == PlayerStats[i].getName()) {
            cout<<"Team"<<setw(12)<<"Name"<<setw(12)<<"Age"<<setw(9)<<"KDA"<<setw(6)<<"CSD"<<setw(17)<<"Highest Kills"<<setw(15)<<"FirstBloodRate"<<setw(15)<<"Average Deaths"<<endl;
            PlayerStats[i].printData();//Function from class
            found = true;
        }
    }
    if (found == true) {
        found = true;
    } else
        cout << "Player Not found." << endl;
}
void showSpecificTeam(){
    vector<Player> teamStats;//Vector to store all the Player Objects
    readData( &teamStats );//Function to read data from file and store in vector
    string playerTeam;
    bool found = false;//Boolean to keep track if the team exists or not.
    cout << "Enter the Name of the team " << endl;
    cin.ignore();
    getline(cin,playerTeam);
    if(cin.fail()||cin.bad()){ //error handling
        cout<<"Invalid input!"<<endl;
    }
    //Converting string to Uppercase to compare with the team name in text file.
    transform(playerTeam.begin(), playerTeam.end(),playerTeam.begin(), ::toupper);
    for (int i = 0; i < teamStats.size()-1; i++) { // Loop to check if the team exist
        if (playerTeam == (teamStats[i].getTeam())) {
            found = true;
            break;
        }
    }
        cout<<"Team"<<setw(12)<<"Name"<<setw(12)<<"Age"<<setw(9)<<"KDA"<<setw(6)<<"CSD"<<setw(17)<<"Highest Kills"<<setw(15)<<"FirstBloodRate"<<setw(15)<<"Average Deaths"<<endl;
        string str1 = playerTeam;
        for (int i = 0; i < teamStats.size(); i++) {
            string str2 = teamStats[i].getTeam();
            if(str1 == str2){
                teamStats.at(i).printData();
            }
        }
        if (found == false ){
            cout<<"Team not found. Please try again!"<<endl;
        }
}
void updateDataForPlayer(){
    vector<Player> updatePlayerStats;//Vector to store all the Player Objects
    readData( &updatePlayerStats );//Function to read data from file and store in vector
    string name,team;
    int age,highestKills;
    double kda,csd,firstBloodRate,averageDeaths;
    string playerName;
    bool madeChanges = false; // boolean to keep track if changes made or not
    cout<<"Type the name of the player you want to update stats for : ";
    cin.ignore();
    getline(cin,playerName);
    //Converting string to Uppercase to compare with the team name in text file.
    transform(playerName.begin(), playerName.end(),playerName.begin(), ::toupper);
    for (int i = 0; i < updatePlayerStats.size()-1; i++) {
        if (playerName == (updatePlayerStats[i].getName())) {
          AGE:  
          cout<<"Enter Age for "<<updatePlayerStats[i].getName()<< " :  ";
          string spaces;//local variable
          stringstream stringStream; 
          cin>>age;
          while(cin.fail() || cin.bad() || age<18 || age>35){ //error handling
              cout<<"Invalid Input! Please enter valid age ( 18 to 35). "<<endl;
              cin.clear();
              cin.ignore(10000, '\n');
            cout<<"Enter the age for the player: ";
            cin>>age;
          }
            updatePlayerStats[i].setAge(age); //setting age
            cout<<"Enter KDA (Kills Deaths Average):  ";
            KDA:
           cin>>kda;
            while(cin.fail() || cin.bad()){ //error handling
                cout<<"Please enter valid kda for "<<updatePlayerStats[i].getName()<<" (0 to 10) : ";
                cin.clear();
                cin.ignore(10000, '\n');
                cin>>kda;
            }
            updatePlayerStats[i].setKda(kda); //setting kda 
            cout<<"Enter CSD (Creep Score Difference) :  ";
            CSD:
            cin>>csd;
            while(cin.fail() || cin.bad()){ //error handling
                cout<<"Please enter valid csd for "<<updatePlayerStats[i].getName()<<" (0 to 20) : ";
                cin.clear();
                cin.ignore(10000, '\n');
                cin>>csd;
            }
            updatePlayerStats[i].setCsd(csd); //setting csd
            HK:
            cout<<"Enter Highest Kills :  ";
            cin>>highestKills;
            while(cin.fail() || cin.bad()){ //error handling
                cout<<"Please enter valid highestKills for " << updatePlayerStats[i].getName() << " (0 to 40) :  ";
                cin.clear();
                cin.ignore(10000, '\n');
                cin>>highestKills;
            }
            updatePlayerStats[i].setHighestKills(highestKills); //setting highest kills
            FBR:
            cout<<" Enter First Blood Rate :  ";
            cin>>firstBloodRate;
            while(cin.fail() || cin.bad()){ //error handling
                cout<<"Please enter valid firstBloodRate for "<<updatePlayerStats[i].getName() <<" (0 to 100) :  ";
                cin.clear();
                cin.ignore(10000, '\n');
                cin>>firstBloodRate;
            }
            updatePlayerStats[i].setFirstBloodRate(firstBloodRate); //setting firstblood rate
            AD:
            cout<<"Enter Average Deaths :  ";
            cin>>averageDeaths;
            while(cin.fail() || cin.bad()){ //error handling
                cout<<"Please enter valid averageDeaths for "<<updatePlayerStats[i].getName()<<" (0 to 50) :  ";
                cin.clear();
                cin.ignore(10000, '\n');
                cin>>averageDeaths;
            }
            updatePlayerStats[i].setAverageDeaths(averageDeaths); //setting average deaths
            madeChanges = true;
            string player = updatePlayerStats[i].getName(); //storing name of the player
            cout<<"Stats for "<<player<< " Changed successfully."<<endl;
        }
    }

    if(madeChanges == true ){
        writeData( &updatePlayerStats );
    }else {
        cout<<"Player not found, Please try again."<<endl;
    }
}
void addNewPlayer(){
    vector<Player> addPlayerStats;//Vector to store all the Player Objects
    readData( &addPlayerStats );//Function to read data from file and store in vector
    string name,team; //local variables
    int age,highestKills; //local variables
    double kda,csd,firstBloodRate,averageDeaths;//local variables
    Player PlayerObject;
    PN:
    cout<<"Enter the team for the player: "<<endl; //returning here if input fails
    cin.ignore();
    getline(cin,team);
  remove(team.begin(), team.end(), ' '); // removing whitespaces from input 
  team = removeSpecialCharacter(team); // removing special characters from input
    while(cin.fail() || cin.bad()){ //error handling
        cout<<"Invalid Input! Please try again."<<endl;
        cin.clear();
        cin.ignore();
        cout<<"Please enter valid team for the player: ";
        getline(cin,team);
      remove(team.begin(), team.end(), ' '); // removing whitespaces from input 
    }
    while(team.size()>8){ //char length handling
      cout<<"Team name can't be greater than 8 characters!"<<endl;
        cin.clear();
        cout<<"Please enter valid team for the player: ";
        cin.ignore();
        getline(cin,team);
      remove(team.begin(), team.end(), ' '); // removing whitespaces from input 
    }
    transform(team.begin(), team.end(),team.begin(), ::toupper);//Converting string to Uppercase
    PlayerObject.setTeam(team); //using setter function
    cout<<"Enter the name for the player: "<<endl;
    NAME:
    getline(cin,name);
    remove(name.begin(), name.end(), ' '); // removing whitespaces from input
    name = removeSpecialCharacter(name); // removing special characters from name
    if(cin.fail() || cin.bad()) { //error handling
        cout << "Invalid Input! Please try again. " << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        goto NAME;
    }
  while(name.size()>11){ //char length handling
      cout<<"Player name can't be greater than 11 characters!"<<endl;
        cin.clear();
        cout<<"Please enter valid name for the player: ";
        cin.ignore();
        getline(cin,name);
    remove(name.begin(), name.end(), ' '); // removing whitespaces from input 
    }
    transform(name.begin(), name.end(),name.begin(), ::toupper);//Converting string to Uppercase
    PlayerObject.setName(name);
  AGE:
    cout<<"Enter the age for the player: "<<endl;
    cin>>age;
    while(cin.fail() || cin.bad() || age <18 || age > 35){ //error handling
        cout<<"Invalid Input! Please enter valid age ( 18 to 35). "<<endl;
        cin.clear();
        cin.ignore(10000, '\n');
      cout<<"Enter valid the age for the player: ";
      cin>>age;
    }
    PlayerObject.setAge(age);
    KDA:
    cout<<"Enter KDA (Kills Deaths Average) : "<<endl; 
    cin>>kda;
    while(cin.fail() || cin.bad()){ //error handling
        cout<<"Invalid Input! Please try again. "<<endl;
        cin.clear();
        cin.ignore(10000, '\n');
        cout<<"Enter valid KDA for the player (0 to 10):";
        cin>>kda;
    }
    PlayerObject.setKda(kda);
    CSD:
    cout<<"Enter CSD (Creep Score Difference) : "<<endl;
    cin>>csd;
    while(cin.fail() || cin.bad()){ //error handling
        cout<<"Invalid Input! Please try again. "<<endl;
        cin.clear();
        cin.ignore(10000, '\n');
        cout<<"Enter valid CSD for the player (0 to 20) :";
        cin>>csd;
    }
    PlayerObject.setCsd(csd);
    HK:
    cout<<"Enter highest Kills : "<<endl;
    cin>>highestKills;
    while(cin.fail() || cin.bad()){ //error handling
        cout<<"Invalid Input! Please try again. "<<endl;
        cin.clear();
        cin.ignore(10000, '\n');
        cout<<"Enter valid highestKills for the player (0 to 40) :";
        cin>>highestKills;
    }
    PlayerObject.setHighestKills(highestKills);
    FBR:
    cout<<"Enter First Blood Rate :"<<endl;
    cin>>firstBloodRate;
    while(cin.fail() || cin.bad()){ //error handling
        cout<<"Invalid Input! Please try again. "<<endl;
        cin.clear();
        cin.ignore(10000, '\n');
        cout<<"Enter valid firstBloodRate for the player (0 to 100) :";
        cin>>firstBloodRate;
    }
    PlayerObject.setFirstBloodRate(firstBloodRate);
    cout<<"Enter Average Deaths : "<<endl;
    AD:
    cin>>averageDeaths;
    while(cin.fail() || cin.bad()){ //error handling
        cout<<"Invalid Input! Please try again. "<<endl;
        cin.clear();
        cin.ignore(10000, '\n');
        cout<<"Enter valid averageDeaths for the player (0 to 50) :";
        cin>>averageDeaths;
    }
    PlayerObject.setAverageDeaths(averageDeaths);
    addPlayerStats.insert(addPlayerStats.begin(),PlayerObject); // placing new player object to the front of vector
    addData( &addPlayerStats ); // updating file with new player
    cout<<"New Player "<<PlayerObject.getName()<< " created successfully."<<endl;
}
void exportFile(){
  vector<Player> exportStats;
                readData(&exportStats);
                writeData(&exportStats);
                cout<<"File Exported successfully !"<<endl;
}
string removeSpecialCharacter(string s){
    for (int i = 0; i < s.size(); i++) {
        // Finding the character whose
        // ASCII value fall under this
        // range
        if (s[i] < 'A' || s[i] > 'Z' &&
            s[i] < 'a' || s[i] > 'z')
        {  
            // erase function to erase
            // the special character from the string
            s.erase(i, 1);
            i--;
        }
    }
    return s;
}