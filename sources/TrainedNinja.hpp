#pragma once 
#include "Ninja.hpp"
using namespace std;

namespace ariel
{
    class TrainedNinja: public Ninja
    {
    public:
        // **** define constructors ****
        TrainedNinja(); // default constructor
        TrainedNinja(string name, const Point& coordinate); // this constructor get ninja name and coordinate on game's map. set hp level:120 speed:12
    };
}