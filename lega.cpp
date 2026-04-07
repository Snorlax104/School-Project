#include <iostream>
#include <vector>
using namespace std;

class Player{

    string name;
    int credits, points;

public:
   
    Player(string n, int c, int p) {
        
        cout << "inserire il nome del giocatore: " << endl;
        cin >> name;
        
        credits = 100;
        points = 0;
    }

    int GetPoints() const;

};

class Lega {

    string name;
    vector<Player> players;
    vector<int> index;

public:

    Lega(string n) {

        cout << "inserire il nome della lega: " << endl;
        cin >> name;

    }

    void gestioneClassifica(const vector<Player>& players, vector<int>& index);

};

int main() {
    
    return 0;
}

int Player::GetPoints() const {

    return points;

}

void Lega::gestioneClassifica(const vector<Player>& players, vector<int>& index) {

    for (int i = 0; i < players.size(); i++) {
        
        if (players.size() == 0) {
            
            for (int f = 0; f < players.size(); f++) {

                if (f == 0) {

                    index.push_back(f);

                }
                else {

                    if(players[f].GetPoints() > players[f-1].GetPoints()){

                        int a = index[f-1];
                        index[f-1] = f;
                        index.push_back(a);

                    }
                    else {

                        index.push_back(f);

                    }

                }

            }

        }
        else {
                
            

        }

    }

}