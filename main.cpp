#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <time.h>
#include <string>
#include "header.h"

using namespace std;

vector<save_info> si; // Dynamic memory management

bool has_axe = false;
string has_key = "0";
int you = 3;
int killer = 3;

// Main Menu
int main(){
    cout << "Awaken "<< FIRST <<endl;
    int start;
    cout << " 1 - Start Game."<< endl;
    cout << " 2 - Continue Story."<< endl;
    cout << " 3 - Help."<< endl;
    cout << " 4 - Exit Game."<< endl;
    cout << endl;
    cout << " Enter your choice and press return: ";

    cin >> start;
    while (start != 1 && start != 2 && start != 3 && start != 4) // checks if input is correct
    {
        cout << "Please choose between 1,2,3 and 4" << endl; // loops input if input is incorrect
        cin >> start;
    }

    switch (start)
    {
    case 1:
        startgame();
        break;
    case 2:
        readfile();
    case 3:
        cout << "How to Play Game" <<endl;
        cout << endl;
        cout << "Read the text displayed on the screen and follow the instuctions." << endl;
        cout << "At certain stages of the game you will be presented with several choices with a corresponding number." << endl;
        cout << "i.e. Which do you like more? [1] Rainbows ---- [2] Unicorns " << endl;
        cout << "Type the number into the console to select your choice." << endl;
        cout << "i.e. 1"<<endl;
        cout << "When you quit the game using one of the choices given, a save file will be created with your progress recorded." << endl;
        cout << "When you choose \"Continue\" in the main menu, the game will read your save file." << endl;
        cout << "That is all! Please enjoy!" << endl;
        cout << "[1] Start Game [2] Continue Game [3] Quit Game" << endl;
        cout << " Enter your choice and press return: ";
        cin >> start;
        cout << endl;
        while (start != 1 && start !=2 && start !=3)
        {
            cout << "Please input either 1,2 or 3" << endl;
            cin >> start;
        }
        if (start==1) startgame();
        else if(start==2) readfile();
        else if (start == 3) switch(4);
    case 4:
        cout << "Thanks for playing!" <<endl;
        exit(1);
    return 0;
    }
}




// Start Game --------------------------------------------------------------------

void startgame()
{
    save_info s;
    s.position = "1";
    s.has_axe = "No";
    s.has_key = has_key;
    si.push_back(s) ; // generates new input into save_info vector

    int choice1;
    cout << "GAME START" << endl;
    cout << endl;
    cout << "You wake up from the sound of water droplets hitting the concrete ground." << endl;
    cout << "The room is shrouded in darkness, only slightly illuminated by the light seeping through a door at the top of the stairs." << endl;
    cout << "What do you do? [1] Open the door ---- [2] Look Around ---- [3] Quit Game" << endl;
    cin >> choice1;
    while (choice1 != 1 && choice1 != 2 && choice1 != 3)
    {
        cout << "Please input either 1,2 or 3" << endl;
        cin >> choice1;
    }
    func1(choice1);
}



// End Game ---------------------------------------------------------------------
void endingFunc(){
    if (you == 0){
        cout << "Farewell! May your soul rest in peace.\n";
        cout << endl;
        cout << "GAME END"<<endl;
        exit(1);
    }
    else{
        cout << "Congratulations! You are alive and have escaped.\n";
        cout << endl;
        cout << "GAME END"<<endl;
        exit(1);
    }
}



