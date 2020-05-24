//
// Created by nati on 21/05/2020.
//

#include "FootSoldier.hpp"
namespace WarGame {
    Soldier *FootSoldier::BFS(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> pos) {
        if (pos.first < 0 || pos.first >= board.size() || pos.second < 0
            || pos.second >= board[pos.first].size() || board[pos.first][pos.second] == (Soldier *) -1)
            return nullptr;
        Soldier *ans = board[pos.first][pos.second];
        if (ans != nullptr && ans->team() != this->team())
            return ans;
        board[pos.first][pos.second] = (Soldier *) -1;
        ans = BFS(board, std::pair<int, int>{pos.first + 1, pos.second});
        if (ans != nullptr)
            return ans;
        ans = BFS(board, std::pair<int, int>{pos.first - 1, pos.second});
        if (ans != nullptr)
            return ans;
        ans = BFS(board, std::pair<int, int>{pos.first, pos.second + 1});
        if (ans != nullptr)
            return ans;
        return BFS(board, std::pair<int, int>{pos.first, pos.second - 1});
    }

    void FootSoldier::play(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> pos) {
//        std::vector<std::vector<Soldier *>> copy = board;
//        Soldier *nearest = BFS(copy, pos);

        uint minDistance = board.size()+board[0].size();
        uint distance;
        Soldier** nearest = nullptr;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                distance = abs(i-pos.first)+abs(j-pos.second);
                if (board[i][j] != nullptr && board[i][j]->team() != this->team() && distance < minDistance){
                    minDistance = distance;
                    nearest = &board[i][j];
                }
            }
        }
        if (nearest != nullptr)
            (*nearest)->harm(this->_damage, nearest);
        else
            std::cerr << "FootSoldier::play- can't find someone to shoot at" << std::endl;
    }
}