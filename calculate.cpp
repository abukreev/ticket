#include <calculate.h>
#include <print.h>
#include <iostream>
#include <assert.h>

using namespace std;

bool calculate(const Values& numbers) {

    assert(!numbers.empty());
    bool res = false;
//    cout << "calculate" << endl;
//    cout << numbers << endl;
    if (numbers.size() > 1) {
        for (Values::const_iterator i = numbers.begin();
                (i + 1) != numbers.end(); ++i) {
            Values sideNumbers;
            if (i != numbers.begin()) {
                sideNumbers.insert(sideNumbers.end(), numbers.begin(), i);
            }
            sideNumbers.push_back(Value());
            if ((i + 2) != numbers.end()) {
                sideNumbers.insert(sideNumbers.end(), i + 2, numbers.end());
            }

            Values modifiedValues;
            modifiedValues.push_back(*i +   *(i + 1));
            modifiedValues.push_back(*i -   *(i + 1));
            modifiedValues.push_back(*i *   *(i + 1));
            modifiedValues.push_back(*i /   *(i + 1));
            modifiedValues.push_back(*i * -(*(i + 1)));
            modifiedValues.push_back(*i / -(*(i + 1)));

            for (Values::const_iterator j = modifiedValues.begin();
                 j != modifiedValues.end(); ++j) {
                Values modifiedNumbers = sideNumbers;
                modifiedNumbers[i - numbers.begin()] = *j;
                if (calculate(modifiedNumbers)) {
                    res = true;
                }
            }
        }
    } else {
        if (numbers[0].first == 100) {
            cout << numbers[0].second << " = 100" << endl;
            res = true;
        } else {
//            cout << "!=100" << endl;
        }
    }
    return res;
}
