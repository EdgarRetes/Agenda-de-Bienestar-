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
    
        // method to set percentage attribute
        void set_per_percentage(int events, int personal_events){
            if (events > 0){
                per_percentage = (personal_events * 100) / float(events);
            }
        }
        // method to get percentage attribute
        float get_per_percentage(){
            return per_percentage;
        }
};

#endif