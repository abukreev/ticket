#include <digitstonumbers.h>
#include <print.h>
#include <calculate.h>
#include <config.h>
#include <iostream>
#include <sstream>

using namespace std;

static bool digitsToNumbersP(const vector<int>& numbers,
                             const vector<int>& digits) {

    bool res = false;
//    cout << "digitsToNumbersP" << endl;
//    cout << "numbers       = " << numbers << endl;
//    cout << "digits        = " << digits  << endl;
    if (!digits.empty()) {
        int digit = digits[0];

        vector<int> shortenDigits;
        if (digits.size() > 1) {
            shortenDigits.insert(shortenDigits.begin(), digits.begin() + 1, digits.end());
        }
//        cout << "shortenDigits = " << shortenDigits << endl;

        vector<int> numbers1 = numbers;
        numbers1.push_back(digit);
//        cout << "numbers1      = " << numbers1 << endl;
        if (digitsToNumbersP(numbers1, shortenDigits)) {
            if (Config::instance()->answer() == Config::ANSWER_EXISTS) {
                return true;
            }
            res = true;
        }

        if (!numbers.empty()) {
            vector<int> numbers2 = numbers;
            numbers2[numbers2.size() - 1] = 10 * numbers2[numbers2.size() - 1] + digit;
//             cout << "numbers2      = " << numbers2 << endl;
            if (digitsToNumbersP(numbers2, shortenDigits)) {
                if (Config::instance()->answer() == Config::ANSWER_EXISTS) {
                    return true;
                }
                res = true;
            }
         }
    } else {
//        cout << numbers << endl;
        vector<NumText> values;
        for (vector<int>::const_iterator i = numbers.begin(); i != numbers.end(); ++i) {
            NumText::Value ntv(*i);
            NumText nt(ntv);
            values.push_back(nt);
        }
//        cout << "values = " << values << endl;
        if (calculate(values)) {
            if (Config::instance()->answer() == Config::ANSWER_EXISTS) {
                return true;
            }
            res = true;
        }
    }

    return res;
}

bool digitsToNumbers(const vector<int>& digits) {

    vector<int> numbers;
    return digitsToNumbersP(numbers, digits);
}

