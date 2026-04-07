#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

const int numero_b=13;
const int numero_m=11;
const int numero_q=10;

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

int main() {
    Storico persona1;
    srand(time(NULL)); // Inizializza il generatore di numeri casuali per la quest

    int numero = numerorandomquest(); // Genera un numero casuale per la quest
    cout << "Punteggio iniziale: " << persona1.getpunteggio() << endl; // Stampa il punteggio iniziale
    persona1.stampquest(numero); // Stampa la descrizione della quest
    persona1.aggiornaPunteggioQuest(numero); // Aggiorna il punteggio con i punti della quest
    persona1.stampabonus(numero); // Stampa la descrizione del bonus
    persona1.aggiornaPunteggioBonus(numero); // Aggiorna il punteggio con il bonus
    persona1.stampamalus(numero); // Stampa la descrizione del malus    
    persona1.aggiornaPunteggioMalus(numero); // Aggiorna il punteggio con il malus

    numero = numerorandomquest(); // Genera un numero casuale per la quest
    persona1.stampquest(numero); // Stampa la descrizione della quest
    persona1.aggiornaPunteggioQuest(numero); // Aggiorna il punteggio con i punti della quest
    persona1.stampabonus(numero); // Stampa la descrizione del bonus
    persona1.aggiornaPunteggioBonus(numero); // Aggiorna il punteggio con il bonus
    persona1.stampamalus(numero); // Stampa la descrizione del malus    
    persona1.aggiornaPunteggioMalus(numero); // Aggiorna il punteggio con il malus

    persona1.getstorico(); // Stampa lo storico dei punteggi
    

    return 0;
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
