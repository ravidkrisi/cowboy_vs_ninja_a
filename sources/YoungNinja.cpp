#include "YoungNinja.hpp"
namespace ariel
{
    // **** define constructors ****
    YoungNinja::YoungNinja(): Ninja("anon", 100, 14, Point()) {}; // default constructor
    YoungNinja::YoungNinja(string name, const Point& coordinate): Ninja(name, 100, 14, coordinate) {} // parameterized constructor
}