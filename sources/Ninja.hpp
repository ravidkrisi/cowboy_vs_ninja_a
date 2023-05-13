#ifndef NINJA_HPP
#define NINJA_HPP

#include <string>
#include "Character.hpp"
using namespace std;

namespace ariel
{
    class Ninja: protected Character
    {
    private:
        // **** declare attributes ****
        int speed_;
    public:
        // **** declare constructors ****
        Ninja(); // default constructor
        Ninja(string name, int hp_level, int speed, const Point& coordinate); // parametrized constructor

        // **** declare functions ****
        void move(Character* opponent); // the ninja moves toward the opponent accordingly to their speed
        void slash(Character* opponent); // if ninja is alive and the opponent is less than 1 meter far then the ninja slash the opponent and opponent's hp level down by 50 point, else the opponent wont harm
    };
}

#endif