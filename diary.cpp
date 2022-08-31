//
// Created by Ryan Perkins on 23/08/2022.
// Last updated 30/08/2022.
//

#include "requirements.h"
#include "diary.h"

void Diary::displayDiary(){  // prints the current diary goals
    int i {};
    std::cout << "\nCurrent diary\n"; // for tidiness of visuals

    if (m_diary.empty()){ // If user tries to check an empty diary
        std::cout << "Diary is empty!\n";
    }

    else {
        for (i = 1; i < m_diary.size() + 1; i++){
            std::cout << "Diary entry " << i << " is: " << m_diary[i - 1] << '\n';
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
        n_goal = n_goal - 1; // subtract for index searching

        while(std::cin.fail()) { // Integer error handling
            std::cout << "Error, please type a number!" << std::endl;
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cout << "Please type the index of goal you'd like to edit: ";
            std::cin >> n_goal;
        }

        if (n_goal == 0){ // type zero for exit
            break;
        }

        else if (n_goal >= m_diary.size()) { // error catching
            std::cout << "Incorrect entry\n";
            n_goal = 0;
        }

        // Diary update
        else {
            std::string edited_goal {};
            std::cout << "Type update here: ";
            std::getline(std::cin >> std::ws, edited_goal);
            m_diary[n_goal] = edited_goal;
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
            std::cout << "Please type the index of goal you'd like to edit: ";
            std::cin >> n_goal;
        }

        if (n_goal <= m_diary.size()) {
            m_diary.erase(m_diary.begin() + n_goal - 1); // delete entry
            std::cout << "Entry deleted!\n";
            break;
        }
        else {
            std::cout << "Invalid selection!\nPlease type the index of the goal you'd like to delete: ";
        }
    }
}

