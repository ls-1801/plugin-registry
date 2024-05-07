#include <iostream>
#include <dlfcn.h>
#include "common.h"

int main(int argc, const char** argv)
{
    assert(argc == 2 && "usage program PATH_TO_PLUGIN.so");
    if (void* plugin = dlopen(argv[1], RTLD_NOW | RTLD_GLOBAL); !plugin)
    {
        printf("%s", dlerror());
        exit(-1);
    }
    assert(Registry<GreetingsPlugin>::verify().greet() == "Hello Friend");
}
