#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class FoodItem {
public:
    void Print();
    void PrintNutritionFacts();
    FoodItem(string Fname = "Unnamed", int Fcalories = 0, int Ftotalfat = 0, int Ftotalsugar = 0, int Fprotein = 0, int Fsodium = 0);
    FoodItem operator+(FoodItem f);
    
private:
    string name;
    int calories;
    int totalfat;
    int totalsugar;
    int protein;
    int sodium;
};

#endif