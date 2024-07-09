
#ifndef TOUR_H
#define TOUR_H

#include <vector>
#include <algorithm>
//#include "TourManager.h"
#include "City.h"
//#include "Utility.h"
#include <iostream>

using namespace std;

class Tour {
private:
    //to hold a tour of cities
    vector<City> tour;
    //we assume initial value of distance is 0
    int distance = 0;


public:
    //Constructor
    //starts an empty tour
    Tour() {
        //tour.resize(TourManager::numberOfCities());
        /*for (int i = 0; i < TourManager::numberOfCities(); i++) {
            tour.push_back(nullptr);
        }*/
    }

    //another Constructor
    //starts a tour from another tour
  
    Tour(vector<City> tour1) {
        tour = tour1;
        distance = 0;
    }

    /*Tour( Tour& tour1) {
        tour = tour1.tour;
        distance = tour1.distance;
    }*

    /**
      Returns tour information
      @return currenttour
     */
    vector<City> getTour() {
        return tour;
    }

    /**
     * Creates a random tour (i.e. individual or candidate solution)
     */
    void generateInitialTour(vector<City>& cities) {
        tour.resize(cities.size());
        // Loop through all our destination cities and add them to our tour
        for (int cityIndex = 0; cityIndex < cities.size(); cityIndex++) {
            setCity(cityIndex, cities[cityIndex]);
        }
        // Randomly reorder the tour
       random_shuffle(tour.begin(), tour.end());
    }

    /**
     * Returns a city from the tour given the city's index
     * @param index
     * @return City at that index
     */

    City getCity(int index) {
        return tour[index];
    }

    /**
     * Sets a city in a certain position within a tour
     * @param index
     * @param city
     */
    void setCity(int index, City city) {
        tour[index]=  city;
        // If the tour has been altered we need to reset the fitness and distance
        distance = 0;
    }

    /**
     * Computes and returns the total distance of the tour
     * @return distance total distance of the tour
     */

    int getTotalDistance() {
        if (distance == 0) {
            int tourDistance = 0;
            // Loop through our tour's cities
            for (int cityIndex = 0; cityIndex < tourSize(); cityIndex++) {
                // Get city we're traveling from
                City fromCity = getCity(cityIndex);
                // City we're traveling to
                City destinationCity;
                // Check we're not on our tour's last city, if we are set our
                // tour's final destination city to our starting city
                if (cityIndex + 1 < tourSize()) {
                    destinationCity = getCity(cityIndex + 1);
                }
                else {
                    destinationCity = getCity(0);
                }
                // Get the distance between the two cities
                tourDistance += euclidianDistance(fromCity, destinationCity);
            }
            distance = tourDistance;
        }
        return distance;
    }

    /**
     * Get number of cities on our tour
     * @return number how many cities there are in the tour!
     */
    int tourSize() {
        return tour.size();
    }

    /**
    * To print out a list of all the cities in the tour
    */

    void printTour() {
        cout << getCity(0).getCityName();
        for (int i = 1; i < tourSize(); i++) {
            cout << " -> " + getCity(i).getCityName();
        }
    }

    /**
    * Computes and returns the Euclidean distance between two cities
    * city1 the first city
    * city2 the second city
    * @return distance the dist between city1 and city2
    */
    static double euclidianDistance(City city1, City city2) {
        int xDistance = abs(city1.getX() - city2.getX());
        int yDistance = abs(city1.getY() - city2.getY());
        double distance = sqrt((xDistance * xDistance) + (yDistance * yDistance));

        return distance;
    }
};

#endif