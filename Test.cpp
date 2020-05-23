//
// Created by nati on 23/05/2020.
//

#include "doctest.h"
#include <stdexcept>
#include "Board.hpp"

#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"

using namespace std;
using namespace WarGame;

Board game_board(20, 20);

TEST_CASE("Create Soldiers"){
    // Staging team 1 soldiers
    CHECK_NOTHROW((game_board[{0,9}] = new FootCommander(1)));
    CHECK_NOTHROW((game_board[{0,10}] = new ParamedicCommander(1)));
    CHECK_NOTHROW((game_board[{0,11}] = new SniperCommander(1)));
    for (int i = 0; i < 20; ++i) {
        switch (i%3){
            case 0:
                CHECK_NOTHROW((game_board[{1,i}] = new FootSoldier(1)));
                break;
            case 1:
                CHECK_NOTHROW((game_board[{1,i}] = new Paramedic(1)));
                break;
            case 2:
                CHECK_NOTHROW((game_board[{1,i}] = new Sniper(1)));
                break;
        }
    }

    // Staging team 2 soldiers

    CHECK_NOTHROW((game_board[{19,9}] = new FootCommander(2)));
    CHECK_NOTHROW((game_board[{19,10}] = new ParamedicCommander(2)));
    CHECK_NOTHROW((game_board[{19,11}] = new SniperCommander(2)));
    for (int i = 0; i < 20; ++i) {
        switch (i%2){
            case 0:
                        CHECK_NOTHROW((game_board[{18,i}] = new FootSoldier(2)));
                break;
            case 1:
                        CHECK_NOTHROW((game_board[{18,i}] = new Sniper(2)));
                break;
        }
    }
}

TEST_CASE("Some forbidden moves"){
    CHECK_THROWS((game_board.move(2, {1,10}, Board::MoveDIR::Up))); // not belong to player 2.
    CHECK_THROWS((game_board.move(1, {18,10}, Board::MoveDIR::Down))); // not belong to player 1.

    CHECK_THROWS((game_board.move(1, {0,10}, Board::MoveDIR::Up))); // The destination is taken by other soldier.
    CHECK_THROWS((game_board.move(2, {19,10}, Board::MoveDIR::Down))); // The destination is taken by other soldier.


    CHECK_THROWS((game_board.move(1, {5,10}, Board::MoveDIR::Up))); // There is no soldier in the source location.
    CHECK_THROWS((game_board.move(2, {15,10}, Board::MoveDIR::Down))); // There is no soldier in the source location.

    CHECK_THROWS((game_board.move(1, {0,10}, Board::MoveDIR::Down))); // The destination is out of the board.
    CHECK_THROWS((game_board.move(2, {19,10}, Board::MoveDIR::Up))); // The destination is out of the board.

    CHECK_THROWS((game_board.move(1, {1,0}, Board::MoveDIR::Right))); // The destination is out of the board.
    CHECK_THROWS((game_board.move(2, {18,19}, Board::MoveDIR::Left))); // The destination is out of the board.

}

void team_1_play();
void team_2_play();
TEST_CASE("Play the game"){
    bool has_soldiers = true;
    while (true){
        CHECK_NOTHROW(has_soldiers = game_board.has_soldiers(1));
        if(has_soldiers)
            CHECK_NOTHROW(team_1_play());
        else
            break;

        CHECK_NOTHROW(has_soldiers = game_board.has_soldiers(2));
        if(has_soldiers)
            CHECK_NOTHROW(team_2_play());
        else
            break;
    }
    CHECK(game_board.has_soldiers(1));
    CHECK(!game_board.has_soldiers(2));
}

void team_1_play(){
    static bool commander_mode = false;
    static Board::MoveDIR dir = Board::MoveDIR::Up;
    if(!commander_mode){
        for (int i = 0; i < 20; ++i) { // will move the line of soldiers up, one in each turn.
            if(game_board[{1,i}] != nullptr){
                game_board.move(1,{1,i}, Board::MoveDIR::Up);
                return;
            }
        }
        commander_mode = true;
        team_1_play();
    } else {
        if (dir == Board::MoveDIR::Up){
            for (int i = 9; i < 12; ++i) {
                if (game_board[{0, i}] != nullptr) {
                    game_board.move(1, {0, i}, dir);
                    return;
                }
            }
            dir = Board::MoveDIR::Down;
            team_1_play();
        } else {
            for (int i = 9; i < 12; ++i) {
                if (game_board[{1, i}] != nullptr) {
                    game_board.move(1, {1, i}, dir);
                    return;
                }
            }
            dir = Board::MoveDIR::Up;
            team_1_play();
        }
    }
}

void team_2_play(){
    for (int i = 18; i > 2; --i) { // will move the whole soldiers line down
        for (int j = 0; j < 20; ++j) { // will move the line of soldiers down, one in each turn.
            if(game_board[{i,j}] != nullptr){
                game_board.move(2,{i,j}, Board::MoveDIR::Down);
                return;
            }
        }
    }
}
