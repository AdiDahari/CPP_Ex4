#pragma once
#include <map>
#include <set>
#include <string>
#include <iostream>
#include "City.hpp"
#include "Color.hpp"

namespace pandemic
{

    class Board
    {
        static std::map<City, std::set<City>> _adj;
        std::set<City> _stations;
        std::map<City, int> _cubes;
        std::set<Color> _cured;

    public:
        Board();
        ~Board(){};
        bool is_clean();
        void remove_cures();
        void remove_stations();
        int &operator[](City c);
        static Color get_city_color(City c);
        void set_station(City c);
        void set_cured(Color c);
        void set_cubes(City c, int n);
        inline static std::map<City, std::set<City>> get_adj()
        {
            return _adj;
        };
        inline std::set<City> get_stations()
        {
            return _stations;
        };
        inline std::map<City, int> get_cubes()
        {
            return _cubes;
        };
        inline std::set<Color> get_cured()
        {
            return _cured;
        };
        friend std::ostream &operator<<(std::ostream &os, const Board &b);
    };

}