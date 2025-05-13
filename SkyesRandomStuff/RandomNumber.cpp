//
// Created by Skye on 13/05/2025.
//

#include "RandomNumber.h"
#include <chrono>
#include <thread>
#include <cstdlib>

using namespace std;
namespace srs
{
    int RandomNumber(int min, int max, int loadTime)
    {
        this_thread::sleep_for(chrono::seconds(loadTime));
        return (rand() % (max - min + 1)) + min;
    }
}