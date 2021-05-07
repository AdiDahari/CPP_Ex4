#include "Researcher.hpp"

using namespace std;
using namespace pandemic;

Player &Researcher::discover_cure(Color c)
{
    if (!_board.get_cured().contains(c))
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
            if (cntr == 5)
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
    return *this;
}