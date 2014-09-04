#include <args.h>
#include <iostream>
#include <sstream>

static void printUsage() {

    cerr << "Usage: ticket [0-9]{1,}" << endl;
}

bool parseArgs(int argc, char *argv[], std::vector<int>& digits) {

    if (argc < 2) {
        printUsage();
        return false;
    }

    digits.clear();
    for (int i = 1; i < argc; ++i) {
        for (const char* p = argv[i]; *p != '\0'; ++p) {
            int value;
            string str = string(1, *p);
            stringstream sstr(str);
            if (!(sstr >> value)) {
                cerr << "\'" << *p << "\' is not a valid decimal number" << endl;
                return false;
            }
            digits.push_back(value);
        }
    }

    return true;
}

