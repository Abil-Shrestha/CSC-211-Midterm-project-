
#ifndef MIDTERM_CSC211_PLAYER_H
#define MIDTERM_CSC211_PLAYER_H
#include<string>
using namespace std;

class Player {
public:
    //Default Constructor
    Player() = default;
    //Copy Constructor
    Player(string team,string name,int age,double kda,double csd,int highestKills,double firstBloodRate,double averageDeaths);
    //Destructor
    ~Player();
    //Getter functions
    int getAge() const;
    double getKda() const;
    double getCsd() const;
    double getAverageDeaths() const;
    double getFirstBloodRate() const;
    int getHighestKills() const;
    string &getName();
    string &getTeam() ;
    void printData() const;

    //Setter functions
    void setAge(int age);
    void setKda(double kda);
    void setCsd(double csd);
    void setHighestKills(int highestKills);
    void setFirstBloodRate(double firstBloodRate);
    void setAverageDeaths(double averageDeaths);
    void setName(const string &name);
    void setTeam(const string team);
private:
    double csd{};//Csd = Creep Score Difference
    int highestKills{};
    double firstBloodRate{};
    double averageDeaths{};
    double kda{};//Kill, Deaths & Assists
    int age{};
    string name,team;
};


#endif //MIDTERM_CSC211_PLAYER_H
