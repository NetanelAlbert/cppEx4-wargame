//
// Created by nati on 20/05/2020.
//

#include "Soldier.hpp"
namespace WarGame {
    void Soldier::harm(uint damage, Soldier** pos){
        int tmp = health();
        _health -= damage;
//        std::cout << typeid(this).name() << " of team " << team()
//            << ". before harm: " << tmp << ". after: "<<health()<< std::endl;
        if(_health <= 0){
            *pos = nullptr;
            delete this;
        }
    }
    void Soldier::heal(){
        _health = _maxHealth;
    }
    void Soldier::playAll(std::vector<std::vector<Soldier*>>& board, TYPE type){
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if(board[i][j] != nullptr && board[i][j]->team() == this->team() && board[i][j]->type() == type)
                    board[i][j]->play(board,std::pair<int,int>{i,j});
            }
        }
    }
}
