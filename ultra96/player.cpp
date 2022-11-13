
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "player.hpp"
#include <unordered_map>
#include <ctime>
#include <chrono>
#include <sys/time.h>
#include <unistd.h>
#pragma once

void Player::grenade(){
    this->action = GRENADE;
    if(this->grenades){
        this->grenades--;
    }
}

void Player::shield(){
    this->action = SHIELD;
    if(this->num_shield && !this->activated_shield){
        this->shield_health = 30;
        this->activated_shield= true;
        this->activated_shield_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        this->num_shield--;
    }
}

void Player::shoot(){
    this->action = SHOOT;
    if(this->bullets){
        this->bullets--;
        this->action = SHOOT;
    }
}

void Player::reload(){
    this->action = RELOAD;
    if(!this->bullets){
        this->bullets = 6; 
    }
}

void Player::getDamaged(int damage){
    if(this->activated_shield){
        time_t millisec_since_epoch_1 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        float currTime_1 = ((float)millisec_since_epoch_1) / 1000;
        if((currTime_1 - ((float)this->activated_shield_time) / 1000) > 10.0){
            this->activated_shield = false;
            this->shield_health = 0;
        };
    }

    if(this->activated_shield){
        if(this->shield_health > damage){
            this->shield_health -= damage;
        }else{
            damage -= this->shield_health;
            this->shield_health = 0;
            this->hp -= damage; 
        }
    }else{
        this->hp -= damage;
    }

    if(this->hp <= 0){
        this->num_shield = 3;
        this->grenades = 2;
        this->bullets = 6;
        this->num_deaths += 1;
        this->hp = 100;
    }

}

void Player::getGrenade(){
    this->getDamaged(30);
}

void Player::getShot(){
    this->getDamaged(10);
}

void Player::synchronise(const gameState_playerState *currPlayer){
    std::unordered_map<std::string, int> actionStringMap = {
        {"shield", 0},
        {"grenade", 1},
        {"reload", 2},
        {"exit", 3},
        {"shoot", 4},
        {"none", 5}
    };
    this->bullets = currPlayer->bullets();
    this->hp = currPlayer->hp();
    this->grenades = currPlayer->grenades();
    this->shield_time = currPlayer->shield_time();
    this->activated_shield = (this->shield_time > 0.0);
    this->action = (Action) actionStringMap[currPlayer->action()];
    this->num_deaths = currPlayer->num_deaths();
    this->num_shield = currPlayer->num_shield();
    this->shield_health = currPlayer->shield_health();
}

void Player::setState(gameState_playerState *currPlayer){
    switch (this->action){
        case SHOOT:
            currPlayer->set_action("shoot");
            break;
        case GRENADE:
            currPlayer->set_action("grenade");
            break;
        case RELOAD:
            currPlayer->set_action("reload");
            break;
        case EXIT:
            currPlayer->set_action("exit");
            break;
        case SHIELD:
            currPlayer->set_action("shield");
            break;
        default:
            currPlayer->set_action("none");
            break;
    }
    std::cout<<currPlayer->action()<<"\n";
    time_t millisec_since_epoch_1 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    float shield_time = (((float)millisec_since_epoch_1) / 1000) - (((float)this->activated_shield_time) / 1000);
    
    if(shield_time > 10.0){
        this->activated_shield = false;
        this->shield_time = 0;
         this->shield_health = 0;
    }else{
         this->shield_time = 10.0 - shield_time;
    }

    currPlayer->set_bullets(this->bullets);
    currPlayer->set_hp(this->hp);
    currPlayer->set_num_deaths(this->num_deaths);
    currPlayer->set_shield_health(this->shield_health);
    currPlayer->set_shield_time(this->shield_time);
    currPlayer->set_grenades(this->grenades);
    currPlayer->set_num_shield(this->num_shield);
}

