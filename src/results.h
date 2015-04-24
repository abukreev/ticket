#ifndef RESULTS_H
#define RESULTS_H

#include <numtext.h>

#include <vector>

class Results {
  public:
    typedef void (*CallbackT)();
  private:
    static Results* d_instance;
    std::vector<NumText> d_solutions;
    CallbackT d_cb;
    Results();
    Results(const Results&);
  public:
    static Results* instance();
    void clear();
    void addSolution(const NumText& solution);
    const std::vector<NumText> solutions() const;
    void sort();
    void print(std::ostream& os);
    void setCallback(CallbackT cb);
};

inline
const std::vector<NumText> Results::solutions() const {
    return d_solutions;    
}

#endif // RESULTS_H

