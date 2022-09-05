//
// Created by Ryan Perkins on 24/08/2022.
//

#ifndef STUDY_BUD_DIARY_H
#define STUDY_BUD_DIARY_H

class Diary{
private:
    std::vector<std::string> m_diary; // to hold goals
    std::vector<std::string> m_diary_status ; // to record completion status

public:
    void displayDiary();
    static std::string enterGoal();
    void addGoal(const std::string& goal);
    static int enterGoalStatus();
    void addGoalStatus(const int& goal_status);
    void zipDiary();
    void editGoal();
    void deleteGoal();
    void saveDiary(); // output csv with date, overwrite option
    void loadDiary();
};

#endif //STUDY_BUD_DIARY_H
