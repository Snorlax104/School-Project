#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Punteggi{
    private:
        int punteggio_;
    public:

        Punteggi() {
            punteggio_ = 0; // Inizializza il punteggio a 0
        }

        void stampabonus(int numero) {
            cout << "Bonus: " << bonus_desc[numero] << " (x" << bonus_val[numero] << ")" << endl;
        }

        int aggiornaPunteggioBonus(int numero) {
            punteggio_ = punteggio_*bonus_val[numero]; // Aggiorna il punteggio moltiplicandolo per il bonus
            return punteggio_;
        }
        
        void stampamalus(int numero) {
            cout << "Malus: " << malus_desc[numero] << " (x" << malus_val[numero] << ")" << endl;
        }

        int aggiornaPunteggioMalus(int numero) {
            punteggio_ = punteggio_*malus_val[numero]; // Aggiorna il punteggio moltiplicandolo per il malus
            return punteggio_;
        }

        void stampquest(int numero) {
            cout << "Quest: " << quest_desc[numero] << " (+" << quest_points[numero] << " punti)" << endl;
        }

        int aggiornaPunteggioQuest(int numero) {
            punteggio_ = punteggio_+quest_points[numero]; // Aggiorna il punteggio aggiungendo i punti della quest
            return punteggio_;
        }

        int getpunteggio() {
            return punteggio_;
        }

        string bonus_desc[10] = {
            "Prende 10",
            "Interrogazione perfetta",
            "Aiuta un compagno",
            "Consegna tutto in anticipo",
            "Prende un +",
            "Risponde sempre in classe",
            "Progetto eccellente",
            "Nessuna assenza nella settimana",
            "Partecipa attivamente",
            "Vince una gara scolastica"
        };

        double bonus_val[10] = {
            2.0, 1.8, 1.5, 1.7, 1.6,
            1.4, 2.2, 1.3, 1.2, 2.5
        };

        // MALUS: [azione, moltiplicatore]
        string malus_desc[10] = {
            "Prende 2 in informatica",
            "Non fa i compiti",
            "Nota",
            "Disturba la lezione",
            "Arriva in ritardo",
            "Dimentica il materiale",
            "Insufficienza grave",
            "Salta interrogazione",
            "Uso del telefono in classe",
            "Assenza ingiustificata"
        };

        double malus_val[10] = {
            0.5, 0.7, 0.6, 0.8, 0.9,
            0.85, 0.6, 0.75, 0.7, 0.65
        };

        // QUEST: [missione, punteggio]
        string quest_desc[10] = {
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

        double quest_points[10] = {
            30.0, 15.0, 20.0, 12.0, 10.0,
            18.0, 25.0, 14.0, 16.0, 22.0
        };

};

int numerorandomquest() {
            return rand() % 10; // Genera un numero casuale tra 0 e 9
}

int main() {
    Punteggi persona1;
    srand(time(NULL)); // Inizializza il generatore di numeri casuali
    int numero = numerorandomquest(); // Genera un numero casuale per la quest
    
    cout << "Punteggio iniziale: " << persona1.getpunteggio() << endl; // Stampa il punteggio iniziale

    persona1.stampquest(numero); // Stampa la descrizione della quest
    persona1.aggiornaPunteggioQuest(numero);
	
	cout << "Punteggio aggiornato: " << persona1.getpunteggio() << endl;
	
    persona1.stampabonus(numero); // Stampa la descrizione del bonus
	persona1.aggiornaPunteggioBonus(numero);

	cout << "Punteggio aggiornato: " << persona1.getpunteggio() << endl;
	
    persona1.stampamalus(numero); // Stampa la descrizione del malus
    persona1.aggiornaPunteggioMalus(numero);
    cout << "Punteggio finale: " << persona1.getpunteggio() << endl; // Stampa il punteggio finale
    
    return 0;
}
