// g++ main.cpp -o main
// ./main.exe

// terminal just "main.exe"

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>
// month class included through file
#include "Month.cpp"
using namespace std;

int main() {
    // create object month
    Month month;
    Personal personal_dim;
    Social social_dim;
    Physical physical_dim;
    Vocational vocational_dim;

    // Loop to display the calendar until the user exits.
    while (true){

        cout << "\n";
        // Call method in month object using its year and month attributes as attributes
        month.displayCalendar(month.get_year(), month.get_month());

        // Display the percentage of dimensions

        int personal = month.num_per_ev();
        int social = month.num_soc_ev();
        int physical = month.num_phy_ev();
        int vocational = month.num_voc_ev();
        int num_events = personal + social + physical + vocational;
   

        personal_dim.set_per_percentage(num_events, personal);
        social_dim.set_soc_percentage(num_events, social);
        physical_dim.set_phy_percentage(num_events, physical);
        vocational_dim.set_voc_percentage(num_events, vocational);   

        cout << "\nPersonal Dimension: " << personal_dim.get_per_percentage() << "%" <<endl;
        cout << "Social Dimension: " << social_dim.get_soc_percentage() << "%" <<endl;
        cout << "Physical Dimension: " << physical_dim.get_phy_percentage() << "%" << endl;
        cout << "Vocational Dimension: " << vocational_dim.get_voc_percentage() << "%"  << endl;


        // Display options for user
        cout << "\n";
        cout << "1. Add event\n";
        cout << "2. See events\n";
        cout << "3. Delete event\n";
        cout << "4. Exit\n";
        cout << "(1/2/3/4): ";
        int option;

        // Selection of options
        cin >> option;

        if (option == 1){
            int date;
            cout << "\nIn what day you want to add it?: ";
            cin >> date;
            // Check if the month has that day
            if (date > month.get_dayssize())
            {
                printf("\nInvalid date\n");
            }
            else{
                // Use add_event function from days vector from month in the index of the day selected
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
                month.get_day_event(date, name, type, hour, duration);
            }
        }
        else if (option == 2){
            int date;
            cout << "\nIn what day you want see the events?: ";
            cin >> date;
            while (true){
                // Use see_events function from days vector from month in the index of the day selected
                string event_info = month.get_see_events(date);
                cout << event_info;
                char close;
                cout << "\nPress any key to exit: ";
                cin >> close;
                if (close){
                    break;
                }
            }
        }
        
        else if (option == 3){
            int date;
            cout << "\nIn what day you want to delete the event?: ";
            cin >> date;
            while (true){
                // Use see_events function from days vector from month in the index of the day selected
                int check_ev = month.get_num_events(date);
                string dsp_message = month.get_see_events(date);
                cout << dsp_message;
                if (check_ev == 0){
                    break;
                }
                int event; 
                cout << "\nNumber of event to delete: ";
                cin >> event;
                // Use delete_event function from days vector from month in the index of the day selected
                string output_msg = month.get_delete_event(date, event);
                cout << output_msg;
                char close;
                cout << "\nPress any key to exit: ";
                cin >> close;
                if (close){
                    break;
                }
            }

        }
        else if (option == 4){
            printf("\nClosed succesfully\n");
            break;
        }
        else{
            printf("\nInvalid option\n");
        }

    }
    
    return 0;
}
