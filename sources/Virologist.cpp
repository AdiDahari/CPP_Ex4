#include "Virologist.hpp"

using namespace std;
using namespace pandemic;

Player &Virologist::treat(City c)
{
    if (_cards.contains(c) && _board.get_cubes()[c] != 0)
    {
        _cards.extract(c);
        _board.set_cubes(c, _board.get_cubes()[c] - 1);
    }
    else if (_board.get_cubes()[c] == 0)
    {
        throw std::invalid_argument("Not allowed! City of " + get_city(c) + " is clear");
    }
    else
    {
        Player::treat(c);
    }
    return *this;
}