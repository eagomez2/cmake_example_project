#include <cstdio>
#include "../include/Config.h"

int main(int argc, char* argv[]) {
        printf("Running: %s %i.%i\n", argv[0], VERSION_MAJOR, VERSION_MINOR);
        printf("Hello, Cmake!\n");
        return 0;
}
