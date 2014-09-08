#include <config.h>

using namespace std;

Config* Config::d_instance = 0;

Config::Config() : d_all(false) {
}

void Config::setAll(bool all) {
    d_all = all;
}

void Config::setDigits(const vector<int>& digits) {
    d_digits = digits;
}

