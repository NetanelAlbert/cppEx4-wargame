//
// Created by nati on 21/05/2020.
//

#include "Paramedic.hpp"
namespace WarGame {
    void Paramedic::play(std::vector<std::vector<Soldier*>>& board, std::pair<int,int> pos){


        for (int i = pos.first-1; i < pos.first+2 && i < board.size(); ++i) {
            if(i<0)
                i=0;
            for (int j = pos.second-1; j < pos.second+2 && j < board[i].size(); ++j) {
                if(j<0)
                    j=0;
                if(i == pos.first && j == pos.second) // skip on the Paramedic
                    continue;
                if(board[i][j] != nullptr && board[i][j]->team() == this->team())
                    board[i][j]->heal();
            }
        }

    }
}