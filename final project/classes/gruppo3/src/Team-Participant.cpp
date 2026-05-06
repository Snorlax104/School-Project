#include"../Team-Participant.h"


using namespace __FANTASCUOLA_G3_TEAM__;

//#############################################################################
//#############################################################################


Participant::Participant(string name):
	_name(name),
	_id()
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

void Participant::addSE(SEID id){
	_score_events.emplace_back(id);
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
	_members.emplace_back(member);
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