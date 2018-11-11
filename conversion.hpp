#include <iostream>

typedef struct Feet Feet;
typedef struct Metres Metres;

struct Metres {
    double m = 0;

    void operator+= (Metres toAdd_m);
    void operator+= (Feet toAdd_f);
};

struct Feet {
    double f = 0;

    void operator+= (Feet toAdd_f);
    void operator+= (Metres toAdd_m);
};

Feet to_feet (Metres actual_m);
Metres to_metres (Feet actual_f);

std::string to_string(Metres m);
std::string to_string(Feet f);

