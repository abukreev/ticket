#include <args.h>
#include <digitstonumbers.h>
#include <print.h>
#include <config.h>
#include <numtext.h>
#include <results.h>

#include <vector>
#include <assert.h>

using namespace std;

void callback() {

    cout << "callback" << endl;
}

int main(int argc, char* argv[]) {

    int res = parseArgs(argc, argv);
    if (res == EXIT_OK) {
        return 0;
    } else if (res == EXIT_FAIL) {
        return 1;
    }

    Results::instance()->clear();
    Results::instance()->setCallback(callback);

    Config* config = Config::instance();
    
    digitsToNumbers(config->digits());

    if (!Results::instance()->solutions().empty()) {
        Config::Answer answer = config->answer();
        if (Config::ANSWER_EXISTS == answer) {
            cout << "Solution exists." << endl;
        } else if (Config::ANSWER_BEST == answer ||
                   Config::ANSWER_ALL  == answer) {
            Results::instance()->print(cout);
        }
    } else {
        cout << "No solution was found." << endl;
    }

    return 0;
}

