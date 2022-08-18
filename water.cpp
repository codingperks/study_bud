//
// Created by Ryan Perkins on 18/08/2022.
//

/* Functionality
 * Set an interval
 * Start a timer for this interval
 * Create a message/sound once timer is finished
 * Start timer again once message acknowledged
 *
 *
 * */

#include "requirements.h"
#include "water.h"

using namespace std; // adding using command here for readability
using namespace chrono;

int userEntry(){
    cout << "Please set your timer interval in minutes: ";
    int interval {};
    cin >> interval;

    return interval;
}

void displayTimer(){

}

void water_timer(int minutes){
   int user_seconds {};
   user_seconds = (minutes * 60); // convert minutes to seconds

   cout << "\nTimer started\n";

   std::this_thread::sleep_for(chrono::seconds(user_seconds));

   cout << "Don't forget to drink water!";

}


int water(){
    // user entry (seconds)
    int minutes{userEntry()};
    cout << minutes;
    // timer functionality
    water_timer(minutes);
    // display timer
    // play sound
    // confirm / deny
}

int main()
{
    thread th(water);

    // water();

    th.join();
    return 0;
}