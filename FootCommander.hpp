//
// Created by nati on 21/05/2020.
//

#ifndef CPPEX4_WARGAME_FOOTCOMMANDER_HPP
#define CPPEX4_WARGAME_FOOTCOMMANDER_HPP

#include "FootSoldier.hpp"
namespace WarGame {
    class FootCommander : public FootSoldier{
        static const  uint HEALTH = 150;
    public:
        explicit FootCommander(uint team)
                : FootSoldier(team, 20, HEALTH, TYPE::Commander){}
        void play(std::vector<std::vector<Soldier*>>&, std::pair<int,int>) override;
    };
}

#endif //CPPEX4_WARGAME_FOOTCOMMANDER_HPP
