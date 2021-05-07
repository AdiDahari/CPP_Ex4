#include "Dispatcher.hpp"

using namespace std;
using namespace pandemic;

Player &Dispatcher::fly_direct(City c)
{
    if (_city == c)
    {
        throw std::invalid_argument("Not allowed! already in " + get_city(_city));
    }
    if (_board.get_stations().contains(_city))
    {
        _city = c;
    }
    else
    {
        return Player::fly_direct(c);
    }
    return *this;
}