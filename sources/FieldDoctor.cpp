#include "FieldDoctor.hpp"

using namespace std;
using namespace pandemic;

Player &FieldDoctor::treat(City c)
{
    if ((Board::get_adj()[_city].contains(c) || _city == c) && _board.get_cubes()[c] != 0)
    {
        if (_board.get_cured().contains(color_by_city.at(c)))
        {
            _board.set_cubes(c, 0);
        }
        else
        {
            _board.set_cubes(c, _board.get_cubes()[c] - 1);
        }
    }
    else if (_board.get_cubes()[c] == 0)
    {
        throw std::invalid_argument("Not allowed! City of " + get_city(c) + " is clear");
    }
    else
    {
        throw std::invalid_argument("Not allowed! City of " + get_city(c) + " is not reachable");
    }
    return *this;
}