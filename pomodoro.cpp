//
// Created by Ryan Perkins on 23/08/2022.
// Last edited on 30/08/2022
//

#include "pomodoro.h"
#include "requirements.h"

void Pomodoro::pomodoroTimer(){ // count down a pomodoro timer - pause and play functionality
    int user_seconds {};
    user_seconds = (m_pomMinutes * 60); // convert minutes to seconds

    while (user_seconds >= 1) // visual indication of timer remaining
    {
        std::cout << "\rPomodoro time remaining: " << user_seconds << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        user_seconds--;
    }

    std::cout << "\nPomodoro timer complete (don't forget to drink water)!\n";
}

void Pomodoro::shortBreakTimer(){
    int user_seconds {};
    user_seconds = (m_shortBreak * 60); // convert minutes to seconds

    while (user_seconds >= 1) // visual indication of timer remaining
    {
        std::cout << "\rShort break time remaining: " << user_seconds << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        user_seconds--;
    }

    std::cout << "\nShort break complete!\n";
}

void Pomodoro::longBreakTimer(){
    int user_seconds {};
    user_seconds = (m_longBreak * 60); // convert minutes to seconds

    while (user_seconds >= 1) // visual indication of timer remaining
    {
        std::cout << "\rLong break time remaining: " << user_seconds << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        user_seconds--;
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
        if (option == 1) {
            int target{};
            std::cout << "What would you like to change this target to? (default is 4): ";
            std::cin >> target;
            m_longBreakTarget = target;
            std::cout << "You have changed your long break target to: " << m_longBreakTarget;
            break;
        }
        else if (option == 2){
            break;
        }
    }
}

void Pomodoro::pomodoroOutputSettings() {
    std::cout << "The current pomodoro timer setting is " << m_pomMinutes << " minutes.\n";
    std::cout << "The current short break timer setting is " << m_shortBreak << " minutes.\n";
    std::cout << "The current long break timer setting is " << m_longBreak << " minutes.\n";
    std::cout << "The target number of pomodoros before a long break is " << m_longBreakTarget << "\n";
}


void Pomodoro::pomodoroSettings(){ // adjust default settings
    // Adjust pomodoro default timer
    std::cout << "The pomodoro default timer is 25 minutes, would you like to change this?\n"
        << "[1] Yes\n[2] No\n";

    while(true){
        int option {};
        std::cin >> option;
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



