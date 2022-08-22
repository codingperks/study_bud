//
// Created by Ryan Perkins on 18/08/2022.
//

/* Functionality to/do
 * Create a sound once timer is finished
 * Start timer again once message acknowledged
 * */

#include "requirements.h"
#include "water.h"

int userEntry(){ // Function to take user entry
    std::cout << "Please set your timer interval in minutes: ";
    int interval {};
    std::cin >> interval;

    return interval;
}

void waterTimer(int minutes){ // water_timer functionality
   int user_seconds {};
   user_seconds = (minutes); // convert minutes to seconds don't forget to add

   std::cout << "Timer started for " << minutes << " minute(s).\n";

   std::this_thread::sleep_for(std::chrono::seconds(user_seconds));

   std::cout << "Don't forget to drink water!\n";
}

std::string confirmWarning(){
    std::cout << "Would you like to start a water timer? Type Y to confirm: ";
    std::string confirm {};
    std::cin >> confirm;
    return confirm;
}

void water() { // Main for calling in main.cpp
    while (true) {
        // User enters in minutes timer interval
        int minutes{userEntry()};
        // Timer uses minutes to operate timer
        waterTimer(minutes);
        // play sound - to implement
        // confirm / deny
        std::string confirm {confirmWarning()};
        if (confirm == "Y" | confirm == "y") // confirmation clause - user confirm to restart timer or not
        {
            continue;
        }
        else
        {
            break;
        }
    }
}