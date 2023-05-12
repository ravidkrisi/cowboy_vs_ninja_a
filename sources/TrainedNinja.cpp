#include "TrainedNinja.hpp"
namespace ariel
{
    // **** define constructors ****
    TrainedNinja::TrainedNinja(): Ninja("anon", 120, 12, Point()) {}; // default constructor
    TrainedNinja::TrainedNinja(string name, const Point& coordinate): Ninja(name, 120, 12, coordinate) {} // parameterized constructor
}