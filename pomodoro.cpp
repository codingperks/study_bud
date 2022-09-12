//
// Created by Ryan Perkins on 23/08/2022.
// Last edited on 30/08/2022
//

#include "pomodoro.h"
#include "requirements.h"
#include "utilities.h"

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
    std::cout << "\a"; // play beep
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
    std::cout << "\a"; // play beep
    std::cout << "\nShort break complete!\n";
}

void Pomodoro::longBreakTimer() const{
    int user_seconds = (m_longBreak * 60); // convert minutes to seconds

    // Convert seconds to MM:SS timer
    int display_minutes = (user_seconds / 60);

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
    std::cout << "\a"; // play beep
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
        int menu_range {2};

        option = integerHandling(option, menu_range, "Would you like to change the number of "
                                                     "pomodoros required for a long break?"
                                                     "[1] Yes\n[2] No\n", 0);

        if (option == 1) {
            int target{};
            std::cout << "What would you like to change this target to? (default is 4): ";
            std::cin >> target;
            int max_range = 100; // set high max range for function below

            target = integerHandling(target, max_range,
                                     "What would you like to change this target to? (default is 4, max is 100): ",
                                     0);

            m_longBreakTarget = target;
            std::cout << "You have changed your long break target to: " << m_longBreakTarget << '\n';
            break;
        }
        else {
            break;
        }
    }
}

void Pomodoro::pomodoroOutputSettings() const {
    std::cout << "The current pomodoro timer setting is " << m_pomMinutes << " minutes.\n";
    std::cout << "The current short break timer setting is " << m_shortBreak << " minutes.\n";
    std::cout << "The current long break timer setting is " << m_longBreak << " minutes.\n";
    std::cout << "The target number of pomodoros before a long break is " << m_longBreakTarget << ".\n\n";
}

void Pomodoro::pomodoroSettings(){ // adjust default settings
    // Adjust pomodoro default timer
    std::string status_pom {"The pomodoro default timer is 25 minutes, would you like to change this?\n"
                            "[1] Yes\n[2] No\n"};
    std::cout << status_pom;

    while(true){
        int option {};
        std::cin >> option;
        int menu_range {2};

        option = integerHandling(option, menu_range, status_pom, 0);

        if (option == 2){ // Selection of 'No'
            break;
        }

        else if (option == 1) { // Selection of 'Yes'
            int setting {};
            std::string status_pom_2 = "Please type in minutes how long you'd like the pomodoro timer to be "
                                       "(max is 1440): ";
            std::cout << status_pom_2;
            std::cin >> setting;

            int max_range {1440};
            setting = integerHandling(setting, max_range, status_pom_2, 0);

            m_pomMinutes = setting;
            std::cout << '\n';
            break;
        }
    }

    // Adjust short break timer
    std::string status_short {"The short break default timer is 5 minutes, would you like to change this?\n"
                              "[1] Yes\n[2] No\n"};
    std::cout << status_short;

    while(true){
        int option {};
        std::cin >> option;
        int menu_range {2};

        option = integerHandling(option, menu_range, status_short, 0);

        if (option == 2){ // Selection of 'No'
            break;
        }
        else if (option == 1) { // Selection of 'Yes'
            int setting {};
            std::string status_short_2 {"Please type in minutes how long you'd like the short break timer to be "
                                        "(max is 1440): "};
            std::cout << status_short_2;
            std::cin >> setting;

            int max_range {1440};
            setting = integerHandling(setting, max_range, status_short_2, 0);

            m_shortBreak = setting;
            std::cout << '\n';
            break;
        }
    }
    // Adjust long break timer
    std::string status_long {"The long break default timer is 20 minutes, would you like to change this?\n"
                             "[1] Yes\n[2] No\n"};
    std::cout << status_long;

    while(true){
        int option {};
        std::cin >> option;
        int menu_range {2};

        option = integerHandling(option, menu_range, status_long, 0);

        if (option == 2){ // Selection of 'No'
            break;
        }

        else if (option == 1) { // Selection of 'Yes'
            int setting {};
            std::string status_long_2 {"Please type in minutes how long you'd like the long break timer to be "
                                        "(max is 1440): "};
            std::cout << status_long_2;
            std::cin >> setting;

            int max_range {1440};
            setting = integerHandling(setting, max_range, status_long_2, 0);

            m_longBreak = setting;
            std::cout << '\n';
            break;
        }
    }
}