#include <args.h>
#include <digitstonumbers.h>
#include <print.h>

#include <vector>

using namespace std;

int main(int argc, char* argv[]) {

    vector<int> digits;
    bool all;

    int res = parseArgs(argc, argv, digits, all);
    if (res == EXIT_OK) {
        return 0;
    } else if (res == EXIT_FAIL) {
        return 1;
    }

//    cout << "digits = " << digits << endl;

    if (!digitsToNumbers(digits, !all)) {
        cout << "No solution was found." << endl;
    }

    return 0;
}

