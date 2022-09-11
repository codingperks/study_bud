//
// Created by Ryan Perkins on 23/08/2022.
//

#include "requirements.h"
#include "diary.h"
#include "utilities.h"

void Diary::displayDiary(){  // prints the current diary goals
    std::cout << "\nCurrent diary\n"; // for tidiness of visuals

    if (m_diary.empty()){ // If user tries to check an empty diary
        std::cout << "Diary is empty!\n";
    }

    else {
        for (int i = 1; i < m_diary.size() + 1; i++){
            std::cout << "Diary entry " << i << " is: " << m_diary[i - 1]
            << " - Status: " << m_diary_status[i-1] << '\n';
        }
    }
    std::cout << '\n'; // for tidiness of visuals
}

std::string Diary::enterGoal(){ // allows user entry of goals
    std::cout << "Enter a goal: ";
    std::string goal {};
    std::getline(std::cin >> std::ws, goal);

    return goal;
}

void Diary::addGoal (const std::string& goal){ // adds user entered goals
    m_diary.push_back(goal);
    std::cout << "Added '" << goal << "' to diary!\n\n";
}

int Diary::enterGoalStatus() {
    std::cout << "What is the status of this goal?\n";

    int goal_status{};
    while (true) {
        std::string status {"[1] Planned\n[2] In-progress\n[3] Completed\n"
                            "Please type the index of goal status here: "};
        std::cout << status;
        std::cin >> goal_status;
        int max_range = 3;

        goal_status = integerHandling(goal_status, max_range,
                        status,-1);

        std::cout <<'\n';

        return goal_status;
    }
}

void Diary::addGoalStatus(const int& goal_status){
    switch (goal_status){
        case (0):
            m_diary_status.emplace_back("Planned");
            break;
        case (1):
            m_diary_status.emplace_back("In-progress");
            break;
        case (2):
            m_diary_status.emplace_back("Completed");
            break;
    }
}

void Diary::editGoal(){ // allows user to edit diary entries
    // Diary entry selection
    Diary::displayDiary();

    while (true) {
        if ((m_diary.empty())) {
            break;
        }
        int n_goal{};
        std::string status {"Please type the index of goal you'd like to edit: "};
        std::cout << status;
        std::cin >> n_goal;

        n_goal = integerHandling(n_goal, m_diary.size(),
                        status, -1);

        if (n_goal == -1){ // type zero for exit
            break;
        }

        else if (n_goal > m_diary.size()) { // error catching
            std::cout << "Incorrect entry\n";
        }

        // Diary update
        else {
            std::string edited_goal {};
            std::cout << "Type update here: ";
            std::getline(std::cin >> std::ws, edited_goal);
            m_diary[n_goal] = edited_goal;
            while (true) {
                int edited_goal_status = enterGoalStatus();
                switch (edited_goal_status) {
                    case (0):
                        m_diary_status[n_goal] = ("Planned");
                        break;
                    case (1):
                        m_diary_status[n_goal] = ("In-progress");
                        break;
                    case (2):
                        m_diary_status[n_goal] = ("Completed");
                        break;
                    }
                    break;
                }
            break;
            }
        }
    }

void Diary::deleteGoal(){ // allows user to delete diary entries
    Diary::displayDiary();
    std::string status {"Please type the index of goal you'd like to delete: "};
    std::cout << status;

    while (true) { // infinite loop to catch erroneous input
        int n_goal{};
        std::cin >> n_goal;

        n_goal = integerHandling(n_goal, m_diary.size(),
                                 status, 0);

        if (n_goal <= m_diary.size()) {
            m_diary.erase(m_diary.begin() + n_goal - 1); // delete entry
            m_diary_status.erase(m_diary_status.begin() + n_goal - 1); // delete status entry
            std::cout << "Entry deleted!\n";
            break;
        }

    }
}

void Diary::saveDiary() {
    // Set file stream object
    std::ofstream diary_export;

    // Rename confirmation
    while (true) {
        std::string status {"Would you like to name this diary? (Default name uses {Day, Month, Day, HH.MM.SS, 2022}"
                            " format)\n[1] Yes\n[2] No\n"};
        std::cout << status;

        int rename_confirmation{};
        std::cin >> rename_confirmation;

        rename_confirmation = integerHandling(rename_confirmation, m_diary.size(),
                                        status , 0);

        if (rename_confirmation == 1){
            std::string entry{};
            int max_characters {31};
            do {
                // Set export path - string entry
                std::cout << "What would you like to name this diary? (max characters = 31)\n";
                std::getline(std::cin >> std::ws, entry);

            } while (forbiddenChar(entry) || checkStringLength(entry, max_characters));
            // check for forbidden characters & string length

            // Set export name using current date and time
            diary_export.open("diary_output/" + entry + ".csv");

            // Export diary entries
            diary_export << "Index,Goal,Status\n"; // csv headers

            for (int i{0}; i < m_diary.size(); i++) {
                static int diary_index{1};
                diary_export << std::to_string(diary_index) << ',' << m_diary[i] << ',' << m_diary_status[i]
                             << '\n';
                diary_index++;
            }

        diary_export.close();
        break;
        }

        else {
            // Set export path - use current date and time for naming
            time_t now = time(nullptr);
            std::string dt = ctime(&now);     // convert now to string form
            dt = std::regex_replace(dt, std::regex(":"), "."); // replace colons with periods for filename

            // Set export name using current date and time
            const std::string &export_name{dt};
            diary_export.open("diary_output/" + export_name + ".csv");

            // Export diary entries
            diary_export << "Index,Goal,Status\n"; // csv headers

            for (int i{0}; i < m_diary.size(); i++) {
                static int diary_index{1};
                diary_export << std::to_string(diary_index) << ',' << m_diary[i] << ',' << m_diary_status[i] << '\n';
                diary_index++;
            }
            diary_export.close();
            break;
        }
    }
}

void Diary::loadDiary() {
    // Set import path
    std::string path = "diary_output/";

    std::vector<std::filesystem::directory_entry> diary_files; // to create a vector of filenames

    int index{1};
    for (const auto &entry: std::filesystem::directory_iterator(path)) {
        std::cout << index << " " << entry.path() << std::endl;
        index++;
        diary_files.push_back(entry); // add filename to vector
    }

    while (true) {
        std::string status {"Select the index of a diary you would like to load: "};
        std::cout << status;
        int import_index{};
        std::cin >> import_index;

        import_index = integerHandling(import_index, index,
                                       status , 0);

        if (import_index <= diary_files.size() && import_index > 0) {
            //if selected index is less than/equal to the number of files

            // Delete diary confirmation
            std::string status_2 {"Loading a diary will overwrite your previous diary, are you happy to proceed?\n"
                                "1] Yes\n[2] No\n"};
            std::cout << status_2;

            int delete_confirmation{};
            std::cin >> delete_confirmation;
            int max_range = 2;

            delete_confirmation = integerHandling(delete_confirmation, max_range,
                                           status_2 , 0);

            if (delete_confirmation == 1){ // Respondent confirming (Yes)
                // Reset diary
                m_diary.clear();
                m_diary_status.clear();

                std::string selected_diary{diary_files[import_index - 1].path()};
                std::ifstream diary_import(selected_diary);

                std::string line{};
                std::vector<std::string> diary_csv{}; // vector to hold csv lines

                while (std::getline(diary_import, line, '\n')) {
                    diary_csv.push_back(line); // add csv lines to a vector
                }

                diary_csv.erase(diary_csv.begin()); // drop header row

                for (auto row: diary_csv) {
                    std::string goal = row.substr(1, row.find(',')); // position 1 is always goal
                    std::string status = row.substr(2, row.find(',')); // position 2 is always status

                    size_t first_comma_pos = row.find(','); // denote position of first comma
                    row.erase(0, first_comma_pos + 1); // delete everything prior to location, including comma

                    // Add goal to diary
                    std::string goal_csv{};

                    size_t second_comma_pos = row.find(','); // denote position of first comma
                    goal_csv = row.substr(0, second_comma_pos);
                    m_diary.push_back(goal_csv);

                    // Add status to diary
                    std::string status_csv{};
                    status_csv = row.substr(second_comma_pos + 1, row.length());
                    m_diary_status.push_back(status_csv);

                }
                std::cout << "Diary loaded!\n";
                break;
            }
            else if (delete_confirmation == 2) {
                break;
                }
            else {
                std::cout << "Error, please select a number above!" << std::endl;
                std::cin.clear();
                std::cin.ignore(256, '\n');
                }
            }
        else {
            std::cout << "Invalid selection!\n";
            }
        }
}
