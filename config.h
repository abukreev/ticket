#ifndef CONFIG_H
#define CONFIG_H

#include <vector>

class Config {
public:
    enum Answer { ANSWER_EXISTS, ANSWER_ONE, ANSWER_ALL };
private:
    static Config* d_instance;
    std::vector<int> d_digits;
    Answer d_answer;
    Config();
    Config(const Config&);
public:
    static Config* instance();
    Answer answer();
    void setAnswer(Answer answer);
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
Config::Answer Config::answer() {
    return d_answer;
}

inline
std::vector<int> Config::digits() {
    return d_digits;
}

#endif // CONFIG_H

