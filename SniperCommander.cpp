//
// Created by nati on 21/05/2020.
//

#include "SniperCommander.hpp"
namespace WarGame {
    void SniperCommander::play(std::vector<std::vector<Soldier*>>& board, std::pair<int,int> pos){
        Sniper::play(board, pos);
        playAll(board, TYPE::Sniper);
    }
}