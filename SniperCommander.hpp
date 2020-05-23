//
// Created by nati on 21/05/2020.
//

#ifndef CPPEX4_WARGAME_SNIPERCOMMANDER_HPP
#define CPPEX4_WARGAME_SNIPERCOMMANDER_HPP

#include "Sniper.hpp"
namespace WarGame {
    class SniperCommander : public Sniper{
        static const  uint HEALTH = 120;
    public:
        explicit SniperCommander(uint team): Sniper(team, 100, HEALTH, TYPE::Commander){}
        void play(std::vector<std::vector<Soldier*>>&, std::pair<int,int>) override;
    };
}

#endif //CPPEX4_WARGAME_SNIPERCOMMANDER_HPP
