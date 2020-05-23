//
// Created by nati on 21/05/2020.
//

#ifndef CPPEX4_WARGAME_PARAMEDICCOMMANDER_HPP
#define CPPEX4_WARGAME_PARAMEDICCOMMANDER_HPP

#include "Paramedic.hpp"
namespace WarGame {
    class ParamedicCommander : public Paramedic {
        static const uint HEALTH = 200;
    public:
        explicit ParamedicCommander(uint team) : Paramedic(team, HEALTH, Commander) {};

        void play(std::vector<std::vector<Soldier *>> &, std::pair<int, int>) override;
    };
}
#endif //CPPEX4_WARGAME_PARAMEDICCOMMANDER_HPP
