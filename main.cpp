#include "requirements.h"
#include "water.h"
#include "diary.h"

int main() {
    while (true) {
        // Options menu
        int option{};
        do {
            std::cout << "\nWelcome to the study bud!\n" << "Please select an option:\n"
                      << "[1] Diary\n" << "[2] Timer\n" << "[3] Exit\n";
            std::cin >> option;
            std::cin.clear(); // to remove erroneous enter presses from cin
            std::cin.get();

            switch (option) { // Diary menu
                case 1:
                    int diary_option{};
                    do {
                        std::cout << "Diary\n" << "Please select an option:\n"
                                  << "[1] View diary\n" << "[2] Enter goal\n" << "[3] Edit goal\n"
                                  << "[4] Delete goal\n" << "[5] Exit\n";

                        std::cin >> diary_option;
                        std::cin.clear(); // to remove erroneous enter presses from cin
                        std::cin.get();

                        static Diary diary{}; // instantiate diary object

                        switch (diary_option) {
                            case 1:
                                diary.displayDiary();
                                break;
                            case 2:
                                diary.addGoal({Diary::enterGoal()});
                                break;
                            case 3:
                                diary.editGoal();
                                break;
                            case 4:
                                diary.deleteGoal();
                                break;
                            default:
                                break;
                        }
                    } while (diary_option < 5);
            }
        } while (option != 3);
        return 0;
    }
}
