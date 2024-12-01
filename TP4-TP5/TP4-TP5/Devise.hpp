#pragma once

#include <string>
#include <iostream>

enum class Devise {
    CAD,
    EURO,
    UNKNOWN
};

inline Devise stringToDevise(std::string devise) {
    if (devise[0] == 'E') {
        return Devise::EURO;
    }
    else if (devise[0] == 'C') {
        return Devise::CAD;
    }

    return Devise::UNKNOWN;
}

inline std::string deviseToString(Devise devise) {
    switch (devise) {
    case Devise::CAD: return "CAD";
    case Devise::EURO: return "EURO";
    default: return "Unknown";
    }
}