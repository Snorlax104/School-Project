#pragma once


#include "json.hpp"
#include <fstream>
#include <string>
#include <iostream>

namespace __FANTASCUOLA_G1_SAVE__ {

    using nlohmann::json;
    using std::string;
    using std::ifstream;
    using std::ofstream;
    using std::cout;
    using std::endl;

    // --------------------------------------------------------
    // SaveManager
    // Uso:
    //   SaveManager::save(lega, "salvataggio.json");
    //   SaveManager::load(lega, "salvataggio.json");
    // --------------------------------------------------------
    class SaveManager {
    public:

        // Salva un oggetto json su file
        // Restituisce true se ok, false se errore
        static bool save(const json& data, const string& filePath) {
            ofstream file(filePath);
            if (!file.is_open()) {
                cout << "[SaveManager] Errore: impossibile aprire " << filePath << endl;
                return false;
            }
            file << data.dump(4); // dump(4) = indentazione di 4 spazi, leggibile
            cout << "[SaveManager] Salvato in: " << filePath << endl;
            return true;
        }

        // Carica un file JSON e restituisce l'oggetto json
        // In caso di errore ritorna un json vuoto
        static json load(const string& filePath) {
            ifstream file(filePath);
            if (!file.is_open()) {
                cout << "[SaveManager] Errore: file non trovato: " << filePath << endl;
                return json{};
            }
            try {
                json data = json::parse(file);
                cout << "[SaveManager] Caricato: " << filePath << endl;
                return data;
            } catch (const json::parse_error& e) {
                cout << "[SaveManager] Errore nel parsing del JSON: " << e.what() << endl;
                return json{};
            }
        }
    };

} // namespace __FANTASCUOLA_G1_SAVE__
