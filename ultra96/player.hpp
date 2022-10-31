#include <string>
#include "gameState.pb.h"
#include <ctime>

enum Action { 
    SHIELD,
    GRENADE,
    RELOAD,
    EXIT,
    SHOOT,
    NONE
};
#pragma once

class Player{
    public:
        Player(int id): id(id){};
        void grenade();
        void shield();
        void reload();
        void shoot();
        void getDamaged(int damage);
        void getGrenade();
        void getShot();
        void exit(){};
        void setState(gameState_playerState *);
        void synchronise(const gameState_playerState *currPlayer);
        Action getAction(){
            return this->action;
        }
    private:
        const int id;
        int hp = 100;
        int bullets = 6;
        int grenades = 2;
        float shield_time = 0;
        int shield_health = 0;
        int num_deaths = 0;
        int num_shield = 3;
        Action action = (Action) NONE;
        std::time_t activated_shield_time;
        bool activated_shield = false;
};
