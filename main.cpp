#include <args.h>
#include <digitstonumbers.h>
#include <print.h>
#include <numtext.h>

using namespace std;

int main(int argc, char* argv[]) {

    vector<int> digits;
    if (!parseArgs(argc, argv, digits)) {
        return 1;
    }

//    cout << "digits = " << digits << endl;

    if (!digitsToNumbers(digits)) {
        cout << "No solution was found." << endl;
    }

    return 0;
}

