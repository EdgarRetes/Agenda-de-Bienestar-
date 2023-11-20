#ifndef VOCATIONAL_CLASS_CPP
#define VOCATIONAL_CLASS_CPP

#include <iostream>
#include <string>
#include "Event.cpp"
using namespace std;

// Incomplete

class Vocational : public Event{
    private:
        float voc_percentage = 0;
    public: 
        // method to set percentage attribute 
        void set_voc_percentage(int events, int vocational_events){
            if (events > 0){
                voc_percentage = (vocational_events * 100) / float(events);
            }
        }
        // method to get percentage attribute
        float get_voc_percentage(){
            return voc_percentage;
        }
        
};

#endif