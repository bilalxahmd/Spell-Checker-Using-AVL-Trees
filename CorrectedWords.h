#ifndef CORRECTEDWORDS_H
#define CORRECTEDWORDS_H

#include <iostream>
#include <string>

class CorrectedWords {
public:
    std::string mistake, correction;

    CorrectedWords();

    friend std::ostream& operator<<(std::ostream&, const CorrectedWords&);
};

#endif
