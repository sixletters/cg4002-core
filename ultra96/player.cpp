#include "player.hpp"
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

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

// void Player::getDamaged(int damage){
//     if(this->activated_shield){

//     }

// }