#include "Player.hpp"

using namespace std;
using namespace pandemic;

Player &Player::take_card(City c)
{
    _cards.insert(c);
    return *this;
}

Player &Player::remove_cards()
{
    _cards = set<City>();
    return *this;
}

Player &Player::drive(City c, bool flag)
{
    if (_city == c)
    {
        throw std::invalid_argument("Not allowed! already in " + get_city(_city));
    }
    if (flag || _board.get_adj()[_city].contains(c))
    {
        _city = c;
    }
    else
    {
        throw std::invalid_argument(get_city(_city) + " has no connection with " + get_city(c));
    }
    return *this;
}

Player &Player::fly_charter(City c, bool flag)
{
    if (_city == c)
    {
        throw std::invalid_argument("Not allowed! already in " + get_city(_city));
    }
    if (flag || _cards.contains(_city))
    {
        _cards.extract(_city);
        _city = c;
    }
    else
    {
        throw std::invalid_argument("Not allowed! Card of " + get_city(_city) + " is required");
    }
    return *this;
}

Player &Player::fly_shuttle(City c)
{
    if (_city == c)
    {
        throw std::invalid_argument("Not allowed! already in " + get_city(_city));
    }
    if (!_board.get_stations().contains(c))
    {

        throw std::invalid_argument("City of " + get_city(c) + " has no Research Station");
    }
    else if (!_board.get_stations().contains(_city))
    {
        throw std::invalid_argument("City of " + get_city(_city) + " has no Research Station");
    }
    _city = c;
    return *this;
}

Player &Player::fly_direct(City c)
{
    if (_city == c)
    {
        throw std::invalid_argument("Not allowed! already in " + get_city(_city));
    }
    if (_cards.contains(c))
    {
        _cards.extract(c);
        _city = c;
    }
    else
    {
        throw std::invalid_argument("Not allowed! Card of " + get_city(c) + " is required");
    }
    return *this;
}

Player &Player::build()
{
    if (!_board.get_stations().contains(_city))
    {
        if (_cards.contains(_city))
        {

            _cards.extract(_city);
            _board.set_station(_city);
        }
        else
        {
            throw std::invalid_argument("Not allowed! Card of " + get_city(_city) + " is required");
        }
    }
    return *this;
}

Player &Player::discover_cure(Color c)
{
    if (!_board.get_cured().contains(c))
    {
        if (_board.get_stations().contains(_city))
        {

            int cntr = 0;
            set<City> to_erase;
            for (City ct : _cards)
            {
                if (_board.get_city_color(ct) == c)
                {
                    cntr++;
                    to_erase.insert(ct);
                }
                if (cntr >= 5)
                {
                    _board.set_cured(c);
                    for (City rmv : to_erase)
                    {
                        _cards.erase(rmv);
                    }
                    return *this;
                }
            }
            throw std::invalid_argument("Insufficient cards of Color " + get_color(c));
        }
        else
        {
            throw std::invalid_argument("No research station in " + get_city(_city));
        }
    }
    return *this;
}

Player &Player::treat(City c)
{
    Color col = _board.get_city_color(c);
    if (!_board.get_cured().contains(col))
    {
        if (_board[c] != 0 && _city == c)
        {
            _board.set_cubes(c, _board[c] - 1);
            return *this;
        }
        else if (_city == c)
        {
            throw std::invalid_argument("Not allowed! City of " + get_city(c) + " is clear");
        }
        else
        {
            throw std::invalid_argument("Not allowed! Not in " + get_city(c));
        }
    }
    else if (_board.get_cubes().at(c) == 0)
    {
        throw std::invalid_argument("Not allowed! City of " + get_city(c) + " is clear");
    }
    else
    {
        _board.set_cubes(c, 0);
        return *this;
    }
}