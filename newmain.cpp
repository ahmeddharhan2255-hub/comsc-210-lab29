//COMSC-210 | LAB 30 | AHMAD DHARHAN

//Header definitions
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
#include <array>

using namespace std;

//Function Protoypes
void find_high_avg();
void find_avg_avg();
void find_low_avg();

const int SIZE = 34;

int main(){

    //Each map represents a city
    //Values represent a day
    //List represents that days high, lows, and avg
    map<int, list<int>> city1;
    map<int, list<int>> city2;
    map<int, list<int>> city3;

    ifstream file("weatherData.txt");

    if(!file.is_open()){
        cout << "Data could not be retrieved" << endl;
    }

    string input;
    int high,low,avg;
    while(getline(file,input)){
        
    }



    return 0;
}