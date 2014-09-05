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

NumText::NumText(const NumText& other) {

    *this = other;
}

void NumText::setValue(const Value& value) {

    d_value = value;
    d_text = valueToText(value);
}

const NumText& NumText::operator= (const NumText& other) {

    d_value = other.d_value;
    d_text = other.d_text;
    return *this;
}

NumText operator- (const NumText& value) {

    return NumText(-value.value(), "(-" + value.text() + ")");
}

NumText operator+ (const NumText& left, const NumText& right) {

    return NumText(left.value() + right.value(),
            "(" + left.text() + "+" + right.text() + ")");
}

NumText operator- (const NumText& left, const NumText& right) {

    return NumText(left.value() - right.value(),
            "(" + left.text() + "-" + right.text() + ")");
}

NumText operator* (const NumText& left, const NumText& right) {

    return NumText(left.value() * right.value(),
            left.text() + "*" + right.text());
}

NumText operator/ (const NumText& left, const NumText& right) {

    return NumText(left.value() / right.value(),
            left.text() + "/" + right.text());
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

