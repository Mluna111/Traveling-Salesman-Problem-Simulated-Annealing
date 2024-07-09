
#ifndef CITY_H
#define CITY_H

#include <string>
using namespace std;

class City {
private:
    int x;
    int y;
    string cityName;

public:

    City() {};
    // Constructor
    // creates a city given its name and (x,y) location
    City(string cityName1, int x1, int y1) {
        cityName = cityName1;
        x = x1;
        y = y1;
    }

    // Getters and Setters
    int getX() {
        return x;
    }

    void setX(int x1) {
        x = x1;
    }

    int getY() {
        return y;
    }

    void setY(int y1) {
        y = y1;
    }

    string getCityName() {
        return cityName;
    }

    void setCityName(string cityName1) {
        cityName = cityName1;
    }
};

#endif
