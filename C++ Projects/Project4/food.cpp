#include <iostream>
#include <vector>
#include "food.h"

void FoodItem::Print() {
    cout << "Please enter one of the food choices below: " << endl;
    cout << "1. Apple " << endl;
    cout << "2. French Fries " << endl;
    cout << "3. Cheeseburger " << endl;
    cout << "4. Instant Ramen " << endl;
    cout << "5. Protein Bar " << endl;
    cout << "6. Pizza Slice " << endl;
    cout << "7. Fried Chicken " << endl;
    cout << "8. Taco " << endl;
    cout << "9. Filet Mignon " << endl;
    cout << "10. Beef Wellington " << endl;
    cout << "11. Finished " << endl;
}

void FoodItem::PrintNutritionFacts() {
    cout << "Your total nutrition for the day is:" << endl;
    cout << "Total" << endl;
    cout << "Calories: " << calories << endl;
    if (calories > 2000){
        cout << "You have exceeded the recommended intake of Calories for an average adult" << endl;
    }
    cout << "Fat (g): " << totalfat << endl;
    if (totalfat > 70){
        cout << "You have exceeded the recommended intake of Total Fat for an average adult" << endl;
    }
    cout << "Sugars (g): " << totalsugar << endl;
    if (totalsugar > 30){
        cout << "You have exceeded the recommended intake of Total Sugar for an average adult" << endl;
    }
    cout << "Protein (g): " << protein << endl;
    if (protein > 50){
        cout << "You have exceeded the recommended intake of Protein for an average adult" << endl;
    }
    cout << "Sodium (mg): " << sodium << endl;
    if (sodium > 2300){
        cout << "You have exceeded the recommended intake of Sodium for an average adult" << endl;
    }
}

FoodItem::FoodItem(string Fname, int Fcalories, int Ftotalfat, int Ftotalsugar, int Fprotein, int Fsodium) {
   name  = Fname;
   calories = Fcalories;
   totalfat= Ftotalfat;
   totalsugar = Ftotalsugar;
   protein  = Fprotein;
   sodium = Fsodium;
}

FoodItem FoodItem::operator+(FoodItem f) {
   FoodItem totalNutri;

   totalNutri.calories = calories + f.calories;
   totalNutri.totalfat = totalfat + f.totalfat;
   totalNutri.totalsugar = totalsugar + f.totalsugar;
   totalNutri.protein = protein + f.protein;
   totalNutri.sodium = sodium + f.sodium;
   
   return totalNutri;
}
