#pragma once
#include<iostream>
#include<vector>

namespace __FANTASQUOLA_CLSS_DEF__ {

	using std::string;
	using std::vector;
	using std::initializer_list;

	using std::cout;
	using std::endl;

	//temporary type definition, to be replaced when the variable type of quest id will be known
	//stands for Score Event ID
	#define SEID	__TMP_SEID
	//temporary type definition, to be replaced when the variable type of the total point count id will be known
	#define SCORE	unsigned long
	struct __TMP_SEID { char buf[64]; };

	class Participant {
	private:
		string _name;

		vector<SEID> _score_events;

	public:

		Participant(string name);
		~Participant();

		string name();
		SCORE score();
	};



	class Team {
	private:
		// Attributi della classe 
		string _name; // Nome della squadra 
		int _score; // Punteggio accumulato 
		vector<Participant> _members; // Array per contenere fino a 20 nomi 

	public:
		// Costruttore: imposta i valori iniziali quando crei la squadra 
		Team(string n);
		Team(string n, vector<Participant> members);

		// Funzione per inserire un nuovo partecipante nella lista 
		void addMember(const Participant& member);

		// Funzione per il calcolo dei punti totali della squadra
		SCORE score();

		// Funzione per visualizzare i dati a schermo 
		void displayCLI();
	};
}
