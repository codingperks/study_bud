//
// Created by Ryan Perkins on 24/08/2022.
//

#ifndef STUDY_BUD_DIARY_H
#define STUDY_BUD_DIARY_H

#include <vector>

class Diary{
private:
    std::vector<std::string> m_diary;

public:
    void displayDiary();
    static std::string enterGoal();
    void addGoal(const std::string& goal);
    void editGoal();
    void deleteGoal();
};

#endif //STUDY_BUD_DIARY_H
