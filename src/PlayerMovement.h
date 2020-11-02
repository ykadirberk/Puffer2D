#include "CharMoveTemp.h"

class PlayerMovement : public CharMoveTemp {
    public:
        PlayerMovement(sf::Sprite* sprite);
        ~PlayerMovement();
        void calculate();
    private:
        sf::Sprite* nsprite = NULL;
};