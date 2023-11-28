#ifndef PERSONAL_CLASS_CPP
#define PERSONAL_CLASS_CPP

#include <iostream>
#include <string>
#include "Event.cpp"
using namespace std;


class Personal : public Event{
    private:
        float per_percentage = 0;
    public:
    
        // Method that sets the per_percentage attribute using events and personal_events parameters
        void set_per_percentage(int events, int personal_events);

        // Method that returns the per_percentage attribute
        float get_per_percentage();
};

void Personal::set_per_percentage(int events, int personal_events){
    if (events > 0){
        per_percentage = (personal_events * 100) / float(events);
    }
}

float Personal::get_per_percentage(){
    return per_percentage;
}

#endif