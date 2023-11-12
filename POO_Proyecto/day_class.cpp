#include <iostream>
#include <vector>
#include <string>
#include "event_class.cpp"
using namespace std;

class Day{
    public: //attributes
        int num_day;
        vector<Event> events;

    public: // methods

        Day(int number) : num_day(number){}

        void display_day(int day, char space){
            if (!events.empty()){
                if (day > 9){
                    printf(" Events: %2i  %i|", events.size(), day);
                }
                else{
                    printf(" Events: %2i   %i|", events.size(), day);
                }
            }
            else{
                printf("%15i|", day);
            }
        }

        void add_event(void){
            string name;
            int type;
            float hour;
            float duration;
            cout << "\nName: ";
            cin >> name;
            cout << "Type (Personal-1, Social-2, Physical-3, Vocational-4): ";
            cin >> type;
            cout << "Hour: ";
            cin >> hour;
            cout << "Duration: ";
            cin >> duration;

            Event e(name, type, hour, duration);
            events.push_back(e);

        }

        int see_events(void){
            if (events.empty()){
                printf("\nThere are no events for this day\n");
                return 0;
            }
            else{
                for (int i = 0; i < events.size(); i++){
                    cout << "\nEvent " << i + 1 << ":" << endl;
                    cout << "Name: " << events[i].name << endl;
                    string types[4] = {"Personal", "Social", "Physical", "Vocational"};
                    cout << "Type: " << types[events[i].type] << endl;
                    cout << "Hour: " << events[i].hour << endl;
                    cout << "Duration: " << events[i].duration << endl;
                }
                return 1;
            }
        }

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