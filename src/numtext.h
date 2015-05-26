#ifndef NUMTEXT_H
#define NUMTEXT_H

#include <vector>
#include <iostream>
#include <commfrac.h>

class NumText {
public:
    typedef CommFrac Value;
    typedef std::string Text;
    enum Braces { NoBraces, NeedBraces };

private:
    Value d_value;
    Text d_text;
    Text valueToText(const Value& value);
    Braces d_braces;
    int d_complexity;

public:
    NumText();
    explicit NumText(const Value& value);
    NumText(const Value& value, const Text& text);
    NumText(const Value& value, const Text& text, Braces braces,
            int complexity);
    NumText(const NumText& other);
    int complexity() const;
    void setValue(const Value& value);
    const Value& value() const;
    Text textWithBraces() const;
    const Text& text() const;
    const NumText& operator= (const NumText& other);
};

NumText operator- (const NumText& value);
NumText operator+ (const NumText& left, const NumText& right);
NumText operator- (const NumText& left, const NumText& right);
NumText operator* (const NumText& left, const NumText& right);
NumText operator/ (const NumText& left, const NumText& right);

inline int NumText::complexity() const {

    return d_complexity;
}

inline const NumText::Value& NumText::value() const {

    return d_value;
}

inline NumText::Text NumText::textWithBraces() const {

    if (NeedBraces == d_braces) {
        return "(" + d_text + ")";
    } else {
        return d_text;
    }
}
inline const NumText::Text& NumText::text() const {

    return d_text;
}

bool simpler(const NumText& left, const NumText& right);

bool complexer(const NumText& left, const NumText& right);

bool same(const NumText& left, const NumText& right);

#endif // NUMTEXT_H

