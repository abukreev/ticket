#include <numtext.h>

#include <sstream>

using namespace std;

NumText::NumText() {

    d_complexity = 0;
    setValue(0);
}

NumText::NumText(const Value& value) {

    d_complexity = 0;
    setValue(value);
}

NumText::NumText(const Value& value, const Text& text) {

    d_value = value;
    d_text = text;
    d_complexity = 0;
}

NumText::NumText(const Value& value, const Text& text, bool needBraces,
                 int complexity) {

    d_value = value;
    d_text = text;
    d_needBraces = needBraces;
    d_complexity = complexity;
}

NumText::NumText(const NumText& other) {

    *this = other;
}

void NumText::setValue(const Value& value) {

    d_value = value;
    d_text = valueToText(value);
    d_needBraces = false;
}

const NumText& NumText::operator= (const NumText& other) {

    d_value = other.d_value;
    d_text = other.d_text;
    d_needBraces = other.d_needBraces;
    d_complexity = other.d_complexity;
    return *this;
}

NumText operator- (const NumText& value) {

    return NumText(-value.value(), "-" + value.textWithBraces(), true,
                    value.complexity() + 1);
}

NumText operator+ (const NumText& left, const NumText& right) {

    return NumText(left.value() + right.value(),
                   left.text() + "+" + right.text(),
                   true,
                   max(left.complexity(), right.complexity()) + 1);
}

NumText operator- (const NumText& left, const NumText& right) {

    return NumText(left.value() - right.value(),
                   left.text() + "-" + right.textWithBraces(),
                   true,
                   max(left.complexity(), right.complexity()) + 1);
}

NumText operator* (const NumText& left, const NumText& right) {

    return NumText(left.value() * right.value(),
                   left.textWithBraces() + "*" + right.textWithBraces(),
                   false,
                   max(left.complexity(), right.complexity()) + 1);
}

NumText operator/ (const NumText& left, const NumText& right) {

    return NumText(left.value() / right.value(),
                   left.textWithBraces() + "/" + right.textWithBraces(),
                   false,
                   max(left.complexity(), right.complexity()) + 1);
}

ostream& operator<< (ostream& out,
                     const NumText& value)
{
    return out << "(" << value.value() << ":\'" << value.text() << "\')";
}

ostream& operator<< (ostream& out,
                     decimal::decimal32 const& value)
{
    return out << decimal_to_float(value);
}

NumText::Text NumText::valueToText(const NumText::Value& value) {

    stringstream sstr;
    sstr << decimal_to_float(value);
    return sstr.str();
}

bool simpler(const NumText& left, const NumText& right) {

    return left.complexity() < right.complexity();
}

bool complexer(const NumText& left, const NumText& right) {
    return !simpler(left, right);
}

bool same(const NumText& left, const NumText& right) {
    return left.text() == right.text();
}
