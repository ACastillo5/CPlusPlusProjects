#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double haversine(double lat1, double long1, double lat2, double long2, double radius){

    double x1 = (lat2 - lat1) * (M_PI / 180.0);
    double x2 = (long2 - long1) * (M_PI / 180.0);
    
    lat1 = lat1 * (M_PI / 180.0);
    lat2 = lat2 * (M_PI / 180.0);
    
    
    double n = pow(sin(x1/2.0),2.0) + pow(sin(x2/2.0),2.0) * cos(lat1) * cos(lat2);
    
    double final = 2.0 * radius * asin(sqrt(n));
    
    return final;
    
}
//Converting Degree to Radians

double getFlightTime(double lat1, double long1, double lat2, double long2, double radius, double speed){
    
    double final = haversine(lat1, long1, lat2, long2, radius);
    
    return final/speed;
    
}

int main(){
    
    double lat1;
    double lat2;
    
    double long1;
    double long2;
    
    double radius = 3958.8;
    
    double jetSpeed = 500;
    
    double d;
    double flightTime;
    
    vector<string> locations;
    vector<double> lats;
    vector<double> longs;
    
    //Names of Locations
    locations.push_back("Miami Beach, FL, USA");  
    lats.push_back(25.793449);
    longs.push_back(80.139198);
    
    locations.push_back("Fargo, ND, USA");
    lats.push_back(46.877186);
    longs.push_back(-96.789803);
    
    locations.push_back("Idaho City, ID, USA");
    lats.push_back(43.828850);
    longs.push_back(-115.837860);
    
    locations.push_back("Monroe, LA, USA");
    lats.push_back(32.509930);
    longs.push_back(-92.121742);
    
    locations.push_back("Dodge City, KS, USA");
    lats.push_back(37.753098);
    longs.push_back(-100.024872);
    
    locations.push_back("Lewes, DE, USA");
    lats.push_back(38.781082);
    longs.push_back(-75.157150);
        
    locations.push_back("Sterling, CO, USA");
    lats.push_back(40.626743);
    longs.push_back(-103.217026);
    
    locations.push_back("Toledo, OH, USA");
    lats.push_back(41.651031);
    longs.push_back(-83.541939);
    
    locations.push_back("Plankinton, SD, USA");
    lats.push_back(43.714790);
    longs.push_back(-98.484451);
    
    locations.push_back("Peabody, MA, USA");
    lats.push_back(42.536457);
    longs.push_back(-70.985786);
    
    
    cout << "Enter the number of your beginning location" << endl;
    int i2 = 1;
    
    for(int i = 0; i < locations.size(); i++){
        cout << i2 << ") " << locations[i] << "   " << lats[i] << "   " << longs[i] << endl;
        i2++;
    }
    
    int choice1;
    cin >> choice1;
    
    i2 = 1;
    
    cout << "Enter the number of your ending location" << endl;
    for(int i = 0; i < locations.size(); i++){
        cout << i2 << ") " << locations[i] << " " << lats[i] << " " << longs[i] << endl;
        i2++;
    }
    
    int choice2;
    cin >> choice2;
    
    lat1 = lats[choice1 - 1];
    
    lat2 = lats[choice2 - 1];
    
    long1 = longs[choice1 - 1];
    
    long2 = longs[choice2 - 1];
    
 
    //Distance 
    d = haversine(lat1, long1, lat2, long2, radius);
    cout << "The distance between the 2 points is : " << d << " miles." << endl;
    
    flightTime = getFlightTime(lat1, long1, lat2, long2, radius,jetSpeed);
    cout << "The flight time will be : " << flightTime << " hours." << endl;
    
    return 0;
}