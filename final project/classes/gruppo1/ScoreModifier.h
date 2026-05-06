#pragma once
#include <array>
#include <random>
#include <algorithm>

#include "UID.h"

namespace __FANTASCUOLA_G1_SCMOD__ {

    using __FANTASCUOLA_G1_UID__::_ID;

    class ScoreModifier {
        
    public:
        enum class Type {
            mult,
            flat
        };

    private:
        UID _id;
        const int _val;
        Type _type;
    public:

        ScoreEvent(int val, Type type);
        ~ScoreEvent();

        inline int val() noexcept;
        inline Type type() noexcept;

    };

}
