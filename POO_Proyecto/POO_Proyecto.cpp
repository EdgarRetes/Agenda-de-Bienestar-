#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include "month_class.cpp"
using namespace std;


int main() {
    Month month;
    while (true){

        cout << "\n";
        month.displayCalendar(month.year, month.month_num);
        cout << "\n";
        cout << "1. Add event\n";
        cout << "2. See events\n";
        cout << "3. Delete event\n";
        cout << "4. Exit\n";
        cout << "(1/2/3/4): ";
        int option;
        cin >> option;

        if (option == 1){
            int date;
            cout << "\nIn what day you want to add it?: ";
            cin >> date;
            if (date > month.days.size())
            {
                printf("\nInvalid date\n");
            }
            else{
            month.days[date-1].add_event();
            }
        }
        else if (option == 2){
            int date;
            cout << "\nIn what day you want see the events?: ";
            cin >> date;
            while (true){
                month.days[date-1].see_events();
                char close;
                cout << "Press any key to exit: ";
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
                int check_ev = month.days[date-1].see_events();
                if (check_ev == 0){
                    break;
                }
                int event; 
                cout << "\nNumber of event to delete: ";
                cin >> event;
                month.days[date-1].delete_event(event);
                char close;
                cout << "Press any key to exit: ";
                cin >> close;
                if (close){
                    break;
                }
            }

        }
        else if (option == 4){
            printf("Closed succesfully\n");
            break;
        }
        else{
            printf("Invalid option\n");
        }

    }
    

    return 0;
}
