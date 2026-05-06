#include "../UID.h"

//funzione visibile solo in questo file, genera un UID
static std::array<unsigned char, UIDSIZE> __getUID(){
    //questi robi servono a generare un numero randomico per davvero davvero
    //che altrimenti potrebbe dare problemi
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 255);

    std::array<unsigned char, UIDSIZE> buf;
    //ad ogni 
    for (size_t i = 0; i < UIDSIZE; ++i) {
        buf[i] = static_cast<unsigned char>(dis(gen));
    }

    return buf;
}


using namespace __FANTASCUOLA_G1_UID__;



_ID::_ID() :
    _word(__getUID())
{}

_ID::~_ID() {

}



const array<unsigned char, UIDSIZE>& _ID::get() noexcept {
    return  _word;
}

bool _ID::operator==(_ID obj) {
    return _word == obj._word;
}
