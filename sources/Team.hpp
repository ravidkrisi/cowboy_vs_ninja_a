// #ifndef TEAM_HPP
// #define TEAM_HPP

#pragma once 

#include "Ninja.hpp"
#include "Cowboy.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"

#include <vector>
using namespace std;
namespace ariel
{
    class Team
    {
    protected:
        // **** declare attributes ****
        Character* leader_;
        vector<Character *> team_members_;

    public:
        // **** declare constructors and destructor ****
        Team (); // default constructor
        Team(Character* leader); // parameterized constructor
        ~Team(); // destructor
        Team& operator=(const Team&) = delete; // disable copy operator

        // **** declare getters ****
        Character* getLeader() const; // this function return the leader of the team

        // **** declare functions ****
        void add(Character* team_member); // this function get a pointer to team member and add it to team vector team members
        void attack(Team* opponent_team); // this function get a pointer to opponent team, check if the leader of attacking team is alive else, replace the leader with the closest team member to the dead leader. then the attacking team choose  the closest team member to the leader of the attacking team from the members of the opponent team as a victim. all attacking team members will attack the victim. cowboy that out of armor will reload and if the victim is dead at any time they will choose new victim as before. if all members of any team are dead game is over
        int stillAlive(); // return the number of alive team members
        void print(); // iterate all over the team members and print their details

    protected:
        void setLeader(); // if the team leader is dead set the closest team member to the leader as the new leader
        Character* getVictim(Team* opponent_team); // return the closest team member of the opponent team to the leader of the attack team
        virtual void attackVictim(Character* victim, Team* opponent_team); // get pointer to the victim of the opponent team and attack him/her till is down. then go to the next victim if the attacking team members are still alive.

    };
}

// #endif