#include <string>
#include "Ninja.hpp"
using namespace std;

namespace ariel
{
    class TrainedNinja: protected Ninja
    {
    public:
        // **** define constructors ****
        TrainedNinja(); // default constructor
        TrainedNinja(string name, const Point& coordinate); // this constructor get ninja name and coordinate on game's map. set hp level:120 speed:12
    };
}