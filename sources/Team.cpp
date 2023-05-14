#include "Team.hpp"
#include <limits.h>
#include <float.h>
#include <stdexcept>
using namespace std;
namespace ariel
{
    // **** define constructors deconstruct ****
    Team::Team(): leader_(nullptr){} // default constructor
    Team::Team(Character* leader): leader_(leader)
    {
        this->team_members_.push_back(leader);
    } // parameterized constructor
    // destructor
    Team::~Team()
    {
        // free all team members ptr
        for (auto ptr : this->team_members_)
        {
            delete ptr;
            ptr = nullptr;
        }
    }

    // **** define getters ****
    Character* Team::getLeader() const{return this->leader_;}

    // **** define functions ****

    // this function get a pointer to team member and add it to team vector team members
    void Team::add(Character *team_member)
    {
        // check if the member is already in the team them throws invalid argument error
        for (auto ptr : this->team_members_)
        {
            if (ptr == team_member)
            {
                throw std::invalid_argument("cant add this member already in the team");
            }
        }
        // check if the team has less than 10 members than thrown out of range exception
        if(team_members_.size()>=10)
        {
            throw std::out_of_range("cant add members the team is full");
        }
        // add character to team member
        else
        {
            this->team_members_.push_back(team_member);
        }
    }

    // return the number of alive team members
    int Team::stillAlive()
    {
        int alive_count;
        //iterate over all team members
        for (auto ptr : this->team_members_)
        {
            if ( ptr->isAlive())
            {
                alive_count ++;
            }
        }
        return alive_count;
    }

    // iterate all over the team members and print their details
    void Team::print()
    {
        // iterate over all team members
        for (auto ptr : this->team_members_)
        {
            ptr->print();
        }
    }

    void Team::attack(Team *opponent_team)
    {
        setLeader(); // if the team leader is dead set the closest team member to the leader as the new leader
        Character* victim = getVictim(opponent_team); // get the victim of the opponent team
        attackVictim(victim,opponent_team); // all team members attack the victim
    }
    // if the team leader is dead set the closest team member to the leader as the new leader
    void Team::setLeader()
    {
        //check if team leader is alive, else replace team leader with the closet one
        if(!this->leader_->isAlive())
        {
            // searching the closest team member to the team leader
            Character* closest_member = NULL;
            double closet_distance = DBL_MAX;

            // iterate over all team members
            for (auto ptr : this->team_members_)
            {
                // check if the team meber is alive 
                if(ptr->isAlive())
                {
                    double temp_dist = ptr->distance(this->leader_); // calc the distance from the leader 
                    if (temp_dist < closet_distance)
                    {
                        closest_member = ptr; 
                        closet_distance = temp_dist;
                    }
                }
            }
            // set the closest team member to team leader
            this->leader_ = closest_member;
        }
    }

    // return the closest team member of the opponent team to the leader of the attack team
    Character* Team::getVictim(Team *opponent_team)
    {
        Character* closest_victim = NULL;
        double closest_dist = DBL_MAX;

        // iterate over all  opponent team members team members
        for (auto ptr : opponent_team->team_members_)
        {
            // check if the team member is alive 
            if (ptr->isAlive())
            {
                double temp_dist = ptr->distance(this->leader_); // calc the dist from the leader of the attacking team 
                if (temp_dist < closest_dist)
                {
                    closest_victim = ptr;
                    closest_dist = temp_dist; 
                }
            }
        }
        // return the closest victim
        return closest_victim;
    }

    // in this class first the cowboys of the attacking team attack and then the ninja of the team
    void Team::attackVictim(Character *victim, Team* opponent_team)
    {
        // case 1: iterate over the attacking team cowboy members
        for(auto ptr : this->team_members_)
        {
            // check if the team member is alive
            if (ptr->isAlive())
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
            }
        }
        // case 2: iterate over the attacking team ninja members
        for (auto ptr : this->team_members_)
        {
            // check if the team member is alive
            if (ptr->isAlive())
            {
                // try to cast to ninja
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
}