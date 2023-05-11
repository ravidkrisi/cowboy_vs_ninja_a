#include "Ninja.hpp"
namespace ariel
{
    // **** define constructors ****
    Ninja::Ninja(): Character(), speed_(0) {} // default constructor
    Ninja::Ninja(string name, int hp_level, int speed, const Point& coordinate): Character(name, coordinate, hp_level), speed_(speed) {} // parameterized constructor


    // **** define functions ****
    // the ninja moves toward the opponent accordingly to their speed
    void Ninja::move(Character& opponent)
    {
        this->coordinate_ = Point::moveTowards(this->coordinate_, opponent.getLocation(), this->speed_); // set the ninja coordinate in closer to their opponent
    }
    // if ninja is alive and the opponent is less than 1 meter far then the ninja slash the opponent and opponent's hp level down by 50 point, else the opponent wont harm
    void Ninja::slash(Character& opponent)
    {
        // check if ninja is alive
        if(this->isAlive())
        {
            // check if the opponent is less than 1 meter far
            if(this->distance(opponent)<1)
            {
                // hit the opponent with 40 points
                opponent.hit(40);
            }
        }
        //else nothing happen
    }
}

using namespace ariel;
int main ()
{
//    Ninja a("ravid", 120, 12, Point(14, 20));
}