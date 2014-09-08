#include <calculate.h>
#include <print.h>
#include <config.h>
#include <iostream>
#include <assert.h>

using namespace std;

bool calculate(const vector<NumText>& numbers) {

    assert(!numbers.empty());
    bool res = false;
//    cout << "calculate" << endl;
//    cout << numbers << endl;
    if (numbers.size() > 1) {
        for (vector<NumText>::const_iterator i = numbers.begin();
                (i + 1) != numbers.end(); ++i) {
            vector<NumText> sideNumbers;
            if (i != numbers.begin()) {
                sideNumbers.insert(sideNumbers.end(), numbers.begin(), i);
            }
            sideNumbers.push_back(NumText());
            if ((i + 2) != numbers.end()) {
                sideNumbers.insert(sideNumbers.end(), i + 2, numbers.end());
            }

            vector<NumText> modifiedValues;
            modifiedValues.push_back(*i +   *(i + 1));
            modifiedValues.push_back(*i -   *(i + 1));
            modifiedValues.push_back(*i *   *(i + 1));
            modifiedValues.push_back(*i /   *(i + 1));
            modifiedValues.push_back(*i * -(*(i + 1)));
            modifiedValues.push_back(*i / -(*(i + 1)));

            for (vector<NumText>::const_iterator j = modifiedValues.begin();
                 j != modifiedValues.end(); ++j) {
                vector<NumText> modifiedNumbers = sideNumbers;
                modifiedNumbers[i - numbers.begin()] = *j;
                if (calculate(modifiedNumbers)) {
                    if (Config::instance()->answer() == Config::ANSWER_EXISTS || 
                        Config::instance()->answer() == Config::ANSWER_ONE) {
                        return true;
                    }
                    res = true;
                }
            }
        }
    } else {
        if (numbers[0].value() == Config::instance()->target()) {
            if (Config::instance()->answer() == Config::ANSWER_ONE || 
                Config::instance()->answer() == Config::ANSWER_ALL) {
                cout << numbers[0].text() << " = " << Config::instance()->target() << endl;
            }
            res = true;
        } else {
//            cout << "!=100" << endl;
        }
    }
    return res;
}
