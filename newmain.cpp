//COMSC-210 | LAB 30 | AHMAD DHARHAN

//Header definitions
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
#include <iterator>

using namespace std;

//Function Protoypes
void find_high_avg(map<int, list<int>> city);
void find_avg_avg(map<int, list<int>> city);
void find_low_avg(map<int, list<int>> city);
void check_weather(map<int, list<int>> city, int day);
void display_all_data(map<int, list<int>> city);
void recommendation(map<int, list<int>> city, int day);

const int SIZE = 34;

int main(){

    int choice = 0;
    int day;
    int city_choice;
    //Each map represents a city
    //Values represent a day
    //List represents that days high, lows, and avg
    map<int, list<int>> city1;
    map<int, list<int>> city2;
    map<int, list<int>> city3;

    ifstream file("weatherData.txt");

    if(!file.is_open()){
        cout << "Data could not be retrieved" << endl;
        return 1;
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
        cout << endl;

        switch(choice){
            case 1:
                cout << "What would you like to view" << endl;
                cout << "1. Weather for a specific day" << endl;
                cout << "2. All recorded temperatures in the past 34 days" << endl;
                cout << "3. Average of all temp categories" << endl;
                cin >> city_choice;

                if (city_choice == 1){
                    cout << "What Day(1-34)?" << endl;
                    cin >> day;

                    if(day < 1 || day > 34){
                        cout << "Invalid Input" << endl;
                        cin.clear();
                        cin.ignore(10000, '\n');
                        break;
                    }
                    check_weather(city1, day);
                    recommendation(city1, day);
                    break; 
                }
                else if (city_choice == 2){
                    display_all_data(city1);
                    break;
                }
                else if(city_choice == 3){
                    find_high_avg(city1);
                    find_low_avg(city1);
                    find_avg_avg(city1);
                    break;
                }
                else{
                    cin.clear();
                    cin.ignore(10000, '\n');
                    break;
                }

            case 2:
                cout << "What would you like to view" << endl;
                cout << "1. Weather for a specific day" << endl;
                cout << "2. All recorded temperatures in the past 34 days" << endl;
                cout << "3. Average of all temp categories" << endl;
                cin >> city_choice;

                if (city_choice == 1){
                    cout << "What Day(1-34)?" << endl;
                    cin >> day;
                    check_weather(city2, day);
                    recommendation(city2, day);
                    break; 
                }
                else if (city_choice == 2){
                    display_all_data(city2);
                    break;
                }
                else if(city_choice == 3){
                    find_high_avg(city2);
                    find_low_avg(city2);
                    find_avg_avg(city2);
                    break;
                }
                else{
                    cin.clear();
                    cin.ignore(10000, '\n');
                    break;
                }

            case 3:
                cout << "What would you like to view" << endl;
                cout << "1. Weather for a specific day" << endl;
                cout << "2. All recorded temperatures in the past 34 days" << endl;
                cout << "3. Average of all temp categories" << endl;
                cin >> city_choice;

                if (city_choice == 1){
                    cout << "What Day(1-34)?" << endl;
                    cin >> day;
                    check_weather(city3, day);
                    recommendation(city3, day);
                    break; 
                }
                else if (city_choice == 2){
                    display_all_data(city3);
                    break;
                }
                else if(city_choice == 3){
                    find_high_avg(city3);
                    find_low_avg(city3);
                    find_avg_avg(city3);
                    break;
                }
                else{
                    cin.clear();
                    cin.ignore(10000, '\n');
                    break;
                }

            case 4:
                return 0;
            default:
                cout << "Your input was Invalid! Enter numbers shown on menu!" << endl;

                cin.clear();
                cin.ignore(10000,'\n');
                break;
        }
    }
    
    return 0;
}

void display_all_data(map<int, list<int>> city){

   for(map<int,list<int>>::iterator it = city.begin();
    it != city.end(); ++it){

        cout << "Day " << it->first << ": ";

        for(auto temp: it->second){
            cout << temp << "F ";
        }
        cout << endl;
        cout << endl;
    }
}

void find_high_avg(map<int, list<int>> city){

    double sum = 0;

   for(map<int,list<int>>::iterator it = city.begin();
    it != city.end(); ++it){

        sum += it->second.front();

    }
    cout << "High Average: ";
    cout << sum / SIZE << "F " << endl;
}

void find_low_avg(map<int, list<int>> city){

    double sum = 0;

   for(map<int,list<int>>::iterator it = city.begin();
    it != city.end(); ++it){

        auto temp = it->second.begin();
        sum += *next(temp);
    }

    cout << "Low Average: ";
    cout << sum / SIZE << "F " << endl;
}

void find_avg_avg(map<int, list<int>> city){

    double sum = 0;

   for(map<int,list<int>>::iterator it = city.begin();
    it != city.end(); ++it){

        auto temp = it->second.begin();
        sum += *next(temp,2);
    }
    cout << "Average of Average Temps: ";
    cout << sum / SIZE << "F " << endl;
    cout << endl;
}

void check_weather(map<int, list<int>> city, int day){

    auto it = city.find(day);

    if(it != city.end()){

        for(auto temp: it->second){
            cout << temp << "F ";
        }

    }
    else{
        cout << "Invalid Day! try again!" << endl;
    }
}

void recommendation(map<int, list<int>> city, int day){

    auto it = city.find(day);

    if (it == city.end()){
        cout << "Invalid day!" << endl;
        return;
    }

    int high = it->second.front();

    if (high < 70){
        cout << "It seems to be a litle cold. Recommend wearing a ";
        cout << "jacket or staying inside!" << endl;
    }
    else if (high > 70){
        cout << "Seems to be on the hotter side. Good day to go out with sunscreen!" << endl;
    }
    else if (high == 70){
        cout << "Great weather! Have a blast!" << endl;
    }

}
