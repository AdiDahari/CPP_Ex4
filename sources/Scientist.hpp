#pragma once
#include "Board.hpp"
#include "Player.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic
{
    class Scientist : public Player
    {
        int _n;

    public:
        Scientist(Board &b, City c, int n) : Player(b, c, "Scientist"), _n(n){};
        ~Scientist(){};
        virtual Player &discover_cure(Color c);
    };
}