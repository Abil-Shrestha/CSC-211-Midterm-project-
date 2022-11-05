//
// Created by Abil Shrestha on 10/28/2022.
//
#include "Player.h"
#include<iostream>
#include<string>
#include<iomanip>
#include <cmath>
using namespace std;

int Player::getAge() const {
    return age;
}
void Player::setAge(int age) {
    while(true){
        if(age <18 || cin.fail() ||cin.bad()|| age >35){ //error handling
            cout<<"Please enter valid age for "<<this->getName()<<":  ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin>> age;
        }
        break;
    }

    this->age = age;
}
double Player::getKda() const {
    return kda;
}
void Player::setKda(double kda) {

        while(kda <0 || cin.fail() ||cin.bad()|| kda > 10 ){//error handling
            cout<<"Please enter valid kda for "<<this->getName()<<" (0 to 10) :";
            cin.clear();
            cin.ignore(10000, '\n');
            cin>> kda;
        }

    this->kda = kda;
}
double Player::getCsd() const {
    return csd;
}
void Player::setCsd(double csd) {
        while(csd <0 || cin.fail()||cin.bad()|| csd > 20) {//error handling
            cout << "Please enter valid csd for " << this->getName() << " (0 to 20) :";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> csd;
        }
    this->csd = csd;
}
int Player::getHighestKills() const {
    return highestKills;
}
void Player::setHighestKills(int highestKills) {//error handling
        while(highestKills <0 || cin.fail() ||cin.bad()|| highestKills > 40 ) {
            cout << "Please enter valid highestKills for " << this->getName() << " (0 to 40) :";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> highestKills;
        }
    this->highestKills = highestKills;
}
double Player::getFirstBloodRate() const {
    return firstBloodRate;
}
void Player::setFirstBloodRate(double firstBloodRate) {
        while(firstBloodRate < 0 || cin.fail() ||cin.bad()|| firstBloodRate > 100 ){//error handling
            cout<<"Please enter valid firstBloodRate for "<<this->getName() <<" (0 to 100) : ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin>> firstBloodRate;
        }
    this->firstBloodRate = firstBloodRate;
}
double Player::getAverageDeaths() const {
    return averageDeaths;
}
void Player::setAverageDeaths(double averageDeaths) {
        while(averageDeaths < 0 || cin.fail() ||cin.bad()|| averageDeaths > 50){//error handling
            cout<<"Please enter valid averageDeaths for "<<this->getName()<<" (0 to 50) : ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin>> averageDeaths;
        }
    this->averageDeaths = averageDeaths;
}
Player::Player(string team,string name,int age,double kda,double csd,int highestKills,double firstBloodRate,double averageDeaths) {
    this->setTeam(team);
    this->setAge(age);
    this->setName(name);
    this->setKda(kda);
    this->setCsd(csd);
    this->setHighestKills(highestKills);
    this->setFirstBloodRate(firstBloodRate);
    this->setAverageDeaths(averageDeaths);
}
string &Player::getName(){
    return name;
}
void Player::setName(const string &name) {
    this->name = name;
}
string &Player::getTeam() {
    return team;
}
void Player::setTeam(const string team) {
    this->team = team;
}
void Player::printData() const {
    cout<<team<<setw(15)<<name<<setw(10)<<age<<setw(10)<<fixed<<setprecision(1)<<kda<<"\t"<<csd<<setw(5)<<highestKills<<fixed<<setprecision(0)<<setw(15)<<firstBloodRate<<"%"<<setw(15)<<averageDeaths<<endl;
}
Player::~Player() {

}