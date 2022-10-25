#include <string>
#include "gameState.pb.h"

enum Action { 
    SHIELD,
    GRENADE,
    RELOAD,
    EXIT,
    IDLE,
    SHOOT,
    NONE
    };

std::unordered_map<std::string, int> actionStringMap = {
    {"shield", 0},
    {"grenade", 1},
    {"reload", 2},
    {"exit", 3},
    {"idle", 4},
    {"shoot", 5},
    {"none", 6}
};

class Player{
    Player(int id): id(id){};
    void grenade();
    void* shield_health_counter(void*);
    void shield();
    void reload();
    void shoot();
    void getDamaged(int damage);
    void getGrenade();
    void getShot();
    void exit();
    void synchronise(gameState &currGame);

    private:
        const int id;
        int hp = 100;
        int bullets = 6;
        int grenades = 2;
        float shield_time = 0.0;
        int shield_health = 0;
        int num_deaths = 0;
        int num_shield = 3;
        Action action = NONE;
        bool activated_shield = false;
};