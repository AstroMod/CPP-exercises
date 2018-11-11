#include "conversion.hpp"
#include <sstream>

void Metres::operator+= (Feet toAdd_f) {
    m += to_metres(toAdd_f).m;
}

void Metres::operator+= (Metres toAdd_m) {
    m += toAdd_m.m;
}

void Feet::operator+= (Feet toAdd_f) {
    f += toAdd_f.f;
}

void Feet::operator+= (Metres toAdd_m) {
    f += to_feet(toAdd_m).f;
}

Feet to_feet (Metres actual_m) {
    Feet new_f {actual_m.m/0.3048};
    return new_f;
}

Metres to_metres (Feet actual_f) {
    Metres new_m {actual_f.f*0.3048};
    return new_m;
}

std::string to_string(Metres conv_m) {
    std::ostringstream temp;
    temp << conv_m.m;
    std::string st = temp.str();
    return st;
}

std::string to_string(Feet conv_f) {
    std::ostringstream temp;
    temp << conv_f.f;
    std::string st = temp.str();
    return st;
}
