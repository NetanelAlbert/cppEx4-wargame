//
// Created by nati on 21/05/2020.
//

#ifndef CPPEX4_WARGAME_PARAMEDIC_HPP
#define CPPEX4_WARGAME_PARAMEDIC_HPP

#include "Soldier.hpp"
namespace WarGame {
    class Paramedic : public Soldier{
    public:
        explicit Paramedic(uint team, uint health = SOLDIER_HEALTH, TYPE type = TYPE::Paramedic)
                : Soldier(team, 0, health, type){};
        void play(std::vector<std::vector<Soldier*>>&, std::pair<int,int>) override;
    };
}


#endif //CPPEX4_WARGAME_PARAMEDIC_HPP
