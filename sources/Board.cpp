#include "Board.hpp"
using namespace std;
using namespace pandemic;

Board::Board()
{
    for (auto &p : color_by_city)
    {
        _cubes[p.first] = 0;
    }
}

bool Board::is_clean()
{
    for (auto &p : _cubes)
    {
        if (p.second != 0)
        {
            return false;
        }
    }
    return true;
}

int &Board::operator[](City c)
{
    return _cubes[c];
}

void Board::remove_cures()
{
    _cured = set<Color>();
}

void Board::remove_stations()
{
    _stations = set<City>();
}

ostream &pandemic::operator<<(ostream &os, const Board &b)
{
    os << "Board Status:\n\n";
    os << "\tDiscovered Cures: ";
    for (auto &e : b._cured)
    {
        os << color_text(e) << get_color(e) << RESET << " ";
    }
    os << "\n"
       << endl;
    for (auto &p : b._cubes)
    {
        os << "\tCity: " << get_city(p.first) << ", " << color_the_city(p.first) << get_color(color_by_city.at(p.first)) << RESET << "\n\t\tDisease level " << p.second << endl;
        os << boolalpha << "\t\tResearch Station Exists: " << b._stations.contains(p.first) << "\n"
           << endl;
    }

    return os;
}

Color Board::get_city_color(City c)
{
    return color_by_city.at(c);
}

void Board::set_station(City c)
{
    _stations.insert(c);
}

void Board::set_cured(Color c)
{
    _cured.insert(c);
}

void Board::set_cubes(City c, int n)
{
    _cubes[c] = n;
}
std::map<pandemic::City, std::set<pandemic::City>> Board::_adj =
    {
        {City::Algiers, {City::Madrid, City::Paris, City::Istanbul, City::Cairo}},
        {City::Atlanta, {City::Chicago, City::Miami, City::Washington}},
        {City::Baghdad, {City::Tehran, City::Istanbul, City::Cairo, City::Riyadh, City::Karachi}},
        {City::Bangkok, {City::Kolkata, City::Chennai, City::Jakarta, City::HoChiMinhCity, City::HongKong}},
        {City::Beijing, {City::Shanghai, City::Seoul}},
        {City::BuenosAires, {City::Bogota, City::SaoPaulo}},
        {City::Bogota, {City::MexicoCity, City::Lima, City::Miami, City::SaoPaulo, City::BuenosAires}},
        {City::Cairo, {City::Algiers, City::Istanbul, City::Baghdad, City::Khartoum, City::Riyadh}},
        {City::Chennai, {City::Mumbai, City::Delhi, City::Kolkata, City::Bangkok, City::Jakarta}},
        {City::Chicago, {City::SanFrancisco, City::LosAngeles, City::MexicoCity, City::Atlanta, City::Montreal}},
        {City::Delhi, {City::Tehran, City::Karachi, City::Mumbai, City::Chennai, City::Kolkata}},
        {City::Essen, {City::London, City::Paris, City::Milan, City::StPetersburg}},
        {City::HoChiMinhCity, {City::Jakarta, City::Bangkok, City::HongKong, City::Manila}},
        {City::HongKong, {City::Bangkok, City::Kolkata, City::HoChiMinhCity, City::Shanghai, City::Manila, City::Taipei}},
        {City::Istanbul, {City::Milan, City::Algiers, City::StPetersburg, City::Cairo, City::Baghdad, City::Moscow}},
        {City::Jakarta, {City::Chennai, City::Bangkok, City::HoChiMinhCity, City::Sydney}},
        {City::Johannesburg, {City::Kinshasa, City::Khartoum}},
        {City::Karachi, {City::Tehran, City::Baghdad, City::Riyadh, City::Mumbai, City::Delhi}},
        {City::Khartoum, {City::Cairo, City::Lagos, City::Kinshasa, City::Johannesburg}},
        {City::Kinshasa, {City::Lagos, City::Khartoum, City::Johannesburg}},
        {City::Kolkata, {City::Delhi, City::Chennai, City::Bangkok, City::HongKong}},
        {City::Lagos, {City::SaoPaulo, City::Khartoum, City::Kinshasa}},
        {City::Lima, {City::MexicoCity, City::Bogota, City::Santiago}},
        {City::London, {City::NewYork, City::Madrid, City::Essen, City::Paris}},
        {City::LosAngeles, {City::SanFrancisco, City::Chicago, City::MexicoCity, City::Sydney}},
        {City::Madrid, {City::London, City::NewYork, City::Paris, City::SaoPaulo, City::Algiers}},
        {City::Manila, {City::HongKong, City::Taipei, City::SanFrancisco, City::HoChiMinhCity, City::Sydney}},
        {City::MexicoCity, {City::LosAngeles, City::Chicago, City::Miami, City::Lima, City::Bogota}},
        {City::Miami, {City::Atlanta, City::MexicoCity, City::Washington, City::Bogota}},
        {City::Milan, {City::Essen, City::Paris, City::Istanbul}},
        {City::Montreal, {City::Chicago, City::Washington, City::NewYork}},
        {City::Moscow, {City::StPetersburg, City::Istanbul, City::Tehran}},
        {City::Mumbai, {City::Karachi, City::Delhi, City::Chennai}},
        {City::NewYork, {City::Montreal, City::Washington, City::London, City::Madrid}},
        {City::Osaka, {City::Taipei, City::Tokyo}},
        {City::Paris, {City::Algiers, City::Essen, City::Madrid, City::Milan, City::London}},
        {City::Riyadh, {City::Baghdad, City::Cairo, City::Karachi}},
        {City::SanFrancisco, {City::LosAngeles, City::Chicago, City::Tokyo, City::Manila}},
        {City::Santiago, {City::Lima}},
        {City::SaoPaulo, {City::Bogota, City::BuenosAires, City::Lagos, City::Madrid}},
        {City::Seoul, {City::Beijing, City::Shanghai, City::Tokyo}},
        {City::Shanghai, {City::Beijing, City::HongKong, City::Taipei, City::Seoul, City::Tokyo}},
        {City::StPetersburg, {City::Essen, City::Istanbul, City::Moscow}},
        {City::Sydney, {City::Jakarta, City::Manila, City::LosAngeles}},
        {City::Taipei, {City::Shanghai, City::HongKong, City::Osaka, City::Manila}},
        {City::Tehran, {City::Baghdad, City::Moscow, City::Karachi, City::Delhi}},
        {City::Tokyo, {City::Seoul, City::Shanghai, City::Osaka, City::SanFrancisco}},
        {City::Washington, {City::Atlanta, City::NewYork, City::Montreal, City::Miami}}

};
