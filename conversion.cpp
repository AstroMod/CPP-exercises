#include "conversion.hpp"
#include <sstream>

void Metres::operator+= (const Feet toAdd_f) {
    m += to_metres(toAdd_f).m;
}

void Metres::operator+= (const Metres toAdd_m) {
    m += toAdd_m.m;
}

Metres operator"" _m (long double n) {
    Metres m {double(n)};
    return m;
}

void Feet::operator+= (const Feet toAdd_f) {
    f += toAdd_f.f;
}

void Feet::operator+= (const Metres toAdd_m) {
    f += to_feet(toAdd_m).f;
}

Feet operator"" _f (long double n) {
    Feet f {double(n)};
    return f;
}

Feet to_feet (const Metres actual_m) {
    Feet new_f {actual_m.m/0.3048};
    return new_f;
}

Metres to_metres (const Feet actual_f) {
    Metres new_m {actual_f.f*0.3048};
    return new_m;
}

std::string to_string(const Metres conv_m) {
    std::ostringstream temp;
    temp << conv_m.m;
    std::string st = temp.str();
    return st;
}

std::string to_string(const Feet conv_f) {
    std::ostringstream temp;
    temp << conv_f.f;
    std::string st = temp.str();
    return st;
}
