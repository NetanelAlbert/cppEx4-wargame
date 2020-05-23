//
// Created by nati on 21/05/2020.
//

#include "Board.hpp"

namespace WarGame {
    Soldier*& Board::operator[](std::pair<int,int> location){
        return board[location.first][location.second];
    }

    Soldier* Board::operator[](std::pair<int,int> location) const{
        return board[location.first][location.second];
    }

    void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction){
        Soldier** soldier;
        Soldier** dest;
        std::pair<int,int> newPosition = source;
        try {
            soldier = &board.at(source.first).at(source.second);
        } catch (std::out_of_range& e){
            throw std::invalid_argument("The source is out of the board.");
        }
        switch (direction){
            case MoveDIR::Up:
                newPosition.first++;
                break;
            case MoveDIR::Down:
                newPosition.first--;
                break;
            case MoveDIR::Left:
                newPosition.second++;
                break;
            case MoveDIR::Right:
                newPosition.second--;
                break;
        }
        try {
            dest = &board.at(newPosition.first).at(newPosition.second);
        } catch (std::out_of_range& e){
            throw std::invalid_argument("The destination is out of the board.");
        }
        if(*soldier == nullptr)
            throw std::invalid_argument("There is no soldier in the source location.");
        if(*dest != nullptr)
            throw std::invalid_argument("The destination is taken by other soldier.");
        if((*soldier)->team() != player_number)
            throw std::invalid_argument("The soldier in the source location belongs to the other player.");

        *dest = *soldier;
        *soldier = nullptr;
        (*dest)->play(board, source);
    }

    bool Board::has_soldiers(uint player_number) const{
        for (const auto & i : board) {
            for (auto j : i) {
                if(j != nullptr && j->team() == player_number)
                    return true;
            }
        }
        return false;
    }




}