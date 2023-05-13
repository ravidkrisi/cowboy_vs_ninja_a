#include "Cowboy.hpp"
#include <stdexcept>
namespace ariel
{
    // **** define attributes ****
    Cowboy::Cowboy(): Character("anonCowboy", Point(), 110), cartridge_(6) {} // default constructor
    Cowboy::Cowboy(string name, const Point& coordiante): Character(name, coordiante, 110), cartridge_(6) {} // parameterized constructor

    // **** define functions ****
    // this function return the number of bullets cowboy has
    int Cowboy::getCartridge() const {return this->cartridge_;}
    // reload the cartridge with extra 6 bullets
    void Cowboy::reload() {this->cartridge_+=6;}
    // return true if cowboy's cartridge is not empty, else false
    bool Cowboy::hasBullets() const
    {
       bool has_bullets =  (this->cartridge_>0) ?  true:  false;
       return has_bullets;
    }
    // if cowboy is alive and has cartridge, shoot the opponent with 10 points and one bullet is out of cartridge, else the enemy wont harm
    void Cowboy::shoot(ariel::Character *opponent)
    {
        // check if opponent is not the cowboy iteself
        if(this == opponent)
        {
            throw std::invalid_argument("cowboy cant shoot itself, is not suicidal");
        }
        // check if cowboy is alive
        if(this->isAlive())
        {
            // check if cartridge is not empty
            if(this->hasBullets())
            {
                opponent->hit(10); // shoot the opponent with 10 points
                --this->cartridge_;
            }
        }
    }
    // overrides the print function from character do the same hust add info that the character is cowboy
    string Cowboy::print() const
    {
        
        string info = "C: ";
        info += Character::print();
        return info;
    }
}
