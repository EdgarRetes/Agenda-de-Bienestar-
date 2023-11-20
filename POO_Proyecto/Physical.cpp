#ifndef PHYSICAL_CLASS_CPP
#define PHYSICAL_CLASS_CPP

#include <iostream>
#include <string>
#include "Event.cpp"
using namespace std;

// Incomplete

class Physical : public Event{
    private:
        float phy_percentage = 0;
    public:
        //method to set percentage attribute
        void set_phy_percentage(int events, int physical_events){
            if (events > 0){
                phy_percentage = (physical_events * 100) / float(events);
            }
        }
        // method to get percentage attribute
        float get_phy_percentage(){
            return phy_percentage;
        }   
        
};

#endif