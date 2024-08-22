#include "CorrectedWords.h"

CorrectedWords::CorrectedWords() : mistake(""), correction("") {}

std::ostream& operator<<(std::ostream& o, const CorrectedWords ob) {
    o << ob.mistake << "         -->\t" << ob.correction << std::endl;
    return o;
}
