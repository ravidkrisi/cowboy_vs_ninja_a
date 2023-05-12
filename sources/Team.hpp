#include "Character.hpp"
#include <vector>
using namespace std;
namespace ariel
{
    class Team
    {
    private:
        // **** declare attributes ****
        Character* leader_;
        vector<Character *> team_members_;

    public:
        // **** declare constructors and destructor ****
        Team (); // default constructor
        Team(Character* leader); // parameterized constructor
        ~Team(); // destructor
        // **** declare functions ****
        void add(Character* team_member); // this function get a pointer to team member and add it to team vector team members
        void attack(Team* opponent_team); // this function get a pointer to opponent team, check if the leader of attacking team is alive else, replace the leader with the closest team member to the dead leader. then the attacking team choose  the closest team member to the leader of the attacking team from the members of the opponent team as a victim. all attacking team members will attack the victim. cowboy that out of armor will reload and if the victim is dead at any time they will choose new victim as before. if all members of any team are dead game is over
        void setLeader(); // if the team leader is dead set the closest team member to the leader as the new leader
        Character* setVictim(Team* opponent_team); // return the closest team member of the opponent team to the leader of the attack team
        int stillAlive(); // return the number of alive team members
        void print(); // iterate all over the team members and print their details
    };
}