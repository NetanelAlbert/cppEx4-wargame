//
// Created by nati on 21/05/2020.
//

#include "ParamedicCommander.hpp"
namespace WarGame {
    void ParamedicCommander::play(std::vector<std::vector<Soldier*>>& board, std::pair<int,int> pos){
        Paramedic::play(board, pos);
        playAll(board, TYPE::Paramedic);
    }
}