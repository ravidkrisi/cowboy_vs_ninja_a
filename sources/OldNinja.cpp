#include "OldNinja.hpp"
namespace ariel
{
    // **** define constructors ****
    OldNinja::OldNinja(): Ninja("anonOldNinja", 150, 8, Point()) {}; // default constructor
    OldNinja::OldNinja(string name, const Point& coordinate): Ninja(name, 150, 8, coordinate) {} // parameterized constructor
}