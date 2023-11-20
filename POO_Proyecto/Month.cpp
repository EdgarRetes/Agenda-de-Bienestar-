#include <iostream>
#include <vector>
#include <string>
// day class included through file
#include "Day.cpp"
using namespace std;

class Month {
private: // attributes
    int year = 2023;
    int month_num = 11;
    // Vector for all day objects in the month
    vector<Day> days;
    // Get name of month as string
    string getMonthName(int month) {
        string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        string get_month = months[month - 1]; 
        return get_month; 
    }
public: // methods

    // get the number of events in the month

    int get_num_events(int date){
        int events;
        events = days[date-1].count_events();
        return events;
    }

    // get the event deleted
    void get_delete_event(int date, int event){
        days[date-1].delete_event(event);
    }

    // get the day with the events it has
    void get_see_events(int date){
        days[date-1].see_events();
    }

    // get day to add event
    void get_day_event(int date, string name, int type, float hour, float duration){
        days[date-1].add_event(name, type, hour, duration);
    }

    // get the size of days vector
    int get_dayssize(){
        return days.size();
    }

    // get the year attribute
    int get_year(){
        return year;
    }

    // get the month attribute
    int get_month(){
        return month_num;
    }

    // Function that displays calendar in the terminal

    void displayCalendar(int year, int month) {

        cout << getMonthName(month) << " " << year << endl;
        cout << "---------------------------------------------------------------------------------------------------------------"<< endl;
        cout << "      Mon      |      Tue      |      Wed      |      Thur     |      Fri      |      Sat      |      Sun      |"<< endl;
        cout << "---------------------------------------------------------------------------------------------------------------"<< endl;
        
        // Day_num determines in which day of the week the month starts
        int day_num = -1;
        char space = ' ';
        
        // Condition to check if the days exist or not.If they don't exists create the day objects.
        if (days.empty()){
            for (int i = 0; i < 5; i++){
                for (int j = 0; j < 7; j++){
                    if (day_num > 0 && day_num < 31){
                        // Create day object with its number attribute
                        Day d (day_num);
                        // Add the day to the vector
                        days.push_back(d);
                        // Call display_day function from the specific day
                        d.display_day(space);
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
        // Display the calendar with the day objects already created
        else {
            for (int i = 0; i < 5; i++){
                for (int j = 0; j < 7; j++){
                    if (day_num > 0 && day_num < 31){
                        // Call display_day function from the specific day
                        days[day_num-1].display_day(space);
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

    int num_per_ev(){
        int per_event = 0;
        for (int i = 0; i < days.size(); i++){
            per_event += days[i].event_iterate(1);
        }
        
        return per_event;
    }

    int num_soc_ev(){
        int soc_event = 0;
        for (int i = 0; i < days.size(); i++){
            soc_event += days[i].event_iterate(2);
        }
        
        return soc_event;
    }

    int num_phy_ev(){
        int phy_event = 0;
        for (int i = 0; i < days.size(); i++){
            phy_event += days[i].event_iterate(3);
        }
        
        return phy_event;
    }

    int num_voc_ev(){
        int voc_event = 0;
        for (int i = 0; i < days.size(); i++){
            voc_event += days[i].event_iterate(4);
        }
        
        return voc_event;
    }


};
