#include "OldNinja.hpp"
namespace ariel
{
    // **** define constructors ****
    OldNinja::OldNinja(): Ninja("anonOldNinja", 140, 8, Point()) {}; // default constructor
    OldNinja::OldNinja(string name, const Point& coordinate): Ninja(name, 140, 8, coordinate) {} // parameterized constructor
}