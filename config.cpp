#include <config.h>

using namespace std;

Config* Config::d_instance = 0;

Config::Config() : d_answer(ANSWER_EXISTS) {
}

void Config::setTarget(int target) {
    d_target = target;
}

void Config::setAnswer(Config::Answer answer) {
    d_answer = answer;
}

void Config::setDigits(const vector<int>& digits) {
    d_digits = digits;
}

