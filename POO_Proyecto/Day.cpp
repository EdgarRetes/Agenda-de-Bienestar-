#include <iostream>
#include <vector>
#include <string>
// event class included through file
#include "Personal.cpp"
#include "Social.cpp"
#include "Physical.cpp"
#include "Vocational.cpp"
using namespace std;

class Day{
    private: //attributes
        int num_day;
        // Vector for all the event objects the day has
        vector<Event> events;
        vector<Social> soc_events;
        vector<Personal> per_events;
        vector<Physical> phy_events;
        vector<Vocational> voc_events;

    public: // methods


        // itterate throught all the events in the specific day
        int event_iterate(int type){
            int event_match = 0;
            for (int i = 0; i < events.size(); i++){
                if (events[i].type_getter() == type){
                    event_match++;
                }
            }
            return event_match;
        }

        // get the count of events
        int count_events(){
            return events.size();
        }

        // Gett num_day attribute from day object
        Day(int number) : num_day(number){}

        // Display day in terminal
        void display_day(char space){
            // Condition to check if there are events in the specific day. If there are events display how many events.
            if (!events.empty()){
                if (num_day > 9){
                    printf(" Events: %2i  %i|", events.size(), num_day);
                }
                else{
                    printf(" Events: %2i   %i|", events.size(), num_day);
                }
            }
            // If there are not any events display the day empty
            else{
                printf("%15i|", num_day);
            }
        }

        // method to add events to the day

        void add_event(string name, int type, float hour, float duration){

            // creates an event inheritance object with the parameters
            if (type == 1){
                Personal e;
                e.set_name(name);
                e.set_type(type);
                e.set_hour(hour);
                e.set_duration(duration);
                //add to the vector attributes the objects
                events.push_back(e);
                per_events.push_back(e);
            }
            
            else if (type == 2){
                Social e;
                e.set_name(name);
                e.set_type(type);
                e.set_hour(hour);
                e.set_duration(duration);
                events.push_back(e); 
                soc_events.push_back(e);
            }
            else if (type == 3){
                Physical e;
                e.set_name(name);
                e.set_type(type);
                e.set_hour(hour);
                e.set_duration(duration);
                events.push_back(e);
                phy_events.push_back(e);

            }
            else if (type == 4){
                Vocational e;
                e.set_name(name);
                e.set_type(type);
                e.set_hour(hour);
                e.set_duration(duration);
                events.push_back(e);
                voc_events.push_back(e);
            }
            else{
                cout << "Error";
            }
            
        }

        // function to check the events i an specific day
        int see_events(void){
            // valdiate if there are events
            if (events.empty()){
                printf("\nThere are no events for this day\n");
                return 0;
            }
            // display the evnts in the terminal
            else{
                for (int i = 0; i < events.size(); i++){
                
                    cout << "\nEvent " << i + 1 << ":" << endl;
                    cout << "Name: " << events[i].name_getter() << endl;
                    string types[4] = {"Personal", "Social", "Physical", "Vocational"};
                    cout << "Type: " << types[events[i].type_getter()] << endl;
                    cout << "Hour: " << events[i].hour_getter()<< endl;
                    cout << "Duration: " << events[i].duration_getter() << endl;
                }
            
                return 1;
            }
        }

        // function to delete events
        int delete_event(int event){
            if (events.empty()){
                printf("\nThere are no events for this day\n");
                return 0;
            }
            else if(event > events.size() || event < 1)
            {
                printf("\nThat event doesn't exist\n");
                return 0;
            }
            else{
                events.erase(events.begin() + (event - 1));
                 printf("\nEvent deleted succesfully\n");
                 return 1;
            }
        }

        

};