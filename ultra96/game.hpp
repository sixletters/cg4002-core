#include "json.hpp"
#include "player.hpp"
using json = nlohmann::json;

class Game {
    Game(int n): numOfPlayers(n){};
    private:
        Player *player1;
        Player *player2;
        int numOfPlayers;
};