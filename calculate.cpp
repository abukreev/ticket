#include <calculate.h>
#include <print.h>
#include <iostream>
#include <assert.h>

using namespace std;

void calculate(const Values& numbers) {

    assert(!numbers.empty());
//    cout << "calculate" << endl;
//    cout << numbers << endl;
    if (numbers.size() > 1) {
        for (Values::const_iterator i = numbers.begin();
                (i + 1) != numbers.end(); ++i) {
            Values v;
            if (i != numbers.begin()) {
                v.insert(v.end(), numbers.begin(), i);
            }
            v.push_back(Value());
            if ((i + 2) != numbers.end()) {
                v.insert(v.end(), i + 2, numbers.end());
            }

            Values vAdd = v;
            vAdd[i - numbers.begin()] = (*i + *(i + 1));
            calculate(vAdd);

            Values vSub = v;
            vSub[i - numbers.begin()] = (*i - *(i + 1));
            calculate(vSub);

            Values vMul = v;
            vMul[i - numbers.begin()] = (*i * *(i + 1));
            calculate(vMul);

            Values vDiv = v;
            vDiv[i - numbers.begin()] = (*i / *(i + 1));
            calculate(vDiv);
        }
    } else {
        if (numbers[0].first == 100) {
            cout << numbers[0].second << " = 100" << endl;
        } else {
//            cout << "!=100" << endl;
        }
    }
}
