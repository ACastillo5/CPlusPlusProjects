#include <iostream>
#include <vector>
#include "food.h"

using namespace std;


int main(){
    
    vector <FoodItem> Buffet;
    FoodItem Food;
    
    //Apple Nutrition
    FoodItem Apple("Apple", 95, 0, 19, 1, 2);
    
    Buffet.push_back(Apple);
    
    //Fries Nutrition
    FoodItem FFries("French Fries", 365, 17, 2, 4, 246);
    
    Buffet.push_back(FFries);
    
    //Cheeseburger Nutrition
    FoodItem CBurger("Cheeseburger", 535, 29, 7, 30, 1176);
    
    Buffet.push_back(CBurger);
    
    //Instant Ramen Nutrition
    FoodItem IRamen("Instant Ramen", 384, 15, 1, 10, 1163);
    
    Buffet.push_back(IRamen);
    
    //Protein Bar Nutrition
    FoodItem PBar("Protein Bar", 211, 5, 12, 20, 115);
    
    Buffet.push_back(PBar);
    
    //Pizza Slice Nutrition
    FoodItem Pizza("Pizza Slice", 285, 10, 4, 12, 640);
    
    Buffet.push_back(Pizza);
    
    //Fried Chicken Nutrition
    FoodItem FryChicken("Fried Chicken", 377, 21, 0, 40, 118);
    
    Buffet.push_back(FryChicken);
    
    //Taco Nutrition
    FoodItem Taco("Taco", 210, 10, 2, 10, 571);
    
    Buffet.push_back(Taco);
    
    //Filet Mignon Nutrition
    FoodItem FilMignon("Filet Mignon", 900, 72, 1, 59, 1117);
    
    Buffet.push_back(FilMignon);
    
    //Beef Wellingtion Nutrition
    FoodItem BWellington("Beef Wellingtion", 453, 34, 1, 18, 256);
    
    Buffet.push_back(BWellington);
    
    //Total Nutrition
    FoodItem Total("Total Nutrition", 0, 0, 0 , 0, 0);
    
    Buffet.push_back(Total);
    
    
    Food.Print();
    
  //This boolean helps the program not crash 
    bool done = false;
    while (done == false){
        
        int choice;
        cin >> choice;
        
        
        if (choice == 1){
            Total = Total + Apple;
            Food.Print();
        }
        else if (choice == 2){
            Total = Total + FFries;
            Food.Print();
        }
        else if (choice == 3){
            Total = Total + CBurger;
            Food.Print();
        }
        else if (choice == 4){
            Total = Total + IRamen;
            Food.Print();
        }
        else if (choice == 5){
            Total = Total + PBar;
            Food.Print();
        }
        else if (choice == 6){
            Total = Total + Pizza;
            Food.Print();
        }
        else if (choice == 7){
            Total = Total + FryChicken;
            Food.Print();
        }
        else if (choice == 8){
            Total = Total + Taco;
            Food.Print();
        }
        else if (choice == 9){
            Total = Total + FilMignon;
            Food.Print();
        }
        else if (choice == 10){
            Total = Total + BWellington;
            Food.Print();
        }
        else if (choice == 11){
            Total.PrintNutritionFacts();
            exit(0);
        }
        else{
            Food.Print();
            cout << "Please enter a valid choice" << endl;
        }
        
    }
    
        return 0;
}