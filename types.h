#ifndef TYPES_H
#define TYPES_H

#include <vector>
#include <decimal/decimal>
#include <iostream>

typedef std::pair<std::decimal::decimal32, std::string> Value;
typedef std::vector<Value> Values;

Value operator+ (const Value& left, const Value& right);
Value operator- (const Value& left, const Value& right);
Value operator* (const Value& left, const Value& right);
Value operator/ (const Value& left, const Value& right);

std::ostream& operator<< (std::ostream& os, const Value& value);
std::ostream& operator<< (std::ostream& out,
                          std::decimal::decimal32 const& value);

#endif // TYPES_H

