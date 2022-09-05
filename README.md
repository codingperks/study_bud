
# Study Bud

This project contains a suite of tools to aid with studying. These tools include a diary, a bundle of [pomodoro timers](https://en.wikipedia.org/wiki/Pomodoro_Technique) and a separate timer reminding the user to drink water (the latter of which I especially forget to do in the middle of a deep study session).

This repo includes the following modules:


**diary.cpp**- which contain the functions related to diary operation

**pomodoro.cpp** - which contain the functions related to timer operation

**water.cpp** (unimplemented) - which contains functions related to
                                the water reminder timer

These tools have been programmed in C++ and compiled using cmake. Each of these .cpp source files contain corresponding header files. Requirements are specified within a **requirements.h** header file.

## Installation instructions

To install and run:

- Download this study_bud repo
- Compile using your c++ compiler
- Run main.cpp

### Requirements

The required headers and namespaces have been detailed in requirements.h, for posterity, these are:
```
#include <iostream> // for std::
#include <utility>
#include <ctime> // for timer functionality
#include <cstdio> // for I/O operations
#include <chrono> // for timer functionalities
#include <string> // for additional string functionality
#include <fstream> // for csv writing
#include <ctime> // to call today's date for naming purposes
#include <vector> // to generate diary member objects
```
The requirements.h header is called within the main.cpp file - no need for additional user input for installation of requirements.

## Usage instructions
main.cpp opens the following menu:

```
Welcome to the Study Bud!
Please select an option:
[1] Diary
[2] Timer
[0] Exit
```

Menu options can be selected by typing a number and pressing the enter key. This is how each subsequent menu option is also selected by the user. On most menus, an input of '0' will exit the user back to the menu a level higher. Exiting at the menu above terminates the program. 

## Further usage instructions
### Diary
A menu option selection of 1 will launch the following diary menu:
```
Diary
Please select an option:
[1] View diary
[2] Enter goal
[3] Edit goal
[4] Delete goal
[5] Save diary
[6] Load diary - to implement
[0] Exit
```
```[1] View diary```
This option outputs the current diary, both the goals and each goal's status, example below:

```
Current diary
Diary entry 1 is: Write this readme - Status: In-progress
Diary entry 2 is: Program the diary.cpp modules - Status: Completed
Diary entry 3 is: Learn how to move objects with my mind - Status: Planned
```

``` [2] Enter goal ```
This option allows the user to input a goal and the goal's status. Currently, the user can choose from three statuses: 'Planned', In-progress', 'Completed'
```
Enter a goal: Write this readme

Added 'Write this readme' to diary!

What is the status of this goal?
[1] Planned
[2] In-progress
[3] Completed
Please type the index of goal status here (type 0 to exit): 2
```

``` [3] Edit goal ```
This option allows the user to edit a previously defined goal. The user is prompted to select the target goal index, input the update and the update's progress.

```
Current diary
Diary entry 1 is: Write this readme - Status: In-progress
Diary entry 2 is: Program the diary.cpp modules - Status: Completed
Diary entry 3 is: Learn how to move objects with my mind - Status: Planned

Please type the index of goal you'd like to edit (type 0 to exit): 1
Type update here: Edit this readme to showcase the edit goal function
What is the status of this goal?
[1] Planned
[2] In-progress
[3] Completed
Please type the index of goal status here (type 0 to exit): 3
```

``` [4] Delete goal ```
This option allows the user to delete a previously defined goal. The user is prompted to select the target goal index, which deletes the goal and corresponding status.

```
Current diary
Diary entry 1 is: Edit this readme to showcase the edit goal function - Status: Completed
Diary entry 2 is: Program the diary.cpp modules - Status: Completed
Diary entry 3 is: Learn how to move objects with my mind - Status: Planned

Please type the index of goal you'd like to delete: 3
Entry deleted!
```
Once an entry is deleted, this goal will no longer appear in the diary.

``` [5] Save diary ```
This option exports the current diary to a csv file into the 'diary_output' folder. These files are named using the user's current time and date. The format of the csv file is as follows:

| Index | Goal                                   | Status      |
|-------|----------------------------------------|-------------|
| 1     | Write this readme                      | In-progress |
| 2     | Program the diary.cpp modules          | Complete    |
| 3     | Learn how to move objects with my mind | Planned     |

``` [6] Load diary``` **currently unimplemented**
This functionality is currently unimplemented, but this function will allow users to load a new diary object from one of these csv files.

### Timer

A menu option of 2 will open the timer menu. This timer is based on the [pomodoro technique for studying](https://en.wikipedia.org/wiki/Pomodoro_Technique). This technique involves working for an interval of time or 'pomodoros' (usually 25 minutes) followed by a short break (usually 5 minutes). After the fourth pomodoro is completed, a long break of 20 - 30 minutes is then taken.

```
Timer
Please select an option:
[1] Start pomodoro timer
[2] Check timer settings
[3] Adjust timer lengths
[4] Reset pomodoro counter
[5] Adjust long break target intervals
[0] Exit
```

```[1] Start pomodoro timer```
This option begins the default timer of 25 minutes. This starts a visual countdown which ticks down in minutes and seconds:

``` Pomodoro time remaining: 24:56 ```

Once the timer has completed, the user is prompted whether they would like to start the short break timer
```
Pomodoro timer complete (don't forget to drink water)!
You have completed 1 pomodoro(s)!
It's time for a short break.
Would you like to start the short break timer or exit?
[1] Start timer
[2] Exit
```
After four pomodoros, the user is prompted if they would like to start the long break timer. After each break, the user can then select the ```Start pomodoro timer ``` option again to begin the next pomodoro.

```[2] Check timer settings``` This option prints the current timer settings

```The current pomodoro timer setting is 25 minutes.
The current short break timer setting is 5 minutes.
The current long break timer setting is 20 minutes.
The target number of pomodoros before a long break is 4
```

```[3] Adjust timer lengths```
This setting allows the user to adjust the lengths of the pomodoro timer, the short break timer and the long break timer.

```[4] Reset pomodoro counter```
A long break occurs after 4 pomodoros, with the program retaining the number of pomodoros completed during a session. If the user would like to reset this counter to zero, they can do so using this option.

```[5] Adjust long break target intervals```
A long break occurs after 4 pomodoros, if the user would like a long break more (or less) frequently, they can adjust this target here.

### Water
This module allows the user to input an interval of time in which to be reminded to take a drink of water. However, this is currently not integrated into the main suite due to the need for a concurrency implementation. This module works standalone, but is yet to be implemented together with the pomodoro timer.

# Author details
Name: Ryan Perkins

gitHub: codingperks

### Author footnotes
I created these tools to aid with my upcoming M.Sc. in Computing, as well to practice C++. I use the pomodoro technique quite frequently in my study so this seemed to be an appropriate project to start with.




