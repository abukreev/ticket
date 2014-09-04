#include <args.h>
#include <digitstonumbers.h>
#include <print.h>
#include <types.h>

using namespace std;

int main(int argc, char* argv[]) {

    Values digits;
    if (!parseArgs(argc, argv, digits)) {
        return 1;
    }

    digitsToNumbers(digits);

    return 0;
}

