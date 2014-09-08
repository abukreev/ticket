#include <args.h>
#include <config.h>

#include <iostream>
#include <sstream>
#include <getopt.h>

static void printUsage() {

    cerr << "Usage: ticket [0-9]{1,}" << endl;
}

static void printVersion() {

    cerr << "ticket - Version 0.1" << endl;
}

int parseArgs(int argc, char *argv[]) {

   int result = RUN;
   Config::instance()->setAll(false);

   while (1) {
       static struct option long_options[] =
           {
           {"all",     no_argument, 0, 'a'},
           {"help",    no_argument, 0, 'h'},
           {"version", no_argument, 0, 'v'},
           {0, 0, 0, 0}
           };

        int option_index = 0;
        int c = getopt_long (argc, argv, "ahv", long_options, &option_index);
    
        if (c == 0) {
            break;
        }

        if (c == -1) {
            break;
        }

        switch (c) {
        case 'a':
            Config::instance()->setAll(true);
            break;
        case 'h':
            printUsage();
	    result = EXIT_OK;
            break;
        case 'v':
            printVersion();
	    result = EXIT_OK;
            break;
        case '?':
        default:
            result = EXIT_FAIL;
        }
    }

    if (result != RUN) {
        return result;
    }

    if ((optind + 1) != argc) {
        printUsage();
        return EXIT_FAIL;
    }

    vector<int> digits;
    for (int i = optind; i < argc; ++i) {
        for (const char* p = argv[i]; *p != '\0'; ++p) {
            int value;
            string str = string(1, *p);
            stringstream sstr(str);
            if (!(sstr >> value)) {
                cerr << "\'" << *p << "\' is not a valid decimal number" << endl;
                return EXIT_FAIL;
            }
            digits.push_back(value);
        }
    }

    Config::instance()->setDigits(digits);

    return RUN;
}

