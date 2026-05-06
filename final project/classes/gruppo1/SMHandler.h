#pragma once

#include <unordered_map>

#include "ScoreModifier.h"
#include "UID.h"

namespace __FANTASCUOLA_G1_SMHANDLER__ {

    using __FANTASCUOLA_G1_SCMOD__::ScoreModifier;
    using __FANTASCUOLA_G1_UID__::_ID;
    using std::unordered_map;


    class SMHandler{
        private:
            unordered_map<_ID, ScoreModifier> _sm_map;

        public:
    }; 
}