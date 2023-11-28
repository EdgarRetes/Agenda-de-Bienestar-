#ifndef DAY_CLASS_CPP
#define DAY_CLASS_CPP

#include <iostream>
#include <vector>
#include <string>
// event class included through file
#include "Personal.cpp"
#include "Social.cpp"
#include "Physical.cpp"
#include "Vocational.cpp"
#include "Day.h"
using namespace std;

class Day{
    private: //attributes
        int num_day;
        // Vector for all the event objects the day has
        vector<Event> events;
        vector<Social> soc_events;
        vector<Personal> per_events;
        vector<Physical> phy_events;
        vector<Vocational> voc_events;

    public: // methods

        // Day constructor using the parameter number
        Day(int number);

        // Itterate throught all the events in the specific day using type parameter
        int event_iterate(int type);

        // Get the count of events returning the number of events in the day
        int count_events();

        // Display day in terminal using the space parameter for desing 
        void display_day(char space);

        // method to add events to the day with name, type, hour and duration parameters to add them to their specific vector
        void add_event(string name, int type, float hour, float duration);

        // function to check the events in an specific day returning the information of the events in that day
        string see_events();

        // function to delete events using the parameter of the event selected to delete them from the vector
        string delete_event(int event);

};

Day::Day(int number){
    num_day = number;
}

int Day::event_iterate(int type){
    int event_match = 0;
    for (int i = 0; i < events.size(); i++){
        if (events[i].type_getter() == type){
            event_match++;
        }
    }
    return event_match;
}

int Day::count_events(){
    return events.size();
}

void Day::display_day(char space){
    // Condition to check if there are events in the specific day. If there are events display how many events.
    if (!events.empty()){
        if (num_day > 9){
            printf(" Events: %2i  %i|", events.size(), num_day);
        }
        else{
            printf(" Events: %2i   %i|", events.size(), num_day);
        }
    }
    // If there are not any events display the day empty
    else{
        printf("%15i|", num_day);
    }
}

 void Day::add_event(string name, int type, float hour, float duration){

    // creates an event inheritance object with the parameters
    if (type == 1){
        Personal e;
        e.set_name(name);
        e.set_type(type);
        e.set_hour(hour);
        e.set_duration(duration);
        //add to the vector attributes the objects
        events.push_back(e);
        per_events.push_back(e);
    }
            
    else if (type == 2){
        Social e;
        e.set_name(name);
        e.set_type(type);
        e.set_hour(hour);
        e.set_duration(duration);
        events.push_back(e); 
        soc_events.push_back(e);
    }
    else if (type == 3){
        Physical e;
        e.set_name(name);
        e.set_type(type);
        e.set_hour(hour);
        e.set_duration(duration);
        events.push_back(e);
        phy_events.push_back(e);

    }
    else if (type == 4){
        Vocational e;
        e.set_name(name);
        e.set_type(type);
        e.set_hour(hour);
        e.set_duration(duration);
        events.push_back(e);
        voc_events.push_back(e);
    }
    else{
        printf("Error");
    }
            
}

string Day::see_events(){
    // valdiate if there are events
    if (events.empty()){
            return "\nThere are no events for this day\n";
    }
    // display the evnts in the terminal
    else{
        string info;
        for (int i = 0; i < events.size(); i++){
                
            string event = "\nEvent " + to_string(i+1) + ":\n";
            string name = "Name: " + events[i].name_getter() + "\n";
            string types[4] = {"Personal", "Social", "Physical", "Vocational"};
            string type = "Type: " + types[events[i].type_getter()] + "\n";
            string hour = "Hour: " + (to_string(events[i].hour_getter())).substr(0,5) + "\n";
            string duration = "Duration: " + (to_string(events[i].duration_getter())).substr(0,5) + "\n";
            info += event + name + type + hour + duration + "\n";

        }
            
        return info;
    }
}

string Day::delete_event(int event){
    if (events.empty()){
        return "\nThere are no events for this day\n";
    }
    else if(event > events.size() || event < 1)
    {
        return "\nThat event doesn't exist\n";
    }
    else{
        events.erase(events.begin() + (event - 1));
        return "\nEvent deleted succesfully\n";
    }
}

#endif
