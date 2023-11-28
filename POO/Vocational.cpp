#ifndef VOCATIONAL_CLASS_CPP
#define VOCATIONAL_CLASS_CPP

#include <iostream>
#include <string>
#include "Event.cpp"
using namespace std;

class Vocational : public Event{
    private:
        float voc_percentage = 0;
    public: 
        // Method that sets the voc_percentage attribute using events and vocational_events parameters
        void set_voc_percentage(int events, int vocational_events);

        // Method that return teh voc_percentage attribute
        float get_voc_percentage();
        
};

void Vocational::set_voc_percentage(int events, int vocational_events){
    if (events > 0){
        voc_percentage = (vocational_events * 100) / float(events);
    }
}

float Vocational::get_voc_percentage(){
    return voc_percentage;
}

#endif