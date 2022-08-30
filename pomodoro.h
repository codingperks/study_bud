//
// Created by Ryan Perkins on 30/08/2022.
//

#ifndef STUDY_BUD_POMODORO_H
#define STUDY_BUD_POMODORO_H

class Pomodoro{
private:
    int m_pomMinutes = 25;
    int m_shortBreak = 5;
    int m_longBreak = 20;

public:
    int m_longBreakTarget = 4;
    void pomodoroTimer();
    void shortBreakTimer();
    void longBreakTimer();
    int pomodoroCounter(int timerCounter);
    void pomodoroSettings();
    void pomodoroOutputSettings();
    void pomodoroCounterReset(int timerCounter);
    void longBreakTarget();

    };



#endif //STUDY_BUD_POMODORO_H
