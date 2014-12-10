#include <results.h>
#include <config.h>

#include <algorithm>

using namespace std;

Results* Results::d_instance = NULL;

Results::Results() {
}

Results* Results::instance() {

    if (NULL == d_instance) {
        d_instance = new Results();
    }
    return d_instance;
}

void Results::clear() {

    d_solutions.clear();
}

void Results::addSolution(const NumText& solution) {

    d_solutions.push_back(solution);
}

void Results::sort() {

    std::sort(d_solutions.begin(), d_solutions.end(), simpler);
    d_solutions.erase(unique(d_solutions.begin(), d_solutions.end(), same),
                      d_solutions.end());
}

void Results::print(std::ostream& os) {

    sort();
    int amount = (Config::instance()->answer() == Config::ANSWER_BEST ?
            min(Config::instance()->numberOfAnswers(),
                Results::instance()->solutions().size()) :
            Results::instance()->solutions().size());
    for (int i = 0; i < amount; ++i) {
        cout << d_solutions[i].text()
             << " = "
             << d_solutions[i].value()
             << endl;
    }
}

