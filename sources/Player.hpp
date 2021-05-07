#pragma once
#include "Board.hpp"
#include "City.hpp"
#include <set>

namespace pandemic
{
    const int FIVE = 5;

    class Player
    {
    protected:
        Board &_board;
        City _city;
        std::string _role;
        std::set<City> _cards;

    public:
        Player(Board &b, City c, std::string r = "Player") : _role(r), _board(b), _city(c){};
        ~Player(){};
        Player &take_card(City c);
        Player &remove_cards();
        virtual Player &drive(City c, bool flag = false);
        virtual Player &fly_charter(City c, bool flag = false);
        virtual Player &fly_shuttle(City c);
        virtual Player &fly_direct(City c);
        virtual Player &build();
        virtual Player &discover_cure(Color c);
        virtual Player &treat(City c);
        std::string &role() { return _role; };
    };
}