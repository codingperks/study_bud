#include <iostream>
#include "requirements.h"
#include "water.h"

int main()
{
    // Water functionality using threads
    std::thread th(water);

    th.join();
    return 0;
}

