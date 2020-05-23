//
// Created by nati on 21/05/2020.
//

#ifndef CPPEX4_WARGAME_FOOTSOLDIER_HPP
#define CPPEX4_WARGAME_FOOTSOLDIER_HPP

#include "Soldier.hpp"
namespace WarGame {
    class FootSoldier : public Soldier{
        Soldier* BFS(std::vector<std::vector<Soldier*>>& board, std::pair<int,int> pos);
    public:
        explicit FootSoldier(uint team, uint damage = 10, uint health = SOLDIER_HEALTH, TYPE type = TYPE::Foot)
                : Soldier(team, damage, health, type){};
        void play(std::vector<std::vector<Soldier*>>& , std::pair<int,int>) override;
    };
}


#endif //CPPEX4_WARGAME_FOOTSOLDIER_HPP
