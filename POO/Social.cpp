#ifndef SOCIAL_CLASS_CPP
#define SOCIAL_CLASS_CPP

#include <iostream>
#include <string>
#include "Event.cpp"
using namespace std;


class Social : public Event{
    private:

        float soc_percentage = 0;
    public:
        // Method that sets the soc_percentage attribute using events and social_events parameters
        void set_soc_percentage(int events, int social_events);

        // Method that returns the soc_percentage parameter
        float get_soc_percentage();
        
};

void Social::set_soc_percentage(int events, int social_events){
    if (events > 0){
        soc_percentage = (social_events * 100) / float(events);
    }
}

float Social::get_soc_percentage(){
    return soc_percentage;
}

#endif