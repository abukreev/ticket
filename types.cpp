#include <types.h>

Value operator+ (const Value& left, const Value& right) {

    return Value(left.first + right.first, "(" + left.second + "+" + right.second + ")");
}

Value operator- (const Value& left, const Value& right) {

    return Value(left.first - right.first, "(" + left.second + "-" + right.second + ")");
}

Value operator* (const Value& left, const Value& right) {

    return Value(left.first * right.first, left.second + "*" + right.second);
}

Value operator/ (const Value& left, const Value& right) {

    return Value(left.first / right.first, left.second + "/" + right.second);
}

std::ostream& operator<< (std::ostream& os, const Value& value) {

    os << "(" << value.first << ":" << value.second << ")";
    return os;
}

std::ostream& operator<< (std::ostream& out,
                          std::decimal::decimal32 const& value)
{
    return out << decimal_to_float(value);
}

