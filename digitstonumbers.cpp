#include <digitstonumbers.h>
#include <print.h>
#include <calculate.h>
#include <iostream>

using namespace std;

static void digitsToNumbersP(const Values& numbers,
                             const Values& digits) {

//    cout << "digitsToNumbersP" << endl;
//    cout << "numbers       = " << numbers << endl;
//    cout << "digits        = " << digits  << endl;
    if (!digits.empty()) {
        Value digit = digits[0];

        Values shortenDigits;
        if (digits.size() > 1) {
            shortenDigits.insert(shortenDigits.begin(), digits.begin() + 1, digits.end());
        }
//        cout << "shortenDigits = " << shortenDigits << endl;

        Values numbers1 = numbers;
        numbers1.push_back(digit);
//        cout << "numbers1      = " << numbers1 << endl;
        digitsToNumbersP(numbers1, shortenDigits);

         if (!numbers.empty()) {
             Values numbers2 = numbers;
             numbers2[numbers2.size() - 1] = 10 * numbers2[numbers2.size() - 1] + digit;
//             cout << "numbers2      = " << numbers2 << endl;
             digitsToNumbersP(numbers2, shortenDigits);
         }
    } else {
 //       cout << numbers << endl;
        calculate(numbers);
    }
}

void digitsToNumbers(const Values& digits) {

    Values numbers;
    digitsToNumbersP(numbers, digits);
}

