#include <digitstonumbers.h>
#include <print.h>
#include <calculate.h>
#include <iostream>
#include <sstream>

using namespace std;

static void digitsToNumbersP(const vector<int>& numbers,
                             const vector<int>& digits) {

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
        digitsToNumbersP(numbers1, shortenDigits);

         if (!numbers.empty()) {
             vector<int> numbers2 = numbers;
             numbers2[numbers2.size() - 1] = 10 * numbers2[numbers2.size() - 1] + digit;
//             cout << "numbers2      = " << numbers2 << endl;
             digitsToNumbersP(numbers2, shortenDigits);
         }
    } else {
//        cout << numbers << endl;
        Values values;
        for (vector<int>::const_iterator i = numbers.begin(); i != numbers.end(); ++i) {
            stringstream str;
            str << *i;
            values.push_back(Value(*i, str.str()));
        }
//        cout << "values = " << values << endl;
        calculate(values);
    }
}

void digitsToNumbers(const vector<int>& digits) {

    vector<int> numbers;
    digitsToNumbersP(numbers, digits);
}

