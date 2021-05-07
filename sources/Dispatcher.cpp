#include "Dispatcher.hpp"

using namespace std;
using namespace pandemic;

Player &Dispatcher::fly_direct(City c)
{
    // cout << "city: " << get_city(_city) << ". station: " << boolalpha << _board.get_stations().contains(_city) << endl;
    if (_board.get_stations().contains(_city))
    {
        _city = c;
        return *this;
    }
    else
    {
        return Player::fly_direct(c);
    }
}