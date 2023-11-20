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
        // method to set percetage attribute
        void set_soc_percentage(int events, int social_events){
            if (events > 0){
                soc_percentage = (social_events * 100) / float(events);
            }
        }
        // method to get percentage attribute
        float get_soc_percentage(){
            return soc_percentage;
        }
        
};

#endif