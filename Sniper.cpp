//
// Created by nati on 21/05/2020.
//

#include "Sniper.hpp"

namespace WarGame {
    void Sniper::play(std::vector<std::vector<Soldier*>>& board, std::pair<int,int> pos){
        uint maxHealth = 0;
        Soldier** strongest = nullptr;
        for (auto & i : board) {
            for (auto & j : i) {
                if (j != nullptr && j->team() != this->team() && j->health() > maxHealth){
                    maxHealth = j->health();
                    strongest = &j;
                }
            }
        }
        if(strongest != nullptr)
            (*strongest)->harm(this->_damage,strongest);
        else
            std::cerr << "Sniper::play can't find someone to shoot at" << std::endl;
    }
}