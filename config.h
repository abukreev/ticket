#ifndef CONFIG_H
#define CONFIG_H

#include <vector>
#include <stdlib.h>

class Config {
public:
    enum Answer { ANSWER_EXISTS, ANSWER_BEST, ANSWER_ALL };
private:
    static Config* d_instance;
    std::vector<int> d_digits;
    int d_target;
    size_t d_numberOfAnswers;
    Answer d_answer;
    Config();
    Config(const Config&);
public:
    static Config* instance();
    int target();
    void setTarget(int target);
    Answer answer();
    void setAnswer(Answer answer);
    size_t numberOfAnswers();
    void setNumberOfAnswers(size_t number);
    std::vector<int> digits();
    void setDigits(const std::vector<int>& digits);
};

inline
Config* Config::instance() {
    if (0 == d_instance) {
        d_instance = new Config();
    }
    return d_instance;
}

inline
int Config::target() {
    return d_target;
}

inline
Config::Answer Config::answer() {
    return d_answer;
}

inline
size_t Config::numberOfAnswers() {
    return d_numberOfAnswers;
}

inline
std::vector<int> Config::digits() {
    return d_digits;
}

#endif // CONFIG_H

