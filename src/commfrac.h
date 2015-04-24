#ifndef COMMFRAC_H
#define COMMFRAC_H

#include <ostream>
#include <stdexcept>

class CommFrac {
    int d_nom;
    int d_denom;

    void simplify();

public:
    CommFrac();
    CommFrac(int value);
    CommFrac(int nom, int denom) throw (std::invalid_argument);
    CommFrac(const CommFrac& other);
    const CommFrac& operator =(const CommFrac& other);
    operator int () const;
    const CommFrac& operator- ();
    friend CommFrac operator+ (const CommFrac& left, const CommFrac& right);
    friend CommFrac operator- (const CommFrac& left, const CommFrac& right);
    friend CommFrac operator* (const CommFrac& left, const CommFrac& right);
    friend CommFrac operator/ (const CommFrac& left, const CommFrac& right);
    friend std::ostream& operator << (std::ostream& s, const CommFrac& cf);
};

CommFrac operator+ (const CommFrac& left, const CommFrac& right);
CommFrac operator- (const CommFrac& left, const CommFrac& right);
CommFrac operator* (const CommFrac& left, const CommFrac& right);
CommFrac operator/ (const CommFrac& left, const CommFrac& right);
std::ostream& operator << (std::ostream& s, const CommFrac& cf);

#endif // COMMFRAC_H
