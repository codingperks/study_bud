//
// Created by Ryan Perkins on 30/08/2022.
//

#ifndef STUDY_BUD_POMODORO_H
#define STUDY_BUD_POMODORO_H

class Pomodoro{
private:
    int m_pomMinutes = 25; // default pomodoro timer of 25 minutes
    int m_shortBreak = 5; // default short break timer of 5 minutes
    int m_longBreak = 20; // default long break timer of 20 minutes

public:
    int m_longBreakTarget = 4; // default long break interval of 4 pomodoros
    void pomodoroTimer() const;
    void shortBreakTimer() const;
    void longBreakTimer() const;
    static int pomodoroCounter(int timerCounter);
    void pomodoroSettings();
    void pomodoroOutputSettings() const;
    static void pomodoroCounterReset(int timerCounter);
    void longBreakTarget();
    };

#endif //STUDY_BUD_POMODORO_H
