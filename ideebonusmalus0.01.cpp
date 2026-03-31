#include <iostream>
using namespace std;

int main() {

    // BONUS: [azione, moltiplicatore]
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

    float bonus_val[10] = {
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

    float malus_val[10] = {
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

   	float quest_points[10] = {
        30.0, 15.0, 20.0, 12.0, 10.0,
        18.0, 25.0, 14.0, 16.0, 22.0
    };

    return 0;
}
