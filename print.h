#ifndef PRINT_H
#define PRINT_H

#include <iostream>
#include <vector>

template<typename T>
std::ostream & operator<< (std::ostream& os, const std::vector<T>& values) {

    for (typename std::vector<T>::const_iterator i = values.begin(), end = values.end(); i != end; ++i) {
        os << (i != values.begin() ? ", " : "") << *i;
    }
    return os;
}

#endif // PRINT_H

