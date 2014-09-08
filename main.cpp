#include <args.h>
#include <digitstonumbers.h>
#include <print.h>
#include <config.h>

#include <vector>

using namespace std;

int main(int argc, char* argv[]) {

    int res = parseArgs(argc, argv);
    if (res == EXIT_OK) {
        return 0;
    } else if (res == EXIT_FAIL) {
        return 1;
    }

//    cout << "digits = " << digits << endl;

    if (!digitsToNumbers(Config::instance()->digits())) {
        cout << "No solution was found." << endl;
    }

    return 0;
}

