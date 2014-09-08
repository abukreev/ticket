#include <numtext.h>

#include <sstream>

using namespace std;

NumText::NumText() {

    setValue(0);
}

NumText::NumText(const Value& value) {

    setValue(value);
}

NumText::NumText(const Value& value, const Text& text) {

    d_value = value;
    d_text = text;
}

NumText::NumText(const Value& value, const Text& text, bool needBraces) {

    d_value = value;
    d_text = text;
    d_needBraces = needBraces;
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
    return *this;
}

NumText operator- (const NumText& value) {

    return NumText(-value.value(), "-" + value.textWithBraces(), true);
}

NumText operator+ (const NumText& left, const NumText& right) {

    return NumText(left.value() + right.value(),
                   left.text() + "+" + right.text(),
                   true);
}

NumText operator- (const NumText& left, const NumText& right) {

    return NumText(left.value() - right.value(),
                   left.text() + "-" + right.textWithBraces(),
                   true);
}

NumText operator* (const NumText& left, const NumText& right) {

    return NumText(left.value() * right.value(),
                   left.textWithBraces() + "*" + right.textWithBraces(),
                   false);
}

NumText operator/ (const NumText& left, const NumText& right) {

    return NumText(left.value() / right.value(),
                   left.textWithBraces() + "/" + right.textWithBraces(),
                   false);
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

