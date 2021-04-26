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
//FUNCTION 3  (HIDE)------------------------------------------------------------------------------------------------
void hideFunc()
{
    save_info s;
    s.position = "8";
    
    if (has_axe) s.has_axe = "Yes";
    else s.has_axe = "No";
    
    s.has_key = has_key;
    
    si.push_back(s) ;

    int choice, choice_attack;
    cout << "You hear the killer opening the door, his heavy footsteps walking down the stairs. You need a place to quickly hide and see a cupboard." <<endl;
    cout << "Without any hesitation, you jump in and hide." <<endl;
    cout << "HEALTH BAR UNLOCKED "<<endl;

    printHealth(); // displays health bar on screen

    cout << "Through the narrow slit of the old cupboard door, you see the killer walk around searching for you, knife in hand. As he turns his back to you, you try to think what to do next." <<endl;
    cout << "What do you do? [1] Attack ---- [2] Try to run past him ---- [3] Quit Game "<<endl;

    cin >> choice;
    while (choice != 1 && choice !=2 && choice !=3) // loops if input is invalid
            {
            cout << "Please input either 1 or 2 or 3" << endl;
            cin >> choice;
            }
    if (choice == 1)
    {

        cout << "You decide to try to attack, but he hears you and quickly turns around, dodging your attack. Without time to spare, you lash out again." <<endl;
        cout << "What do you do? [1] Punch him in the shoulder. ---- [2] Kick him in leg " <<endl;
        cin >> choice;
        while (choice != 1 && choice !=2)
            {
            cout << "Please input either 1 or 2" << endl;
            cin >> choice;
            }
        if (choice==1){
          cout << "You hit his injured shoulder." <<endl;
          cout << "KILLER WEAKENED"<<endl;
          killer--;
          printHealth();
          killergame(choice);
          if (you>0){
    
            cout << "Slowly, you make you way towards the man's body. You circle it like vulture, afraid to approach." <<endl;
            cout << "Gathering a bit of courage, you kick the still body of the man." <<endl;
            cout << "As you continue to kick at it and it remains lifeless, you gently breathe in through your nose to calm yourself. You begin to look for a way to escape.";
            escapeFunc();
            }
          else{
            cout << "With one final stab into your neck, you collapse to ground dead." << endl;
            endingFunc();
          }
        }
        else if (choice==2){
          cout << "You hit his leg. Killer stumbles a little but regains his balance.\n";
          printHealth();
          killergame(choice);
          if (you>0){
            cout << "Slowly, you make you way towards the man's body. You circle it like vulture, afraid to approach." <<endl;
            cout << "Gathering a bit of courage, you kick the still body of the man." <<endl;
            cout << "As you continue to kick at it and it remains lifeless, you gently breathe in through your nose to calm yourself. You begin to look for a way to escape.";
            escapeFunc();
            }
        else{
          cout << "With one final stab into your eye, you collapse to ground lifeless." << endl;
          endingFunc();
        }
          }
    }
    else if (choice ==2){
        cout << "Filled with adrenaline, you decided to run for the stairs.";
        choice=3;
        Success(choice);
    }
    else if (choice == 3)
    {
        savefile();
        cout << "GAME END"<<endl;
        exit(1);
    }
}
