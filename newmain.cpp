//COMSC-210 | LAB 30 | AHMAD DHARHAN

//Header definitions
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
#include <array>
#include <iterator>

using namespace std;

//Function Protoypes
void find_high_avg();
void find_avg_avg();
void find_low_avg();
void check_weather();
void display_city(map<int, list<int>> city);

const int SIZE = 34;
const int TEMP_SIZE = 3;

int main(){

    int choice = 0;
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

    int high,low,avg;
    for(int i = 1; i <= SIZE; i++){
        file >> high >> low >> avg;
        city1[i] = {high, low, avg};
    }

    for(int i = 1; i <= SIZE; i++){
        file >> high >> low >> avg;
        city2[i] = {high, low, avg};
    }

    for(int i = 1; i <= SIZE; i++){
        file >> high >> low >> avg;
        city3[i] = {high, low, avg};
    }

    file.close();

    while(choice != 4){
        cout << "*****************" << endl;
        cout << "Weather Simulator" << endl;
        cout << "*****************" << endl;
        
        cout << "1. City1" << endl;
        cout << "2. City2" << endl;
        cout << "3. City3" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;

        switch(choice){
            case 1:

                break;
            
            case 2:

                break;

            case 3:

                break;

            case 4:
                return 0;
        }
    }

    for(map<int,list<int>>::iterator it = city1.begin();
    it != city1.end(); ++it){

        cout << "Day " << it->first << " [CITY 1]: ";

        for(auto temp: it->second){
            cout << temp << " ";
        }
        cout << endl;
        cout << endl;
    }

    for(map<int,list<int>>::iterator it = city2.begin();
    it != city2.end(); ++it){

        cout << "Day " << it->first << " [CITY 2]: ";

        for(auto temp: it->second){
            cout << temp << " ";
        }
        cout << endl;
        cout << endl;
    }

    for(map<int,list<int>>::iterator it = city3.begin();
    it != city3.end(); ++it){

        cout << "Day " << it->first << " [CITY 3]: ";

        for(auto temp: it->second){
            cout << temp << " ";
        }
        cout << endl;
        cout << endl;
    }

    return 0;
}

void display_city(map<int, list<int>> city){

   for(map<int,list<int>>::iterator it = city.begin();
    it != city.end(); ++it){

        cout << "Day " << it->first << ": ";

        for(auto temp: it->second){
            cout << temp << " ";
        }
        cout << endl;
        cout << endl;
    }
}

void find_high_avg(){

}

void find_low_avg(){

}

void find_avg_avg(){

}

void check_weather(){

}
   