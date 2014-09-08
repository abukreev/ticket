#ifndef ARGS_H
#define ARGS_H

#include <vector>

using namespace std;

enum { EXIT_FAIL, EXIT_OK, RUN };

int parseArgs(int argc, char *argv[]);

#endif // ARGS_H

