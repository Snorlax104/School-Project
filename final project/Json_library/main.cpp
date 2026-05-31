
// ============================================================
// TEST STANDALONE del sistema di salvataggio JSON
// Non richiede nessun altro file del progetto
//
// SETUP:
// 1. Scarica json.hpp da:
//    https://github.com/nlohmann/json/releases/latest
// 2. Mettilo nella stessa cartella di questo file
// 3. Compila con:  g++ -std=c++17 main_test.cpp -o test
// 4. Esegui con:   ./test  (o test.exe su Windows)
// ============================================================

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;
using std::string;
using std::vector;
using std::cout;
using std::endl;

// ============================================================
// Strutture dati semplificate (simulano le classi del progetto)
// ============================================================

struct Participant {
    string name;
    int score;
};

struct Team {
    string name;
    vector<Participant> members;

    int totalScore() const {
        int tot = 0;
        for (const auto& m : members) tot += m.score;
        return tot;
    }
};

struct Player {
    string name;
    int credits;
    int points;
    Team team;
};

struct Lega {
    string name;
    vector<Player> players;
};

// ============================================================
// Serializzatori (identici a quelli del progetto vero)
// ============================================================

json participantToJson(const Participant& p) {
    return json{{"name", p.name}, {"score", p.score}};
}

Participant participantFromJson(const json& j) {
    return {j.at("name"), j.at("score")};
}

json teamToJson(const Team& t) {
    json membersJson = json::array();
    for (const auto& m : t.members)
        membersJson.push_back(participantToJson(m));
    return json{{"name", t.name}, {"members", membersJson}};
}

Team teamFromJson(const json& j) {
    Team t;
    t.name = j.at("name");
    for (const auto& mj : j.at("members"))
        t.members.push_back(participantFromJson(mj));
    return t;
}

json playerToJson(const Player& p) {
    return json{
        {"name",    p.name},
        {"credits", p.credits},
        {"points",  p.points},
        {"team",    teamToJson(p.team)}
    };
}

Player playerFromJson(const json& j) {
    return {
        j.at("name"),
        j.at("credits"),
        j.at("points"),
        teamFromJson(j.at("team"))
    };
}

json legaToJson(const Lega& lega) {
    json playersJson = json::array();
    for (const auto& p : lega.players)
        playersJson.push_back(playerToJson(p));
    return json{{"name", lega.name}, {"players", playersJson}};
}

Lega legaFromJson(const json& j) {
    Lega lega;
    lega.name = j.at("name");
    for (const auto& pj : j.at("players"))
        lega.players.push_back(playerFromJson(pj));
    return lega;
}

// ============================================================
// SaveManager (identico a quello del progetto vero)
// ============================================================

bool save(const json& data, const string& filePath) {
    std::ofstream file(filePath);
    if (!file.is_open()) {
        cout << "[SaveManager] Errore: impossibile aprire " << filePath << endl;
        return false;
    }
    file << data.dump(4);
    cout << "[SaveManager] Salvato in: " << filePath << endl;
    return true;
}

json load(const string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        cout << "[SaveManager] File non trovato: " << filePath << endl;
        return json{};
    }
    try {
        json data = json::parse(file);
        cout << "[SaveManager] Caricato: " << filePath << endl;
        return data;
    } catch (const json::parse_error& e) {
        cout << "[SaveManager] Errore parsing: " << e.what() << endl;
        return json{};
    }
}

// ============================================================
// Funzione di stampa per verificare visivamente i dati
// ============================================================

void stampaLega(const Lega& lega) {
    cout << "\n=== LEGA: " << lega.name << " ===" << endl;
    for (const auto& p : lega.players) {
        cout << "  Player: " << p.name
             << " | Crediti: " << p.credits
             << " | Punti: " << p.points << endl;
        cout << "    Team: " << p.team.name
             << " (score totale: " << p.team.totalScore() << ")" << endl;
        for (const auto& m : p.team.members)
            cout << "      - " << m.name << " (score: " << m.score << ")" << endl;
    }
}

// ============================================================
// MAIN
// ============================================================


int main(int argc, char** argv) {
	

    // --- Crea dati di esempio ---
    Lega lega;
    lega.name = "Fantascuola 2025";

    Player p1;
    p1.name    = "Mario Rossi";
    p1.credits = 100;
    p1.points  = 42;
    p1.team.name = "Team Aquile";
    p1.team.members = {{"Luca", 15}, {"Anna", 27}};

    Player p2;
    p2.name    = "Giulia Bianchi";
    p2.credits = 80;
    p2.points  = 35;
    p2.team.name = "Team Leoni";
    p2.team.members = {{"Marco", 20}, {"Sara", 15}};

    lega.players = {p1, p2};

    // --- Stampa dati originali ---
    cout << ">>> Dati originali:" << endl;
    stampaLega(lega);

    // --- Salva su file ---
    cout << "\n>>> Salvataggio..." << endl;
    save(legaToJson(lega), "salvataggio.json");

    // --- Carica dal file ---
    cout << "\n>>> Caricamento..." << endl;
    json j = load("salvataggio.json");

    if (j.empty()) {
        cout << "Errore nel caricamento!" << endl;
        return 1;
    }

    Lega legaCaricata = legaFromJson(j);

    // --- Stampa dati caricati ---
    cout << "\n>>> Dati caricati dal JSON:" << endl;
    stampaLega(legaCaricata);

    // --- Verifica che i dati siano uguali ---
    cout << "\n>>> Verifica:" << endl;
    bool ok = (lega.name == legaCaricata.name) &&
              (lega.players.size() == legaCaricata.players.size()) &&
              (lega.players[0].name == legaCaricata.players[0].name) &&
              (lega.players[0].credits == legaCaricata.players[0].credits) &&
              (lega.players[1].points == legaCaricata.players[1].points);

    cout << (ok ? "  TUTTO OK - i dati sono identici!" 
                : "  ERRORE - qualcosa non torna!") << endl;

	
	return 0;
}
