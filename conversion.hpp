#include <iostream>

typedef struct Feet Feet;
typedef struct Metres Metres;

struct Metres {
    double m = 0;

    void operator+= (const Metres toAdd_m);
    void operator+= (const Feet toAdd_f);
};

struct Feet {
    double f = 0;

    void operator+= (const Feet toAdd_f);
    void operator+= (const Metres toAdd_m);
};

Feet to_feet (const Metres actual_m);
Metres to_metres (const Feet actual_f);

std::string to_string(const Metres m);
std::string to_string(const Feet f);

