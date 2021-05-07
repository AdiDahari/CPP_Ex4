#include "Scientist.hpp"

using namespace std;
using namespace pandemic;

Player &Scientist::discover_cure(Color c)
{
    if (!_board.get_cured().contains(c))
    {
        if (_board.get_stations().contains(_city))
        {
            if (_n == 0)
            {
                _board.set_cured(c);
                return *this;
            }

            int cntr = 0;
            set<City> to_erase;
            for (City ct : _cards)
            {
                if (_board.get_city_color(ct) == c)
                {
                    cntr++;
                    to_erase.insert(ct);
                }
                if (cntr >= _n)
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