#include <print.h>

using namespace std;

extern "C" char* decimal32ToString(std::decimal::decimal32 const*, char*);

std::ostream& operator<< (std::ostream& out,
                          std::decimal::decimal32 const& value)
{
    return out << decimal_to_float(value);
}

ostream& operator<< (ostream& os, const Values& values) {

    for (Values::const_iterator i = values.begin(), end = values.end(); i != end; ++i) {
        Value value = *i;
        cout << (i != values.begin() ? ", " : "") << value;
    }
    return os;
}

