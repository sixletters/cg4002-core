
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "player.hpp"

void Player::grenade(){
    this->action = GRENADE;
    if(this->grenades){
        this->grenades--;
    }
}

void *Player::shield_health_counter(void* arg){
    this->shield_time = 10;
    while(this->shield_time > 0){
        sleep(1);
        this->shield_time--;
    }
    this->activated_shield = false;
}

void Player::shield(){
    this->action = SHIELD;
    int ret;
    pthread_t my_thread;
    void * ret_join;
    if(this->num_shield && !this->activated_shield){
        this->activated_shield= true;
        
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

void Player::synchronise(gameState &currGame){
    gameState_playerState currPlayer  = (this->id == 1)?currGame.p1():currGame.p2();
    this->bullets = currPlayer.bullets();
    this->hp = currPlayer.hp();
    this->grenades = currPlayer.grenades();
    this->shield_time = currPlayer.shield_time();
    this->action = (Action) actionStringMap[currPlayer.action()];
    this->num_deaths = currPlayer.num_deaths();
    this->num_shield = currPlayer.num_shield();
    this->shield_health = currPlayer.shield_health();
}

