#include <args.h>
#include <digitstonumbers.h>
#include <print.h>
#include <config.h>
#include <numtext.h>

#include <vector>
#include <assert.h>
#include <algorithm>

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

    Config* config = Config::instance();

    if (digitsToNumbers(config->digits())) {
        assert(!g_results.empty());
        Config::Answer answer = config->answer();
        if (Config::ANSWER_EXISTS == answer) {
            cout << "Solution exists." << endl;
        } else if (Config::ANSWER_BEST == answer ||
                   Config::ANSWER_ALL  == answer) {
            sort(g_results.begin(), g_results.end(), simpler);
            g_results.erase(unique(g_results.begin(), g_results.end(), same), g_results.end());
            int amount = (config->answer() == Config::ANSWER_BEST ?
                    min(config->numberOfAnswers(), g_results.size()) :
                                                   g_results.size());
            for (int i = 0; i < amount; ++i) {
                printResult(g_results[i]);
            }
        }
    } else {
        cout << "No solution was found." << endl;
    }

    return 0;
}

