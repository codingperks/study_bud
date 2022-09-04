//
// Created by Ryan Perkins on 23/08/2022.
// Last edited on 30/08/2022
//

#include "pomodoro.h"
#include "requirements.h"

void Pomodoro::pomodoroTimer() const{ // count down a pomodoro timer - pause and play functionality
    int user_seconds = (m_pomMinutes * 60); // convert minutes to seconds

    // Convert seconds to MM:SS timer
    int display_minutes {};
    display_minutes = (user_seconds / 60);

    while (user_seconds >= 1) // visual indication of timer remaining
    {
        if (int(user_seconds%60 == 0)){ // formatting to display 00 instead of 0
            std::cout << "\rPomodoro time remaining: " << int(display_minutes%60) << ':' << "00"
                      << std::flush;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        else {
            std::cout << "\rPomodoro time remaining: " << int(display_minutes % 60) << ':' << int(user_seconds % 60)
                      << std::flush;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        user_seconds--;
        display_minutes = (user_seconds / 60);
    }

    std::cout << "\nPomodoro timer complete (don't forget to drink water)!\n";
}

void Pomodoro::shortBreakTimer() const{
    int user_seconds = (m_shortBreak * 60); // convert minutes to seconds

    // Convert seconds to MM:SS timer
    int display_minutes {};
    display_minutes = (user_seconds / 60);

    while (user_seconds >= 1) // visual indication of timer remaining
    {
        if (int(user_seconds%60 == 0)){ // formatting to display 00 instead of 0
            std::cout << "\rShort break time remaining: " << int(display_minutes%60) << ':' << "00"
                      << std::flush;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        else {
            std::cout << "\rShort break time remaining: " << int(display_minutes % 60) << ':' << int(user_seconds % 60)
                      << std::flush;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        user_seconds--;
        display_minutes = (user_seconds / 60);
    }

    std::cout << "\nShort break complete!\n";
}

void Pomodoro::longBreakTimer() const{
    int user_seconds = (m_longBreak * 60); // convert minutes to seconds

    // Convert seconds to MM:SS timer
    int display_minutes {};
    display_minutes = (user_seconds / 60);

    while (user_seconds >= 1) // visual indication of timer remaining
    {
        if (int(user_seconds%60 == 0)){ // formatting to display 00 instead of 0
            std::cout << "\rLong break time remaining: " << int(display_minutes%60) << ':' << "00"
                      << std::flush;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        else {
            std::cout << "\rLong break time remaining: " << int(display_minutes % 60) << ':' << int(user_seconds % 60)
                      << std::flush;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        user_seconds--;
        display_minutes = (user_seconds / 60);
    }

    std::cout << "\nLong break complete!\n";
}

int Pomodoro::pomodoroCounter(int timerCounter){ // increment and return counters
    return timerCounter += 1;
}

void Pomodoro::pomodoroCounterReset(int timerCounter){
     timerCounter = 0;
}

void Pomodoro::longBreakTarget(){
    std::cout << "Would you like to change the number of pomodoros required for a long break?\n";
    std::cout << "[1] Yes\n[2] No\n";
    int option {};
    while (true) {
        std::cin >> option;

        while(std::cin.fail()) { // Integer error handling
            std::cout << "Error, please type a number!" << std::endl;
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cout << "Would you like to change the number of pomodoros required for a long break?\n";
            std::cout << "[1] Yes\n[2] No\n";
            std::cin >> option;
        }

        if (option == 1) {
            int target{};
            std::cout << "What would you like to change this target to? (default is 4): ";
            std::cin >> target;

            while(std::cin.fail()) { // Integer error handling
                std::cout << "Error, please type a number!" << std::endl;
                std::cin.clear();
                std::cin.ignore(256,'\n');
                std::cout << "What would you like to change this target to? (default is 4): ";
                std::cin >> target;
            }

            m_longBreakTarget = target;
            std::cout << "You have changed your long break target to: " << m_longBreakTarget << '\n';
            break;
        }
        else if (option == 2){
            break;
        }
    }
}

void Pomodoro::pomodoroOutputSettings() const {
    std::cout << "The current pomodoro timer setting is " << m_pomMinutes << " minutes.\n";
    std::cout << "The current short break timer setting is " << m_shortBreak << " minutes.\n";
    std::cout << "The current long break timer setting is " << m_longBreak << " minutes.\n";
    std::cout << "The target number of pomodoros before a long break is " << m_longBreakTarget << "\n\n";
}

void Pomodoro::pomodoroSettings(){ // adjust default settings
    // Adjust pomodoro default timer
    std::cout << "The pomodoro default timer is 25 minutes, would you like to change this?\n"
        << "[1] Yes\n[2] No\n";

    while(true){
        int option {};
        std::cin >> option;

        while(std::cin.fail()) { // Integer error handling
            std::cout << "Error, please type a number!" << std::endl;
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cout << "The pomodoro default timer is 25 minutes, would you like to change this?\n"
                      << "[1] Yes\n[2] No\n";
            std::cin >> option;
        }

        if (option == 2){ // Selection of 'No'
            break;
        }
        else if (option == 1) { // Selection of 'Yes'
            int setting {};
            std::cout << "Please type in minutes how long you'd like the pomodoro timer to be: ";
            std::cin >> setting;
            m_pomMinutes = setting;
            break;
        }

        else{
            std::cout << "Invalid selection\n"
            << "The pomodoro default timer is 25 minutes, would you like to change this?\n" << "[1] Yes\n[2] No\n";
        }
    }

    // Adjust short break timer
    std::cout << "The short break timer is 5 minutes, would you like to change this?\n"
              << "[1] Yes\n[2] No\n";

    while(true){
        int option {};
        std::cin >> option;

        while(std::cin.fail()) { // Integer error handling
            std::cout << "Error, please type a number!" << std::endl;
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cout << "The short break timer is 5 minutes, would you like to change this?\n"
                      << "[1] Yes\n[2] No\n";
            std::cin >> option;
        }

        if (option == 2){ // Selection of 'No'
            break;
        }
        else if (option == 1) { // Selection of 'Yes'
            int setting {};
            std::cout << "Please type in minutes how long you'd like the short break timer to be: ";
            std::cin >> setting;
            m_shortBreak = setting;
            break;
        }

        else{
            std::cout << "Invalid selection\n"
                      << "The short break default timer is 5 minutes, would you like to change this?\n"
                      << "[1] Yes\n[2] No\n";
        }
    }
    // Adjust long break timer
    std::cout << "The long break timer is 20 minutes, would you like to change this?\n"
              << "[1] Yes\n[2] No\n";

    while(true){
        int option {};
        std::cin >> option;

        while(std::cin.fail()) { // Integer error handling
            std::cout << "Error, please type a number!" << std::endl;
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cout << "The long break timer is 5 minutes, would you like to change this?\n"
                      << "[1] Yes\n[2] No\n";
            std::cin >> option;
        }

        if (option == 2){ // Selection of 'No'
            break;
        }
        else if (option == 1) { // Selection of 'Yes'
            int setting {};
            std::cout << "Please type in minutes how long you'd like the long break timer to be: ";
            std::cin >> setting;
            m_longBreak = setting;
            break;
        }

        else{
            std::cout << "Invalid selection\n"
                      << "The long break default timer is 20 minutes, would you like to change this?\n"
                      << "[1] Yes\n[2] No\n";
        }
    }
}