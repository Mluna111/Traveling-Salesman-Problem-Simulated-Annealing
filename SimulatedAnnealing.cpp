#include <iostream>
#include <fstream> 
#include<vector>
#include "City.h"
#include "Tour.h"
//#include "TourManager.h"
//#include "Utility.h"

using namespace std;

double acceptanceProbability(int currentDistance, int newDistance, double temperature);
double randomDouble();
int randomInt(int min, int max);
void printCities(vector<City> vector);

int main(){

    vector<City> cities;
    double temp = 0;
    double coolingRate = 0;
    string fileName;

    cout << "*** TSP using Simulated Annealing ***" << endl << endl;
    cout << "Starting Temperature : ";
    cin >> temp;

    cout << "\nCooling Rate: ";
    cin >> coolingRate;
    cin.ignore();

    cout << "\nPlease enter a file name (quit to end): ";
    getline(cin, fileName);

    ifstream infile(fileName, ios::in);

    if (infile.fail()) {
        cerr << "\nError: File could not be open";
        exit(1);
    }

    while (infile >> ws && !infile.eof()) {
        string city;
        int xCordinate, yCordinate;
        getline(infile, city);

        infile >> xCordinate >> yCordinate;
        City temp(city, xCordinate, yCordinate);
        cities.push_back(temp);
    }
    infile.close();

    cout << "\nCities: " << endl;
    printCities(cities);

    srand(time(0));

    Tour currentSolution;
    currentSolution.generateInitialTour(cities);

    cout << "\nInitial solution distance: " << currentSolution.getTotalDistance() << endl;
    cout << "Tour: \n";//<< currentSolution << endl;
    currentSolution.printTour();

    // We would like to keep track if the best solution
    // Assume best solution is the current solution
    Tour* best = new Tour(currentSolution.getTour());

    int testCount = 0;
    int acceptCount = 0;
    
    // Loop until system has cooled
    while (temp > 1) {
        testCount++;
        // Create new neighbour tour
        Tour newSolution(currentSolution.getTour());;

        // Get random positions in the tour
        int tourPos1 = randomInt(0, newSolution.tourSize()-1);
        int tourPos2 = randomInt(0, newSolution.tourSize()-1);

        // To make sure that tourPos1 and tourPos2 are different
        while (tourPos1 == tourPos2) { tourPos2 = randomInt(0, newSolution.tourSize()-1); }

        // Get the cities at selected positions in the tour
        City citySwap1 = newSolution.getCity(tourPos1);
        City citySwap2 = newSolution.getCity(tourPos2);

        // Swap them
        newSolution.setCity(tourPos2, citySwap1);
        newSolution.setCity(tourPos1, citySwap2);

        // Get energy of solutions
        int currentDistance = currentSolution.getTotalDistance();
        int neighbourDistance = newSolution.getTotalDistance();

        // Decide if we should accept the neighbour
        double rand = randomDouble();
        double debug = acceptanceProbability(currentDistance, neighbourDistance, temp);
        double debug2 = acceptanceProbability(currentDistance, neighbourDistance, temp);

        if (acceptanceProbability(currentDistance, neighbourDistance, temp) > rand) {
            currentSolution = Tour(newSolution.getTour());
            acceptCount++;
        }

        // Keep track of the best solution found
        if (currentSolution.getTotalDistance() < (*best).getTotalDistance()) {
            best = new Tour(currentSolution.getTour());
        }


        // Cool system
         
        temp *= (1 - coolingRate);
    }

    cout << "\n\nNumber of new states tested: " << testCount;
    cout << "\nNumber of new states accepted: " << acceptCount;


    // Print results
    cout << "\n\nFinal solution distance: " << (*best).getTotalDistance() << endl;
    cout << "Tour: \n";
    currentSolution.printTour();

    return 0;
}

// 100000 .0003 Cities.txt

/**
    * Calculates the acceptance probability
    * @param currentDistance the total distance of the current tour
    * @param newDistance the total distance of the new tour
    * @param temp the current temp
    * @return value the probability of whether to accept the new tour
    */
double acceptanceProbability(int currentDistance, int newDistance, double temperature) {
    // If the new solution is better, accept it
    if (newDistance < currentDistance) {
        return 1.0;
    }
    // If the new solution is worse, calculate an acceptance probability
    //double test = exp((currentDistance - newDistance) / temperature);
    return exp((currentDistance - newDistance) / temperature);
}

/**
 * this method returns a random number n such that
 * 0.0 <= n <= 1.0
 * @return random such that 0.0 <= random <= 1.0
 */
double randomDouble()
{
    double randNum = double(rand() % (1001)) / 1000;
    return randNum;
}

/**
 * returns a random int value within a given range
 * min inclusive .. max not inclusive
 * @param min the minimum value of the required range (int)
 * @param max the maximum value of the required range (int)
 * @return rand a random int value between min and max [min,max)
 */
int randomInt(int min, int max) {

    int randNum = (rand() % (max + 1 - min)) + min;
    return randNum;


}

void printCities(vector<City> vector) {

    for (int i = 0; i < vector.size(); i++) {
        cout << " \t " << vector.at(i).getCityName() << "\ ";
        cout << vector.at(i).getX() << " " << vector.at(i).getY() << endl;

    }
}
