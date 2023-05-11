#include <string>
#include "Character.hpp"

using namespace std;

namespace ariel
{
    class Cowboy: protected Character
    {
    private:
        // **** define attributes ****
        int cartridge_; // the number of bullets

    public:
        // **** define constructors ****
        Cowboy(); // default constructor,
        Cowboy(string name, Point coordinate); // get cowboy name and coordinate on map

        // **** define functions ****
        void shoot(Character* opponent); // if cowboy is alive and has cartridge, shoot the opponent with 10 points and one bullet is out of cartridge, else the enemy wont harm
        bool hasBullets(); // return true if cowboy's cartridge is not empty, else false
        void reload(); // reload the cartridge with extra 6 bullets
    };
}

