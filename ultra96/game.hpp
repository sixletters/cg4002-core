
#include "player.hpp"
#include "gameState.pb.h"


class Game {
    public:
        Game(int n): numOfPlayers(n){};
        bool isSinglePlayer(){
            return numOfPlayers==1;
        }
        void takeAction(bool (&playerShotMao)[2], int (&playerActionBuffer)[2]){

        };
        gameState getGameState();
    private:
        Player *player1;
        Player *player2;
        int numOfPlayers;
};