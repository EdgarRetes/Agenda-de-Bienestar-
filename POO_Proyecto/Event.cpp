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
        
        // method to set name attribute
        void set_name(string get_name){
            name = get_name;
        }

        // method to set type attribute
        void set_type(int get_type){
            type = get_type;

        }

        // method to set hour attribute
        void set_hour(float get_hour){
            hour = get_hour;

        }

        // method to set duration attribute
        void set_duration(float get_duration){
            duration = get_duration;

        }
        
        // method to get the name attribute
        string name_getter(){
            return name;
        }
        
        //method to get type atribute
        int type_getter(){
            return type;
        }

        // method to get hour attribute
        float hour_getter(){
            return hour;
        }
        // method to get duration attribte
        float duration_getter(){
            return duration;
        }


};

#endif