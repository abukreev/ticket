#include <config.h>

using namespace std;

Config* Config::d_instance = 0;

Config::Config() : d_target(100), d_numberOfAnswers(1), d_answer(ANSWER_EXISTS) {
}

void Config::setTarget(int target) {
    d_target = target;
}

void Config::setAnswer(Config::Answer answer) {
    d_answer = answer;
}

void Config::setNumberOfAnswers(size_t number) {
    d_numberOfAnswers = number;
}

void Config::setDigits(const vector<int>& digits) {
    d_digits = digits;
}

