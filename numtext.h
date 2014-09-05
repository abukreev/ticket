#ifndef NUMTEXT_H
#define NUMTEXT_H

#include <vector>
#include <decimal/decimal>
#include <iostream>

class NumText {
public:
    typedef std::decimal::decimal32 Value;
    typedef std::string Text;

private:
    Value d_value;
    Text d_text;
    Text valueToText(const Value& value);

public:
    NumText();
    explicit NumText(const Value& value);
    NumText(const Value& value, const Text& text);
    NumText(const NumText& other);
    void setValue(const Value& value);
    const Value& value() const;
    const Text& text() const;
    const NumText& operator= (const NumText& other);
};

NumText operator- (const NumText& value);
NumText operator+ (const NumText& left, const NumText& right);
NumText operator- (const NumText& left, const NumText& right);
NumText operator* (const NumText& left, const NumText& right);
NumText operator/ (const NumText& left, const NumText& right);

inline const NumText::Value& NumText::value() const {

    return d_value;
}

inline const NumText::Text& NumText::text() const {

    return d_text;
}

std::ostream& operator<< (std::ostream& out,
                          std::decimal::decimal32 const& value);

#endif // NUMTEXT_H

