#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

#include "../gruppo3/main.h"

namespace __FANTASCUOLA_G2_LEAG__ {

    using std::string;
    using std::vector;

    using std::cout;
    using std::endl;

    using __FANTASCUOLA_G3_TEAM__::Team;

    class Player{

        string _name;
        int _credits, _points;

        Team _team;

        vector<int> _bonusmalus;

    public:
    
        Player() {} //constructor to create a player with name, credits and points
        //should get the parameters from a memory organization method

         Player(string name, int credits, int points) //Serve quando si ricarica dal JSON: il Serializer legge nome, crediti e punti dal file e ricostruisce un Player con quei valori. 
        : _name(name), _credits(credits), _points(points) {}

        ~Player() {} //destructor
        
        int GetPoints() const;
        int GetCredits() const; //to get the credits of the player, to be used in the auction phase

        void modifyPoints(int p);
        void modifyCredits(int c); //to modify the credits of the player, to be used in the auction phase
        void addBonusMalus(int bm);

         string GetName() const { return _name; } //restituisce il nome del player
         const Team& getTeam() const { return _team; } //restituisce il nome del team
        
        friend void asta(const vector<Player>& players);

    };

    class Lega {

        string _name;
        vector<Player> _players;

    public:

        Lega() {} //builder, nead to be implemented when everything is done properly
        ~Lega() {} //destructor

        void gestioneClassifica();

    };

}
