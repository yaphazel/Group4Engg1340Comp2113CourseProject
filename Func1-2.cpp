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
// FUNCTION 1 (FIRST CHOICE)
// ---------------------------------------------------------------------
void func1(int choice)
{
    if (choice == 1) // open door
    {
        save_info s;
        s.position = "2";
        s.has_axe = "No";
        s.has_key = has_key;
        si.push_back(s) ; // generates new input into save_info vector

  
        srand(time(0));
        int rnd_result = rand()%6 + 1;

        if (rnd_result == 6)   // Escape without Axe
        {
            cout << "You gently push open the door. You step out into the hallway quietly." << endl;
            cout << "You see a key laying on the coffee table in the middle of the room." << endl;
            cout << "You stealthily creep torwards the table and grab the key." << endl;
            srand (time(0));
            int number = rand() %3 + 1;
            keyHint(number);
            cout<<"Holding onto the key tightly, you start to look around."<<endl;
            escapeFunc();
        }

        else      // Encounter Killer without Axe
        {
            cout << "Gently pushing the door open, you hear the faintest hint of shoes shuffling." << endl;
            cout << "Chills running down your spine, you quickly look around you, eyes stopping dead as you see the silhouette of a man bathed in the harsh lights coming from the TV.\n" << "It's the killer.\n";
            cout << "The glint of something sharp in the killer's hand catches your eye, in that split second you realise your killer is coming at you with a knife.\n"; 
            choice = 2;
            killergame(choice);
            if (you>0){
              srand (time(0));
              int number = rand() %3 + 1;
              cout << "Slowly, you make you way towards the man's body. You circle it like vulture, afraid to approach." <<endl;
              cout << "Gathering a bit of courage, you kick the still body of the man." <<endl;
              cout << "As you contine to kick at it and it remains lifeless, you decide to search his body." <<endl;
              keyHint(number);
              cout << "Gently breathe in through your nose, you calm yourself and start to look for a way to escape.";
              escapeFunc();
            }
            else{
              cout << "With one final stab into your chest, you collapse to ground dead." << endl;
              endingFunc();
            }
        }
        return;



    }

    else if (choice == 2) //LOOK AROUND
    {
        save_info s;
        s.position = "3";
        s.has_axe = "No";
        s.has_key = has_key;
        si.push_back(s) ;
        srand (time(0));
        int number = rand() %3 + 1; // generates random number between 3 and 1
        keyHint(number);
        cout << "Beside the key, you see a dusty old box, there is a combination lock on it!" << endl;

        if (comb_minigame()) // comb_minigame() returns 1 or 0
        {
            int success = 1;
            func1_2(success);
            return;
        }

        else
        {
            int success = 0;
            func1_2(success);
            return;
        }


    }

    else if (choice == 3)
    {
        savefile();
        cout << endl;
        cout << "GAME END"<<endl;
        exit(1);
    }
}

void func2(int choice)
{
    if (choice == 1)
    {
        save_info s;
        s.position = "6";
        
        if (has_axe) s.has_axe = "Yes";
        else s.has_axe = "No";
        
        s.has_key = has_key;
        
        si.push_back(s) ;

        cout << "You open the door and a dark figure appears. A man with dark, sinister eyes calmly walks towards you. " << endl;
        cout << "Fear clutching at your heart, you stumble backwards. He seemed to have you cornered against the wall. Choking down you fear, you brace yourself to fight." << endl;
        choice = 2;
        killergame(choice);
        if (you>0){
          if (has_axe){
    
            cout << "Slowly, you make you way towards the man's body. You circle it like vulture, afraid to approach." <<endl;
            cout << "Gathering a bit of courage, you kick the still body of the man." <<endl;
            cout << "As you continue to kick at it and it remains lifeless, you gently breathe in through your nose to calm yourself. You begin to look for a way to escape.";
            escapeFunc();
          }
          else{
            escapeFunc();
          }  
          }
        else{
          cout << "With one final stab into your heart, you collapse to ground dead." << endl;
          endingFunc();
        }
    }
    else if (choice == 2)
    {
        save_info s;
        s.position = "7";
        if (has_axe) s.has_axe = "Yes";
        else s.has_axe = "No";

        s.has_key = has_key;

        si.push_back(s) ;
        hideFunc();

    }
    else if (choice == 3)
    {
        savefile(); 
        cout << endl;
        cout << "GAME END"<<endl;
        exit(1); // terminates game

    }
}
