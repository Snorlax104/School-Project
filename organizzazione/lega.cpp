#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Player{

    string name;
    int credits, points;

    //affect the player when gather points by reducing or increasing the points of the player
    //might even istantly add or take points from the player
    vector<int> bonusmalus;

public:
   
    Player(string n, int c, int p) : name(n), credits(c), points(p) {}
    int GetPoints() const;

    void modifyPoints(int p);
    void addBonusMalus(int bm);

};

class Quest {

    //class where you can put some quests to assign to the players
    //with some specific methods we can put custom quests or even update quest regularly

};

class Lega {

    string name;
    vector<Player> players;

    Quest quests;

public:

    Lega() {

        cout << "inserire il nome della lega: " << endl;
        cin >> name;

        //temporary way to add players. we nead to upgrade this part once we'll use files as mass memory
        cout << "inserire il numero di giocatori: " << endl;
        int numPlayers;
        cin >> numPlayers;

            for (int i = 0; i < numPlayers; ++i) {
    
                string playerName;
                int credits, points;
    
                cout << "inserire il nome del giocatore: " << endl;
                cin >> playerName;
    
                cout << "inserire i crediti del giocatore: " << endl;
                cin >> credits;
    
                cout << "inserire i punti del giocatore: " << endl;
                cin >> points;
    
                players.emplace_back(playerName, credits, points);
    
            }

    }

    void gestioneClassifica();

};

void asta() {

    //get from the extern all the stdents/professors to create your team

}

int main() {

    Lega lega;

    lega.gestioneClassifica();
    
    return 0;
}

int Player::GetPoints() const {

    return points;

}

void Player::modifyPoints(int p){

    //used to change the points of each player due to the quests points affected by bonus and malus
    points += p;

}

void Player::addBonusMalus(int bm){

    bonusmalus.push_back(bm);

}

void Lega::gestioneClassifica() {

    sort(players.begin(), players.end(), [](const Player& a, const Player& b) {

        return a.GetPoints() > b.GetPoints();

    });

}
