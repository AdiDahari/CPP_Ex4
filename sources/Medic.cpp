#include "Medic.hpp"

using namespace std;
using namespace pandemic;

Player &Medic::drive(City c)
{
    if (_city == c)
    {
        throw std::invalid_argument("Not allowed! already in " + get_city(_city));
    }
    bool flag = Board::get_adj()[_city].contains(c);
    if (flag && _board.get_cured().contains(Board::get_city_color(c)))
    {
        _board.set_cubes(c, 0);
    }
    return Player::drive(c, flag);
}

Player &Medic::fly_direct(City c)
{
    if (_city == c)
    {
        throw std::invalid_argument("Not allowed! already in " + get_city(_city));
    }
    bool flag = _cards.contains(c);
    if (flag && _board.get_cured().contains(Board::get_city_color(c)))
    {
        _board.set_cubes(c, 0);
    }
    return Player::fly_direct(c);
}

Player &Medic::fly_charter(City c)
{
    if (_city == c)
    {
        throw std::invalid_argument("Not allowed! already in " + get_city(_city));
    }
    bool flag = _cards.contains(_city);
    if (flag && _board.get_cured().contains(Board::get_city_color(c)))
    {
        _board.set_cubes(c, 0);
    }
    return Player::fly_charter(c, flag);
}

Player &Medic::fly_shuttle(City c)
{
    if (_city == c)
    {
        throw std::invalid_argument("Not allowed! already in " + get_city(_city));
    }
    bool flag = _board.get_stations().contains(_city) && _board.get_stations().contains(c);
    if (flag && _board.get_cured().contains(Board::get_city_color(c)))
    {
        _board.set_cubes(c, 0);
    }
    return Player::fly_shuttle(c);
}

Player &Medic::treat(City c)
{
    Color col = Board::get_city_color(c);
    if (!_board.get_cured().contains(col))
    {
        if (_board.get_cubes().at(c) != 0)
        {
            _board.set_cubes(c, 0);
        }
        else
        {
            throw std::invalid_argument("Not allowed! City of " + get_city(c) + " is clear");
        }
    }
    else if (_board.get_cubes().at(c) == 0)
    {
        throw std::invalid_argument("Not allowed! City of " + get_city(c) + " is clear");
    }
    else
    {
        _board.set_cubes(c, 0);
    }
    return *this;
}