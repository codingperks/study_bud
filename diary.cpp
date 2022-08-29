//
// Created by Ryan Perkins on 23/08/2022.
// Last updated 29/08/2022.
//

#include <iostream>
#include <utility>
#include <vector>
#include "diary.h"

void Diary::displayDiary(){
    // print the diary goals
    int i {};
    std::cout << "\nCurrent diary\n"; // for tidiness of visuals
    for (i = 1; i < m_diary.size() + 1; i++){
        std::cout << "Diary entry " << i << " is: " << m_diary[i-1] << '\n';
    }
    std::cout << '\n'; // for tidiness of visuals
}

std::string Diary::enterGoal(){
    std::cout << "Enter a goal: ";
    std::string goal {};
    std::getline(std::cin, goal);

    return goal;
}

void Diary::addGoal (const std::string& goal){
    m_diary.push_back(goal);
    std::cout << "Added '" << goal << "' to diary!\n\n";
}

void Diary::editGoal (){
    // Diary entry selection
    Diary::displayDiary();
    std::cout << "Please type the index of goal you'd like to edit: ";
    int n_goal {};
    std::cin >> n_goal;
    n_goal = n_goal - 1; // subtract for index searching

    if (n_goal >= m_diary.size()){ // error catching
        std::cout << "Incorrect entry\n";
    }

    // Diary update
    else{
        std::string edited_goal {};
        std::cout << "Type update here: ";
        std::cin >> edited_goal;
        m_diary[n_goal] = edited_goal;
        }
    }

void Diary::deleteGoal(){
    Diary::displayDiary();
    std::cout << "Please type the index of goal you'd like to delete: ";
    int n_goal {};
    std::cin >> n_goal;

    m_diary.erase(m_diary.begin() + n_goal - 1); // delete entry

}
/*
void diary(){ // FOR TESTING

    // initialise diary
    Diary diary{};

    // add goal
    diary.addGoal(std::string {Diary::enterGoal()});

    // display diary - print goals
    diary.displayDiary();

    diary.editGoal();

    diary.displayDiary();

}
*/
