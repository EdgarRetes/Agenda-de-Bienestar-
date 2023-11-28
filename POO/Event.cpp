#ifndef EVENT_CLASS_CPP
#define EVENT_CLASS_CPP

#include <iostream>
#include <string>
using namespace std;

class Event{
    protected: // attributes
        string name;
        int type;
        float hour;
        float duration;

    public: // methods
        
        // // Method that sets the name parameter
        void set_name(string get_name);

        // // Method that sets the type parameter
        void set_type(int get_type);

        // Method that sets the hour parameter
        void set_hour(float get_hour);

        // Method that sets the duration attribute
        void set_duration(float get_duration);
        
        // Method that returns the name parameter
        string name_getter();
        
        // Method that returns the type parameter
        int type_getter();

        // Method that returns the hour parameter
        float hour_getter();

        // Method that returns the duration parameter
        float duration_getter();


};

void Event::set_name(string get_name){
    name = get_name;
}

void Event::set_type(int get_type){
    type = get_type;

}

void Event::set_hour(float get_hour){
    hour = get_hour;

}

void Event::set_duration(float get_duration){
    duration = get_duration;
}

string Event::name_getter(){
    return name;
}

int Event::type_getter(){
    return type;
}

float Event::hour_getter(){
    return hour;
}

float Event::duration_getter(){
    return duration;
}

#endif