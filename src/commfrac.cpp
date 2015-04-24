#include <commfrac.h>
#include <stdlib.h>

static int calclcm(int left, int right) {

    int dividend = abs(left);
    int divisor = abs(right);
    int remainder;

    if (0 == right) {
        return 0;
    }

    while (true) {
        remainder = dividend % divisor;
        if (remainder == 0) {
            return divisor;
        }
        dividend = divisor;
        divisor = remainder;
    }
}

CommFrac::CommFrac()
: d_nom(0), d_denom(1) {
}

CommFrac::CommFrac(int value)
: d_nom(value), d_denom(1) {
}

CommFrac::CommFrac(int nom, int denom) throw (std::invalid_argument)
: d_nom(nom), d_denom(denom) {

    if (0 == denom) {
        throw std::invalid_argument("Denominator can't be zero");
    }

    simplify();
}

CommFrac::CommFrac(const CommFrac& other) {

    *this = other;
}

const CommFrac& CommFrac::operator =(const CommFrac& other) {

    d_nom = other.d_nom;
    d_denom = other.d_denom;
    return *this;
}

CommFrac::operator int () const {

    return (int) (d_nom / d_denom);
}

const CommFrac& CommFrac::operator- () {

    d_nom = -d_nom;
    return *this;
}

void CommFrac::simplify() {

    if (d_denom < 0) {
        d_nom = -d_nom;        
        d_denom = -d_denom;        
    }

    int lcm = calclcm(d_nom, d_denom);
    d_nom /= lcm;
    d_denom /= lcm;
}

CommFrac operator+ (const CommFrac& left, const CommFrac& right) {

    int nom = left.d_nom * right.d_denom + right.d_nom * left.d_denom;
    int denom = left.d_denom * right.d_denom;

    return CommFrac(nom, denom);
}

CommFrac operator- (const CommFrac& left, const CommFrac& right) {

    int nom = left.d_nom * right.d_denom - right.d_nom * left.d_denom;
    int denom = left.d_denom * right.d_denom;

    return CommFrac(nom, denom);
}

CommFrac operator* (const CommFrac& left, const CommFrac& right) {

    int nom = left.d_nom * right.d_nom;
    int denom = left.d_denom * right.d_denom;

    return CommFrac(nom, denom);
}

CommFrac operator/ (const CommFrac& left, const CommFrac& right) {

    int nom = left.d_nom * right.d_denom;
    int denom = left.d_denom * right.d_nom;

    return CommFrac(nom, denom);
}

//CommFrac CommFrac::operator- (const CommFrac& other) {
//}
//
//CommFrac CommFrac::operator* (const CommFrac& other) {
//}
//
//CommFrac CommFrac::operator/ (const CommFrac& other) {
//}

std::ostream& operator << (std::ostream& s, const CommFrac& cf) {

    s << cf.d_nom << "/" << cf.d_denom;
    return s;
}

