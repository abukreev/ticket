#include <args.h>
#include <digitstonumbers.h>
#include <print.h>
#include <types.h>

using namespace std;

int main(int argc, char* argv[]) {

    vector<int> digits;
    if (!parseArgs(argc, argv, digits)) {
        return 1;
    }

//    cout << "digits = " << digits << endl;

    digitsToNumbers(digits);

    return 0;
}

