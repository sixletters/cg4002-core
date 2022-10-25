
#include "player.hpp"
#include "gameState.pb.h"


class Game {
    public:
        Game(int n): numOfPlayers(n){
            this->player1 = new Player(1);
            this->player2 = new Player(2);
        };
        bool isSinglePlayer(){
            return numOfPlayers==1;
        }
        void takeAction(bool (&playerShotMap)[2], Action (&playerActionBuffer)[2]);
        ~Game(){
            delete this->player1;
            delete this->player2;
        }
        void synchronise(std::string);
        gameState getGameState();
        void serializeToJson(std::string &);
    private:
        Player *player1;
        Player *player2;
        int numOfPlayers;
};