#pragma once

#include<iostream>
#include<vector>

#include "../gruppo1/main.h"

namespace __FANTASCUOLA_G3_TEAM__ {

	using std::string;
	using std::vector;

	using std::cout;
	using std::endl;


	
	//stands for Score Event ID (Now Score Modifier ID as the old name could be misleading)
	using SEID = __FANTASCUOLA_G1_UID__::_ID; 
	//stands for Participant ID 
	using PID  = __FANTASCUOLA_G1_UID__::_ID;
	//temporary type definition, to be replaced when the variable type of the total point count id will be known
	#define SCORE	int

	class Participant {
	private:
		string _name;
		PID _id;
		const vector<SEID> _score_events;

	public:

		Participant(string name);
		~Participant();

		string name();
		SCORE score();

		void addSE(SEID);
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