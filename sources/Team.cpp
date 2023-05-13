#include "Team.hpp"
#include <limits.h>
#include <float.h>
using namespace std;
namespace ariel
{
    // **** define constructors deconstruct ****
    Team::Team(): leader_(NULL)  {} // default constructor
    Team::Team(Character* leader): leader_(leader) {} // parameterized constructor

    // **** define functions ****

    // this function get a pointer to team member and add it to team vector team members
    void Team::add(Character *team_member)
    {
        // check if the team has less than 10 members
        if(team_members_.size()<10)
        {
            this->team_members_.push_back(team_member);
        }
        // the team is full and throws an error
        else
        {
            throw std::out_of_range("cant add members the team is full");
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

            for(int i=0; i < this->team_members_.size(); i++)
            {
                // check if the team member is alive
                if(this->team_members_[i]->isAlive())
                {
                    double temp_dist = this->team_members_[i]->distance(this->leader_);
                    if(temp_dist < closet_distance)
                    {
                        closest_member = this->team_members_[i];
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

        // iterate over all opponent team members
        for(int i=0; i < opponent_team->team_members_.size(); i++)
        {
            // check if the team member is alive
            if(opponent_team->team_members_[i]->isAlive())
            {
                double temp_dist = this->leader_->distance(opponent_team->team_members_[i]);
                if(temp_dist < closest_dist)
                {
                    closest_victim = opponent_team->team_members_[i];
                    closest_dist = temp_dist;
                }
            }
        }
        // return the closest victim
        return closest_victim;
    }

    void Team::attackVictim(Character *victim)
    {
        // case 1: iterate over the attacking team cowboy members
        for(int i=0; i < this->team_members_.size(); i++)
        {
            // check if the team member is alive
            if (this->team_members_[i]->isAlive())
            {
                // case 1: cowboy, try to cast to cowboy
                Cowboy* cowboy = dynamic_cast<Cowboy *>(this->team_members_[i]);
                // if casting succeed shoot the victim if cowboy has cartridge else reload armor
                if (cowboy)
                {
                    // check if cowboy has bullets
                    if (cowboy->hasBullets())
                    {
                        cowboy->shoot();
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
        for (int i=0; i < this->team_members_.size(); i++)
        {
            // check if the team member is alive
            if (this->team_members_[i]->isAlive())
            {
                // try to cast to ninja
                Ninja* ninja = dynamic_cast<Ninja *>(this->team_members_[i]);
                // if casting succeed slash the victim if he is less than 1 meter far else move towards him
                if (ninja)
                {
                    // check if ninja is less than 1 meter far then slash the victim
                    if(ninja->distance(victim) < 1)
                    {
                        ninja->slash();
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