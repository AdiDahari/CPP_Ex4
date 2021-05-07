#include "GeneSplicer.hpp"

using namespace std;
using namespace pandemic;

Player &GeneSplicer::discover_cure(Color c)
{
    if (!_board.get_cured().contains(c))
    {

        if (!_board.get_stations().contains(_city))
        {
            throw std::invalid_argument("No research station in " + get_city(_city));
        }

        int cntr = 0;
        set<City> to_erase;
        for (City ct : _cards)
        {

            cntr++;
            to_erase.insert(ct);

            if (cntr == FIVE)
            {
                _board.set_cured(c);
                for (City rmv : to_erase)
                {
                    _cards.erase(rmv);
                }
                return *this;
            }
        }
        throw std::invalid_argument("Insufficient cards");
    }

    return *this;
}