#include"../Leag-Player.h"

using namespace __FANTASCUOLA_G2_LEAG__;

//#############################################################################
//#############################################################################

int Player::GetPoints() const {

    return _points;

}

int Player::GetCredits() const {

    return _credits;

}

void Player::modifyCredits(int c){

    //used to change the credits of each player due to the auction phase
    _credits += c;

}

void Player::modifyPoints(int p){

    //used to change the points of each player due to the quests points and influenced by bonus and malus
    _points += p;

}

void Player::addBonusMalus(int bm){

    _bonusmalus.push_back(bm);

}

//#############################################################################
//#############################################################################

void Lega::gestioneClassifica() {    
    
    sort(_players.begin(), _players.end(), [](const Player& a, const Player& b) {
        
        return a.GetPoints() > b.GetPoints();

    });

}

//#############################################################################
//#############################################################################

static void asta(const vector<Player>& players) {

    cout << "Asta in corso..." << endl;

    vector<string> name;

    for(string& n : name){

        cout << "Asta in corso per " << n << " inserire i crediti da offrire:" << endl;
        int coffer = 0, hoffer = 0, i = 0;
        string id;

        bool a = true;

        while(a){

            i++;

            if(i == players.size()) i = 0;

            if(players[i].GetName() == id) break;

            int f = -1;

            do{

                f++;
                if(f > 0) cout << "Offerta non valida, inserire un numero compreso tra 0 e " << players[i].GetCredits() << endl;

                cin >> coffer;

            }while(coffer < 0 || coffer > players[i].GetCredits());

            if(coffer > hoffer){

                hoffer = coffer;
                id = players[i].GetName();

            }

        }

        players[i].modifyCredits(-hoffer);
        players[i]._team.addMember(players[i]);

    }

}