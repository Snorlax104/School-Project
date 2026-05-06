#include "../ScoreModifier.h"


ScoreModifier::ScoreModifier(int val, Type type):
    _val(val),
    _type(type),
    _id()
{}

ScoreModifier::~ScoreModifier() {

}


inline int ScoreModifier::val() noexcept {
    return _val;
}

inline ScoreModifier::Type ScoreModifier::type() noexcept {
    return _type;
}