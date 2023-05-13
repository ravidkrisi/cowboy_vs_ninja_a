#pragma once 
#include "Ninja.hpp"
using namespace std;

namespace ariel
{
    class YoungNinja: public Ninja
    {
    public:
        // **** define constructors ****
        YoungNinja(); // default constructor
        YoungNinja(string name, const Point& coordinate); // this constructor get ninja name and coordinate on game's map. set hp level:100 speed:14
    };
}