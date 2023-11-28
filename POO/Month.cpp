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

    public: // methods

        // Gets the name of the month according to the numebr of month taken as parameter
        string getMonthName(int month);

        // Gunction that calls the count_events fucntion from day class returning the number of events in the date passed as a parameter
        int get_num_events(int date);

        // Function thatt calls delete_event function from day class and returns if teh event was found and deleted using date and event parameters
        string get_delete_event(int date, int event);

        // Function that calls see_events function from the day class, returning the information fo events in the day passed as parameter
        string get_see_events(int date);

        // Function that calls add_event fucntion from day class passing it the date, type, hoyr and duration parameters)
        void get_day_event(int date, string name, int type, float hour, float duration);

        // Getter function that returns size of the days vector
        int get_dayssize();

        // Getter function that returns year attribute
        int get_year();

        // Getter function that returns month attribute
        int get_month();

        // Function that displays calendar in the terminal using the year and month parameters. This calendar is made with characters and each day created is an object.
        // Each day displayed has a desiganted space so the terminal can be manipulated without affecting all characters in the terminal.
        void displayCalendar(int year, int month);

        // Function to get the number of personal events by itereting through all the events in the day and matching their type to add to the counter which is the return value
        int num_per_ev();

        // Function to get the number of social events by itereting through all the events in the day and matching their type to add to the counter which is the return value
        int num_soc_ev();

        // Function to get the number of physical events by itereting through all the events in the day and matching their type to add to the counter which is the return value
        int num_phy_ev();

        // Function to get the number of vocational events by itereting through all the events in the day and matching their type to add to the counter which is the return value
        int num_voc_ev();

};

string Month::getMonthName(int month) {
    string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    string get_month = months[month - 1]; 
    return get_month; 
}

int Month::get_num_events(int date){
    int events;
    events = days[date-1].count_events();
    return events;
}

string Month::get_delete_event(int date, int event){
    string output_msg = days[date-1].delete_event(event);
    return output_msg;
}

string Month::get_see_events(int date){
    string dsp_info = days[date-1].see_events();
    return dsp_info;
}

void Month::get_day_event(int date, string name, int type, float hour, float duration){
    days[date-1].add_event(name, type, hour, duration);
}

int Month::get_dayssize(){
    return days.size();
}

int Month::get_year(){
    return year;
}

int Month::get_month(){
    return month_num;
}

void Month::displayCalendar(int year, int month) {

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

int Month::num_per_ev(){
    int per_event = 0;
    for (int i = 0; i < days.size(); i++){
        per_event += days[i].event_iterate(1);
    }
    return per_event;
}

int Month::num_soc_ev(){
    int soc_event = 0;
    for (int i = 0; i < days.size(); i++){
        soc_event += days[i].event_iterate(2);
    }
    return soc_event;
}

int Month::num_phy_ev(){
    int phy_event = 0;
    for (int i = 0; i < days.size(); i++){
        phy_event += days[i].event_iterate(3);
    }
    return phy_event;
    }

int Month::num_voc_ev(){
    int voc_event = 0;
    for (int i = 0; i < days.size(); i++){
        voc_event += days[i].event_iterate(4);
    }  
    return voc_event;
}
