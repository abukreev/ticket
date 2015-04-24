#include <digitstonumbers.h>
#include <print.h>
#include <calculate.h>
#include <config.h>
#include <iostream>
#include <sstream>

using namespace std;

static void digitsToNumbersP(const vector<int>& numbers,
                             const vector<int>& digits) {

    if (!digits.empty()) {
        int digit = digits[0];

        vector<int> shortenDigits;
        if (digits.size() > 1) {
            shortenDigits.insert(shortenDigits.begin(), digits.begin() + 1, digits.end());
        }

        vector<int> numbers1 = numbers;
        numbers1.push_back(digit);
        digitsToNumbersP(numbers1, shortenDigits);

        if (!numbers.empty()) {
            vector<int> numbers2 = numbers;
            numbers2[numbers2.size() - 1] = 10 * numbers2[numbers2.size() - 1] + digit;
            digitsToNumbersP(numbers2, shortenDigits);
         }
    } else {
        vector<NumText> values;
        for (vector<int>::const_iterator i = numbers.begin(); i != numbers.end(); ++i) {
            NumText::Value ntv(*i);
            NumText nt(ntv);
            values.push_back(nt);
        }
        calculate(values);
    }
}

void digitsToNumbers(const vector<int>& digits) {

    vector<int> numbers;
    digitsToNumbersP(numbers, digits);
}

