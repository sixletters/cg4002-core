#include "game.hpp"
#include <google/protobuf/util/json_util.h>
#pragma once

void Game::synchronise(std::string jsonString){
    gameState expectedGameState;
    google::protobuf::util::JsonStringToMessage(jsonString, &expectedGameState);
    this->player1->synchronise(&expectedGameState.p1());
    this->player2->synchronise(&expectedGameState.p2());
}

void Game::serializeToJson(std::string &jsonString){
    google::protobuf::util::JsonPrintOptions printOptions;
    printOptions.preserve_proto_field_names= true;
    printOptions.always_print_primitive_fields = true;
    gameState currState;
    this->player1->setState(currState.mutable_p1());
    this->player2->setState(currState.mutable_p2()); 
    google::protobuf::util::MessageToJsonString(currState, &jsonString, printOptions);
}

void Game::takeAction(bool (&playerShotMap)[2], Action (&playerActionBuffer)[2]){
    Action p1Action = (Action) playerActionBuffer[0];
    std::cout<<"BUFFER ACTION IS HERE 2\n";
    std::cout<<p1Action;
    if(this->isSinglePlayer()){
        switch (p1Action){
            case SHOOT:
                this->player1->shoot();
                if(playerShotMap[1]){
                    this->player2->getShot();
                }
                break;
            case GRENADE:
                this->player1->grenade();
                this->player2->getGrenade();
                break;
            case RELOAD:
                this->player1->reload();
                break;
            case EXIT:
                this->player1->exit();
                break;
            case SHIELD:
                this->player1->shield();
                break;
            default:
                break;
        }
        std::cout<<" JL IT IS"<<this->player1->getAction()<<"\n";
    }else{
        Action p2Action = (Action) playerActionBuffer[1];
        if(p2Action == SHIELD){
            this->player2->shield();
        }
        if(p1Action == SHIELD){
            this->player1->shield();
        }
        switch (p1Action){
            case SHOOT:
                this->player1->shoot();
                if(playerShotMap[1]){
                    this->player2->getShot();
                }
                break;
            case GRENADE:
                this->player1->grenade();
                this->player2->getGrenade();
                break;
            case RELOAD:
                this->player1->reload();
                break;
            case EXIT:
                this->player1->exit();
                break;
            default:
                break;
        }

        switch (p2Action){
            case SHOOT:
                this->player2->shoot();
                if(playerShotMap[0]){
                    this->player1->getShot();
                }
                break;
            case GRENADE:
                this->player2->grenade();
                this->player1->getGrenade();
                break;
            case RELOAD:
                this->player2->reload();
                break;
            case EXIT:
                this->player2->exit();
                break;
            default:
                break;
        }
    }
}