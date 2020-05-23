//
// Created by nati on 21/05/2020.
//

#include "Sniper.hpp"

namespace WarGame {
    void Sniper::play(std::vector<std::vector<Soldier*>>& board, std::pair<int,int> pos){
        uint maxHealth = 0;
        Soldier** strongest = nullptr;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] != nullptr && board[i][j]->team() != this->team() && board[i][j]->health() > maxHealth){
                    maxHealth = board[i][j]->health();
                    strongest = &board[i][j];
                }
            }
        }
        if(strongest != nullptr)
            (*strongest)->harm(this->_damage,strongest);
        else
            std::cerr << "Sniper::play can't find someone to shoot at";
    }
}