#pragma once
#include "Board.hpp"
#include "Player.hpp"

namespace pandemic
{
    class Medic : public Player
    {
    public:
        Medic(Board &b, City c) : Player(b, c, "Medic")
        {
            if (_board.get_cured().contains(_board.get_city_color(c)))
            {
                _board.get_cubes()[c] = 0;
            }
        };
        ~Medic(){};
        Player &drive(City c);
        Player &fly_direct(City c);
        Player &fly_charter(City c);
        Player &fly_shuttle(City c);
        Player &treat(City c);
    };
}