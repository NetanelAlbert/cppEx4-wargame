//
// Created by nati on 20/05/2020.
//

#ifndef CPPEX4_WARGAME_SOLDIER_HPP
#define CPPEX4_WARGAME_SOLDIER_HPP
#include <iostream>
#include <vector>

namespace WarGame {
    class Soldier{
    protected:
        static const  uint SOLDIER_HEALTH = 100;
        const uint _damage;
        const uint _team;
        const uint _maxHealth;
        int _health;
        enum TYPE{Commander, Foot, Sniper, Paramedic};
        const TYPE _type;
    public:
        Soldier(uint team, uint damage, uint health, TYPE type)
            : _type(type), _team(team), _damage(damage), _health(health), _maxHealth(health){}
        virtual void play(std::vector<std::vector<Soldier*>>&, std::pair<int,int>) = 0;
        void harm(uint, Soldier**);
        uint team() const {
            return _team;
        }
        uint health() const {
            return _health;
        }
        TYPE type(){
            return _type;
        }
        void heal();
        void playAll(std::vector<std::vector<Soldier*>>& , TYPE);
        virtual ~Soldier() {};
    };
}
#endif //CPPEX4_WARGAME_SOLDIER_HPP
