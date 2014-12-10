#include <args.h>
#include <config.h>

#include <iostream>
#include <sstream>
#include <getopt.h>
#include <stdlib.h>

static void printUsage() {

    cerr << "Usage: ticket [0-9]{1,}" << endl;
    cerr << "  -e, --exists    Only show if a solition exists" << endl;
    cerr << "  -b, --best      Show N best solutions (1 default)" << endl;
    cerr << "  -a, --all       Show all solitions" << endl;
    cerr << "  -t, --target    Target number" << endl;
    cerr << "  -h, --help      Show this help and exit" << endl;
    cerr << "  -v, --version   Print version and exit" << endl;
}

static void printVersion() {

    cerr << "ticket - Version 0.1" << endl;
}

int parseArgs(int argc, char *argv[]) {

    int result = RUN;
    Config::instance()->setAnswer(Config::ANSWER_EXISTS);

    while (result == RUN) {
    
        static struct option long_options[] =
            {
            {"exists",  no_argument,       0, 'e'},
            {"best",    no_argument,       0, 'b'},
            {"all",     no_argument,       0, 'a'},
            {"target",  required_argument, 0, 't'},
            {"help",    no_argument,       0, 'h'},
            {"version", no_argument,       0, 'v'},
            {0,         0,                 0,  0 }
            };

        int option_index = 0;
        int c = getopt_long (argc, argv, "ebat:hv", long_options, &option_index);
    
        if (c == 0) {
            break;
        }

        if (c == -1) {
            break;
        }

        switch (c) {
        case 'e':
            Config::instance()->setAnswer(Config::ANSWER_EXISTS);
            break;
        case 'b':
            Config::instance()->setAnswer(Config::ANSWER_BEST);
            Config::instance()->setNumberOfAnswers(1);
            break;
        case 'a':
            Config::instance()->setAnswer(Config::ANSWER_ALL);
            break;
        case 't':
            {
                stringstream strm(optarg);
                int value;
                if (strm >> value) {
                    Config::instance()->setTarget(value);
                } else {
                    cerr << "\'" << optarg << "\'" << " is not a valid number" << endl;
                    result = EXIT_FAIL;
                }
            }
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

