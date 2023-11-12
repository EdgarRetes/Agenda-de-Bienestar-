#include <iostream>
#include <string>
using namespace std;

class Event{
    public: // attributes
        string name;
        int type;
        float hour;
        float duration;
    public: // methods
        Event(string get_name, int get_type, int get_hour, int get_duration): name(get_name), type(get_type), hour(get_hour), duration(get_duration) {}
};