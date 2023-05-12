#include "Character.hpp"
#include <iostream>
using namespace std;
namespace ariel
{
    // **** define constructors ****

    Character::Character(): name_("anon"), coordinate_(Point()), hp_level_(0) {} // default constructor
    Character::Character(string name, const Point& coordinate, int hp_level): name_(name), coordinate_(Point(coordinate.getX(), coordinate.getY())), hp_level_(hp_level)  {} // parameterized constructor

    // **** define getters ****

    // this function return the character name
    string Character::getName() {return this->name_;};
    // this function return the character location
    const Point& Character::getLocation() const {return  this->coordinate_;}

    // **** define functions ****

    // this function subtract the the number of hits from character hp level
    void Character::hit(int hit_points)
    {
        this->hp_level_-= hit_points;
    }

    // this function return true if hit_count_ greater than 0, else false
    bool Character::isAlive()
    {
        if (this->hp_level_<=0)
        {
            return false;
        }
        return true;
    }
    // this function return the distance between two characters
    double Character::distance(Character* other)
    {
        return this->coordinate_.getDistance(other->getLocation());
    }

    // this function prints characters: name, hp level, coordinate, type of character. if character is dead, doesnt print hp level and character's name in ().
    void Character::print()
    {
        // if the characters is dead
        if(!this->isAlive())
        {
            cout << "(" + this->getName() + ")" << endl;
        }
        // if the character is alive
        else
        {
            cout << this->getName() + " hp level:" + to_string(this->hp_level_) + " Point:";
            this->coordinate_.printPoint();
            cout << endl;
        }
    }




}