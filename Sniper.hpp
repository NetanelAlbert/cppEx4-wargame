//
// Created by nati on 21/05/2020.
//

#ifndef CPPEX4_WARGAME_SNIPER_HPP
#define CPPEX4_WARGAME_SNIPER_HPP

#include "Soldier.hpp"
namespace WarGame {
    class Sniper : public Soldier{
    public:
        explicit Sniper(uint team, uint damage = 50, uint health = SOLDIER_HEALTH, TYPE type = TYPE::Sniper)
                : Soldier(team, damage, health, type){};
        void play(std::vector<std::vector<Soldier*>>&, std::pair<int,int>) override;
    };
}
#endif //CPPEX4_WARGAME_SNIPER_HPP
