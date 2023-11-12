#include <iostream>
#include <vector>
#include <string>
#include "day_class.cpp"
using namespace std;

class Month {
public: // attributes
    int year = 2023;
    int month_num = 11;
    vector<Day> days;
    string getMonthName(int month) {
        string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        string get_month = months[month - 1]; 
        return get_month; 
    }
public: // methods
    void displayCalendar(int year, int month) {

        cout << getMonthName(month) << " " << year << endl;
        cout << "---------------------------------------------------------------------------------------------------------------"<< endl;
        cout << "      Mon      |      Tue      |      Wed      |      Thur     |      Fri      |      Sat      |      Sun      |"<< endl;
        cout << "---------------------------------------------------------------------------------------------------------------"<< endl;
        int day_num = -1;
        char space = ' ';
        if (days.empty()){
            for (int i = 0; i < 5; i++){
                for (int j = 0; j < 7; j++){
                    if (day_num > 0 && day_num < 31){
                        Day d (day_num);
                        days.push_back(d);
                        d.display_day(day_num, space);
                    }
                    else{
                        printf("%15c|", space);
                    }
                    day_num++;
                }
                cout << endl;
                cout << "---------------------------------------------------------------------------------------------------------------"<< endl;
            }
        }
        else {
            for (int i = 0; i < 5; i++){
                for (int j = 0; j < 7; j++){
                    if (day_num > 0 && day_num < 31){
                        days[day_num-1].display_day(day_num, space);
                    }
                    else{
                        printf("%15c|", space);
                    }
                    day_num++;
                }
                cout << endl;
                cout << "---------------------------------------------------------------------------------------------------------------"<< endl;
            }

        }
    }

};
