#ifndef PHYSICAL_CLASS_CPP
#define PHYSICAL_CLASS_CPP

#include <iostream>
#include <string>
#include "Event.cpp"
using namespace std;

class Physical : public Event{
    private:
        float phy_percentage = 0;
    public:
        // Method that sets the phy_percentage attribute using events and physicial_events parameters
        void set_phy_percentage(int events, int physical_events);

        // Method that returns the phy_percentage parameter
        float get_phy_percentage();
        
};

void Physical::set_phy_percentage(int events, int physical_events){
    if (events > 0){
        phy_percentage = (physical_events * 100) / float(events);
    }
}

float Physical::get_phy_percentage(){
    return phy_percentage;
}  

#endif