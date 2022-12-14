#include "requirements.h"
#include "diary.h"
#include "pomodoro.h"
#include "utilities.h"

int main() {
    while (true) {
        // Options menu
        int option{};
        do {
            std::cout << "Welcome to the Study Bud!\n" << "Please select an option:\n"
                      << "[1] Diary\n"
                      << "[2] Timer\n"
                      << "[0] Exit\n";
            std::cin >> option;
            std::cin.clear(); // to remove erroneous enter presses from cin
            std::cin.get();

            switch (option) {
                case 1: { // Diary menu
                    int diary_option{};
                    do {
                        std::cout << "Diary\n" << "Please select an option:\n"
                                  << "[1] View diary\n"
                                  << "[2] Enter goal\n"
                                  << "[3] Edit goal\n"
                                  << "[4] Delete goal\n"
                                  << "[5] Save diary\n"
                                  << "[6] Load diary\n"
                                  << "[0] Exit\n";

                        diary_option = {};
                        std::cin >> diary_option;
                        std::cin.clear(); // to remove erroneous enter presses from cin
                        std::cin.get();

                        static Diary diary{}; // instantiate diary object

                        switch (diary_option) {
                            case 1: // Print diary
                                diary.displayDiary();
                                break;
                            case 2: // Allow user to enter goal
                                diary.addGoal({Diary::enterGoal()});
                                diary.addGoalStatus({Diary::enterGoalStatus()});
                                break;
                            case 3: // Allow user to edit goal
                                diary.editGoal();
                                break;
                            case 4: // Allow user to delete goal
                                diary.deleteGoal();
                                break;
                            case 5: // Allow user to export diary to diary_output folder
                                diary.saveDiary();
                                break;
                            case 6:
                                diary.loadDiary();
                                break;
                            case 0:
                                break;
                            default:
                                break;
                        }
                    } while (diary_option != 0);
                    std::cin.clear();
                    break;
                }
                case 2: // Timer menu
                {
                    int timer_option{};
                    do {
                        std::cout << "Timer\n" << "Please select an option:\n"
                                  << "[1] Start pomodoro timer\n"
                                  << "[2] Check timer settings\n"
                                  << "[3] Adjust timer lengths\n"
                                  << "[4] Reset pomodoro counter\n"
                                  << "[5] Adjust long break target intervals\n"
                                  << "[0] Exit\n";

                        std::cin >> timer_option;
                        std::cin.clear(); // to remove erroneous enter presses from cin
                        std::cin.get();

                        static Pomodoro pomodoro{}; // instantiate diary object
                        static int timerCounter = 0; // instantiate number of timers completed

                        switch (timer_option) {
                            case 1: // Starting pomodoro timer
                                pomodoro.pomodoroTimer();
                                timerCounter = Pomodoro::pomodoroCounter(timerCounter);
                                std::cout << "You have completed " << timerCounter << " pomodoro(s)!\n";

                                if (timerCounter == pomodoro.m_longBreakTarget) {
                                    timerCounter = 0; // reset counters
                                    std::cout << "It's time for a long break.\n";
                                    std::cout << "Would you like to start the long break timer or exit?\n";

                                    int longBreakOption{};
                                    do {
                                        std::cout << "[1] Start timer\n[2] Exit\n";
                                        std::cin >> longBreakOption;

                                        if (longBreakOption == 1) {
                                            pomodoro.longBreakTimer();
                                            break;
                                        }
                                    } while (longBreakOption != 2);
                                } else {
                                    std::cout << "It's time for a short break.\n";
                                    std::cout << "Would you like to start the short break timer or exit?\n";

                                    int shortBreakOption{};
                                    do {
                                        std::cout << "[1] Start timer\n[2] Exit\n";
                                        std::cin >> shortBreakOption;

                                        if (shortBreakOption == 1) {
                                            pomodoro.shortBreakTimer();
                                            break;
                                        }
                                    } while (shortBreakOption != 2);
                                }
                                break;
                            case 2: // Checking pomodoro settings
                                pomodoro.pomodoroOutputSettings();
                                break;
                            case 3: // Changing pomodoro settings
                                pomodoro.pomodoroSettings();
                                break;
                                break;
                            case 4: // Resetting pomodoro counter
                                std::cout << "You have reset your counter of " << timerCounter << " to 0.\n";
                                Pomodoro::pomodoroCounterReset(timerCounter);
                                break;
                            case 5: // Setting pomodoro target for long breaks
                                pomodoro.longBreakTarget();
                                break;
                            default:
                                break;
                        }
                    } while (timer_option != 0);
                }
            }
        } while (option != 0);
        break;
    }
    return 0;
}