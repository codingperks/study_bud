//
// Created by Ryan Perkins on 23/08/2022.
// Last updated 30/08/2022.
//

#include "requirements.h"
#include "diary.h"

/*void Diary::mapDiary(){
    std::map<std::string, int> diary_map;
    diary_map[m_diary[0]] = m_diary_status[0];
}*/


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
        std::cout << "[1] Planned\n[2] In-progress\n[3] Completed\n";
        std::cout << "Please type the index of goal status here (type 0 to exit): ";
        std::cin >> goal_status;
        goal_status = goal_status - 1; // subtract for index searching

        while (std::cin.fail() || goal_status >= 3) { // Integer error handling
            std::cout << "Error, please select from the numbers above!" << std::endl;
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cout << "Please type the index of goal status here (type 0 to exit):";
            std::cin >> goal_status;
            goal_status = goal_status - 1;
        }

        if (goal_status == -1) {
            break;
        }

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
        std::cout << "Please type the index of goal you'd like to edit (type 0 to exit): ";
        std::cin >> n_goal;

        while(std::cin.fail()) { // Integer error handling
            std::cout << "Error, please type a number!" << std::endl;
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cout << "Please type the index of goal you'd like to edit (type 0 to exit): ";
            std::cin >> n_goal;
        }
        n_goal = n_goal - 1; // subtract for index searching

        if (n_goal == -1){ // type zero for exit
            break;
        }

        else if (n_goal >= m_diary.size()) { // error catching
            std::cout << "Incorrect entry\n";
        }

        // Diary update
        else {
            std::string edited_goal {};
            std::cout << "Type update here: ";
            std::getline(std::cin >> std::ws, edited_goal);
            m_diary[n_goal] = edited_goal;
            while (true) {
                int edited_goal_status {};
                edited_goal_status = enterGoalStatus();
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
    std::cout << "Please type the index of goal you'd like to delete: ";

    while (true) { // infinite loop to catch erroneous input
        int n_goal{};
        std::cin >> n_goal;

        while(std::cin.fail()) { // Integer error handling
            std::cout << "Error, please type a number!" << std::endl;
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cout << "Please type the index of goal you'd like to delete: ";
            std::cin >> n_goal;
        }

        if (n_goal <= m_diary.size()) {
            m_diary.erase(m_diary.begin() + n_goal - 1); // delete entry
            m_diary_status.erase(m_diary_status.begin() + n_goal - 1); // delete status entry
            std::cout << "Entry deleted!\n";
            break;
        }
        else {
            std::cout << "Invalid selection!\nPlease type the index of the goal you'd like to delete: ";
        }
    }
}

void Diary::saveDiary(){
    // Set file stream object
    std::ofstream diary_export;

    // Set export path - use current date and time for naming
    time_t now = time(nullptr);
    std::string dt = ctime(&now);     // convert now to string form

    // Set export name using current date and time
    const std::string& export_name {dt};
    diary_export.open("diary_output/" + export_name + ".csv");

    // Export diary entries
    diary_export << "Index,Goal,Status\n"; // csv headers

    for (int i {0}; i < m_diary.size(); i++){
            static int diary_index{1};
            diary_export << std::to_string(diary_index) << ',' << m_diary[i] << ',' << m_diary_status[i] << '\n';
            diary_index++;
        }
    diary_export.close();
}

void Diary::loadDiary(){

}

