#ifndef CONFIG_H
#define CONFIG_H

#include <vector>

class Config {
    static Config* d_instance;
    std::vector<int> d_digits;
    bool d_all;
    Config();
    Config(const Config&);
public:
    static Config* instance();
    bool all();
    void setAll(bool all);
    std::vector<int> digits();
    void setDigits(const std::vector<int>& digits);
};

inline
bool Config::all() {
    return d_all;
}

inline
std::vector<int> Config::digits() {
    return d_digits;
}

#endif // CONFIG_H

