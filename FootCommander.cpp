//
// Created by nati on 21/05/2020.
//

#include "FootCommander.hpp"
namespace WarGame {
    void FootCommander::play(std::vector<std::vector<Soldier*>>& board, std::pair<int,int> pos){
        FootSoldier::play(board, pos);
        playAll(board, TYPE::Foot);
    }
}