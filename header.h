#ifndef HEADER_FILE
#define HEADER_FILE

#define HEART   "\xE2\x99\xA5"
#define SALTIRE "\xe2\x98\x93"
#define FIRST "\xe2\x98\xbd"

#include<string>
#include<vector>
struct save_info        // Data structures for storing game status
{
    std::string position;
    std::string has_axe;
    std::string has_key;
};
extern std::vector<save_info> si;
extern int you;
extern int killer; 
extern bool has_axe;
extern std::string has_key;

//main.cpp
void startgame();
void endingFunc();
//fileManage.cpp
void savefile();
void readfile();
//combGame.cpp
bool comb_minigame();
//killergame.cpp
void killergame(int choice);
void Success(int choice);
void printHealth();
//Func1-2.cpp
void func1(int choice);
void func2(int choice);
//FuncInter.cpp
void func1_2(int success);
//Func3.cpp
void hideFunc();
//Func4.cpp
void keyHint(int number);
void escOutcomeFunc();
void escapeFunc();

#endif
