#pragma once

#include <array>
#include <random>
#include <algorithm>
#include <cstring>

namespace __FANTASCUOLA_G1_UID__ {

    using std::array;

#define UID _ID
#define UIDSIZE 32
//objects to hold unique, randomly generated 256 bit IDs
//the ID is generated upon construction
    class _ID {
    private:
    //regular arrays are difficult to copy return from functions
        array<unsigned char, UIDSIZE> _word;

    public:
        _ID();
        ~_ID();


        const array<unsigned char, UIDSIZE>& get() noexcept;

        bool operator==(_ID);
    };

    

}

namespace std {
    template <>
    struct hash<__FANTASCUOLA_G1_UID__::_ID> {
        size_t operator()(const __FANTASCUOLA_G1_UID__::_ID& id) const {
            // Since the ID is random, the first 64 bits are a perfectly valid hash
            //hence the single size_t variable
            size_t hash;

            memcpy(&hash, id.get().data(), sizeof(size_t));
            
            return hash;
        }
    };
}