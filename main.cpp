#include <args.h>
#include <digitstonumbers.h>
#include <print.h>
#include <config.h>
#include <numtext.h>

#include <vector>
#include <assert.h>

using namespace std;

std::vector<NumText> g_results;

static void printResult(const NumText& result) {
    cout << result.text()
         << " = "
         << result.value()
         << endl;
}

int main(int argc, char* argv[]) {

    int res = parseArgs(argc, argv);
    if (res == EXIT_OK) {
        return 0;
    } else if (res == EXIT_FAIL) {
        return 1;
    }

    g_results.clear();

    if (digitsToNumbers(Config::instance()->digits())) {
        assert(!g_results.empty());
        if (Config::instance()->answer() == Config::ANSWER_EXISTS) {
            cout << "Solution exists." << endl;
        } else if (Config::instance()->answer() == Config::ANSWER_ONE) {
            printResult(g_results[0]);
        } else if (Config::instance()->answer() == Config::ANSWER_ALL) {
            for (vector<NumText>::const_iterator i = g_results.begin();
                 i != g_results.end(); ++i) {
                printResult(*i);
            }
        }
    } else {
        cout << "No solution was found." << endl;
    }

    return 0;
}

