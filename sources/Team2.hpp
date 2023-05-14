#include "Team.hpp"
namespace ariel
{
    class Team2: public Team
    {
    public:
        void attackVictim(Character* victim, Team* opponent_team) override; // this method attack the victim by by order added the attacking team members not by type and order added
    };
}