#include <string>
#include "Ninja.hpp"
using namespace std;

namespace ariel
{
    class OldNinja: protected Ninja
    {
    public:
        // **** define constructors ****
        OldNinja(); // default constructor
        OldNinja(string name, const Point& coordinate) // this constructor get ninja name and coordinate on game's map. set hp level:100 speed:14
    };
}