#include "Team2.hpp"

namespace ariel
{
    void Team2::attackVictim(ariel::Character *victim, ariel::Team *opponent_team)
    {
        // iterate over all attacking team members
        for (auto ptr : this->team_members_)
        {
            // case 1: cowboy, try to cast to cowboy
            Cowboy* cowboy = dynamic_cast<Cowboy *>(ptr);
            // if casting succeed shoot the victim if cowboy has cartridge else reload armor
            if (cowboy)
            {
                // check if cowboy has bullets
                if (cowboy->hasBullets())
                {
                    cowboy->shoot(victim);
                    // check if the victim is dead then switch to another victim
                    if (!victim->isAlive())
                    {
                        victim = getVictim(opponent_team); // set new victim
                    }
                }
                    // else reload armor
                else
                {
                    cowboy->reload();
                }
            }

            // case 2: ninja try to cast to ninja
            Ninja* ninja = dynamic_cast<Ninja *>(ptr);
            // if casting succeed slash the victim if he is less than 1 meter far else move towards him
            if (ninja)
            {
                // check if ninja is less than 1 meter far then slash the victim
                if(ninja->distance(victim) < 1)
                {
                    ninja->slash(victim);
                    // check if the victim is dead then switch to another victim
                    if (!victim->isAlive())
                    {
                        victim = getVictim(opponent_team); // set new victim
                    }
                }
                    // else move towards the victim
                else
                {
                    ninja->move(victim);
                }
            }
        }
    }
}