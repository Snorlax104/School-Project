/*
TO DO:
    classe quests da fare in modo da avere le quest separate
    sistemare le classi e funzioni in modo che siano compatibili e utilizzabili
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>

#include"class_definitions.h"

using namespace std;

using namespace __FANTASQUOLA_CLSS_DEF__;

const int numero_b=13;
const int numero_m=11;
const int numero_q=10;

class Player{

    string name;
    int credits;
    Storico points;

    //affect the player when gather points by reducing or increasing the points of the player
    //might even istantly add or take points from the player
    vector<int> bonusmalus;

public:
   
    Player(string n, int c, int p) : name(n), credits(c) {}
    int GetPoints() const;

};

class Lega {

    string name;
    vector<Player> players;

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

class Punteggi{
    protected:
        double punteggio_;
        
    public:
        Punteggi();
        void stampabonus(int numero);
        double aggiornaPunteggioBonus(int numero);
        void stampamalus(int numero);
        double aggiornaPunteggioMalus(int numero);
        void stampquest(int numero);
        double aggiornaPunteggioQuest(int numero);
        double getpunteggio();
        void ArrontondaPunteggio();

        string bonus_desc[numero_b] = {
            "Prende 10",
            "Buona Interrogazione", //almeno 7
            "Aiuta un compagno",
            "Consegna tutto in orario",
            "Prende un +",
            "Risponde sempre in classe",
            "Progetto eccellente",
            "Nessuna assenza nella settimana",
            "Partecipa attivamente",
            "Vince una gara scolastica",
            "Prende 9",
            "Prende 8", 
            "Consegna tutto in anticipo"
        };

        double bonus_val[numero_b] = {
            3.0, 1.3, 1.5, 1.7, 1.6,
            1.4, 2.2, 1.3, 1.2, 2.5,
            2.0, 1.5, 2.0
        };

        // MALUS: [azione, moltiplicatore]
        string malus_desc[numero_m] = {
            "Prende 2 in informatica",
            "Non fa i compiti",
            "Nota",
            "Disturba la lezione",
            "Arriva in ritardo",
            "Dimentica il materiale",
            "Insufficienza grave", //prende 4 o meno
            "Salta interrogazione",
            "Uso del telefono in classe",
            "Assenza ingiustificata",
            "insufficenza media" //prende più di 4 e meno di 6
        };

        double malus_val[numero_m] = {
            0.5, 0.7, 0.6, 0.8, 0.9,
            0.85, 0.6, 0.75, 0.7, 0.65,
            0.8

        };

        // QUEST: [missione, punteggio]
        string quest_desc[numero_q] = {
            "Prendere 6 e 7 nello stesso giorno",
            "Zero insufficienze in una settimana",
            "Alzare la media in una materia",
            "Essere interrogato 3 volte in una settimana",
            "Fare i compiti per 5 di seguito",
            "Prendere almeno un 9",
            "Nessuna nota per 2 settimane",
            "Fai 67 alla prof di inglese",
            "Partecipare a un progetto",
            "Recuperare un'insufficienza"
        };

        double quest_points[numero_q] = {
            30.0, 15.0, 20.0, 12.0, 10.0,
            18.0, 25.0, 14.0, 16.0, 22.0
        };

};

//#############################################################################
//#############################################################################


Participant::Participant(string name):
	_name(name)
{}

Participant::~Participant() {

}

string Participant::name() {
	return _name;
}

// clacola i punti totali del partecipante
// momentaneamente ritorna sempre il valore 1
SCORE Participant::score() {
	return 1;
}




//#############################################################################
//#############################################################################

// Costruttore di base, chiede solamente il valore della squadra
Team::Team(string name) :
	_name(name)
{}

// costruttore secondario, accetta un vettore di partecipanti per l'inizializzazione
Team::Team(string name, vector<Participant> members) :
	Team(name) // delega al costruttore di base per evitare duplicazione del codice
{
	_members = std::move(members); // muove i contenuti del vector temporaneo in quello permanente
}

// Funzione per inserire un nuovo partecipante nella lista 
void Team::addMember(const Participant& member) {
	_members.push_back(member);
}
// Funzione per visualizzare i dati a schermo 
void Team::displayCLI() {
	cout << "Team: " << _name << " | Pts: " << score() << endl;
	cout << "Members:" << endl;
	// Ciclo che stampa solo i nomi effettivamente aggiunti 
	for (Participant& member : _members) {
		cout << " - " << member.name() << ", Pts:" << member.score() << endl;
	}
}

SCORE Team::score() {
	SCORE score = 0;
	for (Participant& member : _members)
		score += member.score();
	return score;
}

//################################################################################################

class Storico : public Punteggi {
    private:
        vector<double> storico;  
        int counterposition = 0; // Contatore per la posizione nel vettore Storico

    public:
        Storico();
        double aggiornaPunteggioBonus(int numero);
        double aggiornaPunteggioMalus(int numero);
        double aggiornaPunteggioQuest(int numero);
        void getstorico();
};

//################################################################################################

int numerorandomquest();

void asta() {

    //get from the extern all the stdents/professors to create your team

}

int main() {

    Lega lega;

    lega.gestioneClassifica();
    
    return 0;
}

void Lega::gestioneClassifica() {

    sort(players.begin(), players.end(), [](const Player& a, const Player& b) {

        return a.GetPoints() > b.GetPoints();

    });

}

int numerorandomquest() 
{
    return rand() % 10; // Genera un numero casuale tra 0 e 9
}

//###############################################################################################

// Implementazione dei metodi della classe Punteggi

Punteggi::Punteggi() {
    punteggio_ = 0; // Inizializza il punteggio a 0
}

void Punteggi::stampabonus(int numero) {
    cout << "Bonus: " << bonus_desc[numero] << " (x" << bonus_val[numero] << ")" << endl;
}

double Punteggi::aggiornaPunteggioBonus(int numero) {
    punteggio_ = punteggio_*bonus_val[numero]; // Aggiorna il punteggio moltiplicandolo per il bonus
    ArrontondaPunteggio();
    return punteggio_;
}

void Punteggi::stampamalus(int numero) {
    cout << "Malus: " << malus_desc[numero] << " (x" << malus_val[numero] << ")" << endl;
}

double Punteggi::aggiornaPunteggioMalus(int numero) {
    punteggio_ = punteggio_*malus_val[numero]; // Aggiorna il punteggio moltiplicandolo per il malus
    ArrontondaPunteggio();
    return punteggio_;
}

void Punteggi::stampquest(int numero) {
    cout << "Quest: " << quest_desc[numero] << " (+" << quest_points[numero] << " punti)" << endl;
}

double Punteggi::aggiornaPunteggioQuest(int numero) {
    punteggio_ = punteggio_+quest_points[numero]; // Aggiorna il punteggio aggiungendo i punti della quest
    ArrontondaPunteggio(); 
    return punteggio_;
}

double Punteggi::getpunteggio() {
    return punteggio_;
}

void Punteggi::ArrontondaPunteggio() {
    punteggio_ = round(punteggio_ * 100.0) / 100.0; // Arrotonda il punteggio a 2 decimali
}

//###############################################################################################

Storico::Storico() : Punteggi() {
    punteggio_ = 0; // Inizializza il punteggio a 0
    counterposition = 0; // Inizializza il contatore per lo storico
}

double Storico::aggiornaPunteggioBonus(int numero) {
    punteggio_ = punteggio_*bonus_val[numero]; // Aggiorna il punteggio moltiplicandolo per il bonus
    ArrontondaPunteggio();
    storico.push_back(punteggio_); // Salva il punteggio aggiornato nello storico
    counterposition++;
    return punteggio_;
}

double Storico::aggiornaPunteggioMalus(int numero) {
    punteggio_ = punteggio_*malus_val[numero]; // Aggiorna il punteggio moltiplicandolo per il malus
    ArrontondaPunteggio();
    storico.push_back(punteggio_); // Salva il punteggio aggiornato nello storico
    counterposition++;
    return punteggio_;
}

double Storico::aggiornaPunteggioQuest(int numero) {
    punteggio_ = punteggio_+quest_points[numero]; // Aggiorna il punteggio aggiungendo i punti della quest
    ArrontondaPunteggio(); 
    storico.push_back(punteggio_); // Salva il punteggio aggiornato nello storico
    counterposition++;
    return punteggio_;
}

void Storico::getstorico() {
    cout << "Storico dei punteggi:" << endl;
    for (size_t i = 0; i < counterposition; ++i) {
        cout << "Punteggio " << i + 1 << ": " << storico[i] << endl;
    }
}
