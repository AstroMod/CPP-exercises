#include <iostream>
#include <string>

struct Feet;

struct Metres {
    double m = 0;

    void operator+= (const Metres toAdd_m);
    void operator+= (const Feet toAdd_f);
};

Metres operator"" _m (long double n);

struct Feet {
    double f = 0;

    void operator+= (const Feet toAdd_f);
    void operator+= (const Metres toAdd_m);
};

Feet operator"" _f (long double n);

Feet to_feet (const Metres actual_m);
Metres to_metres (const Feet actual_f);

std::string to_string(const Metres m);
std::string to_string(const Feet f);

