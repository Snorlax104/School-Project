#pragma once

// ============================================================
// Serializzatori JSON per le classi di Fantascuola
// Includi questo file DOPO aver incluso le tue classi
// ============================================================

#include "json.hpp"


namespace __FANTASCUOLA_G1_SAVE__ {

    using nlohmann::json;

    // --------------------------------------------------------
    // PARTICIPANT -> JSON  (e viceversa)
    // --------------------------------------------------------

    // Converte un Participant in json
    // Richiede che Participant abbia: name(), score()
    inline json participantToJson(const __FANTASCUOLA_G3_TEAM__::Participant& p) {
        return json{
            {"name",  p.name()},
            {"score", p.score()}
        };
    }

    // Crea un Participant da json
    inline __FANTASCUOLA_G3_TEAM__::Participant participantFromJson(const json& j) {
        return __FANTASCUOLA_G3_TEAM__::Participant(j.at("name").get<std::string>());
        // score viene ricalcolato dagli ScoreEvent, non serve salvarlo
    }

    // --------------------------------------------------------
    // TEAM -> JSON  (e viceversa)
    // --------------------------------------------------------

    // Richiede che Team abbia: name(), score(), members()
    inline json teamToJson(const __FANTASCUOLA_G3_TEAM__::Team& t) {
        json membersJson = json::array();
        for (const auto& m : t.members()) {
            membersJson.push_back(participantToJson(m));
        }
        return json{
            {"name",    t.name()},
            {"score",   t.score()},
            {"members", membersJson}
        };
    }

    // Crea un Team da json
    inline __FANTASCUOLA_G3_TEAM__::Team teamFromJson(const json& j) {
        std::vector<__FANTASCUOLA_G3_TEAM__::Participant> members;
        for (const auto& mj : j.at("members")) {
            members.push_back(participantFromJson(mj));
        }
        return __FANTASCUOLA_G3_TEAM__::Team(
            j.at("name").get<std::string>(),
            members
        );
    }

    // --------------------------------------------------------
    // PLAYER -> JSON  (e viceversa)
    // --------------------------------------------------------

    // Richiede che Player abbia: GetName(), GetPoints(), GetCredits(), getTeam()
    inline json playerToJson(const __FANTASCUOLA_G2_LEAG__::Player& p) {
        return json{
            {"name",       p.GetName()},
            {"points",     p.GetPoints()},
            {"credits",    p.GetCredits()},
            {"team",       teamToJson(p.getTeam())}
        };
    }

    // Crea un Player da json
    // Nota: il costruttore di Player deve accettare nome, crediti, punti
    inline __FANTASCUOLA_G2_LEAG__::Player playerFromJson(const json& j) {
        __FANTASCUOLA_G2_LEAG__::Player p(
            j.at("name").get<std::string>(),
            j.at("credits").get<int>(),
            j.at("points").get<int>()
        );
        // Il team viene ricostruito separatamente se necessario
        return p;
    }

    // --------------------------------------------------------
    // LEGA -> JSON  (e viceversa)
    // --------------------------------------------------------

    // Richiede che Lega abbia: getName(), getPlayers()
    inline json legaToJson(const __FANTASCUOLA_G2_LEAG__::Lega& lega) {
        json playersJson = json::array();
        for (const auto& p : lega.getPlayers()) {
            playersJson.push_back(playerToJson(p));
        }
        return json{
            {"name",    lega.getName()},
            {"players", playersJson}
        };
    }

    // Crea una Lega da json
    inline __FANTASCUOLA_G2_LEAG__::Lega legaFromJson(const json& j) {
        __FANTASCUOLA_G2_LEAG__::Lega lega(j.at("name").get<std::string>());
        for (const auto& pj : j.at("players")) {
            lega.addPlayer(playerFromJson(pj));
        }
        return lega;
    }

} // namespace __FANTASCUOLA_G1_SAVE__
