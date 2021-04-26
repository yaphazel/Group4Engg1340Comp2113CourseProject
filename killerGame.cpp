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

// Health Bar ---------------------------------------------------------------------

void printHealth(){         // Prints out Health Bar
    cout << "Killer : ";
    for (int i=0;i<killer;i++){
        cout << HEART; // prints a heart symbol for each health point the killer has
    }
    if (killer==0){
      cout <<SALTIRE;
    }  // if killer are dead, prints X
    cout << " You : ";

    for (int i=0;i<you;i++){
        cout << HEART;
    }
    
    if (you==0){
      cout <<SALTIRE<<endl;  // if  you are dead, prints X
      cout << "YOU ARE DEAD."<<endl;  // if  you are dead, prints you are dead.
      }   
    if (killer==0){
      cout<<endl;
      cout << "THE MAN IS DEAD."<<endl;  // if killer are dead, prints he is dead
    }
    cout << endl;
}

// Random Probability Fighting 
void Success(int choice)   // Generation of random game sets or events
{
    srand (time(0));
    int number = rand() %7 + 1;
    if (choice==1){         // Case for attack to shoulder
        if (number <=2){    // higher chance of winning attack since weak point attacked
          you--;
          cout << "The man manages to cut you.\n";
          printHealth();}
        else {      
          killer--;
          cout << "You manage to hurt the man.\n";
          printHealth();}
    }
    else if (choice==2){     // Normal Condition including INJURY TO LEG & NO AXE PUNCH 
        if (number <=3){    // lower chance of winning attack
          you--;
          cout << "The man manages to cut you.\n";
          printHealth();}
        else {
          cout << "You manage to injure the man.\n";
          killer--;
          printHealth();
        }
    }
    else if (choice==3){    // Dodging killer 
        if (number <=3){    // fail to dodge 
          cout << "With fast reflex, the man catches you. He stabs the knife into your abdomen  and you fall to the ground." << endl;
          cout << "As vision begin to fade, your last thoughts linger on the life you wished you had lived and all the things you wished you done differently." << endl;
          you-=3;
          printHealth();
          endingFunc();
          }
        else {
          cout << "You stumble out of the door and into a living room." << endl;
          cout << "Your heart racing, your mind consumed by the need to escape. You look around in desperation." << endl;
          cout << "You see a key hanging on a clothing rack across the room. You run and grab it."<<endl;
          srand (time(0));
          int number = rand() %3 + 1;
          keyHint(number);
          cout <<"You begin to look for an exit."<<endl;
          escapeFunc();}
    }
    else if (choice==4){  // *NO AXE PUNCH *  
        if (number <=4){    
          you--;
          cout << "The man manages to cut you.\n";
          printHealth();}
        else {
          cout << "You punch the man in the face\n";
          killer--;
          printHealth();}
    }
    else if (choice==5){    // *NO AXE KICK *  
        if (number <=3){   
          cout << "The man stabs you." << endl;
          you--;
          printHealth();
        }
        else {
          cout << "You kick the man in the chest." << endl;
          killer--;
          printHealth();
          }
    }
    return;

}
// Killer Game ---------------------------------------------------------------------

void killergame(int choice){
    int choice2;
    if (has_axe)
    {
        while (killer > 0 && you > 0)
        {
            cout << "What do you do? [1] Stab ---- [2] Slash" <<endl;
            cin >> choice2;
            while (choice2 != 1 && choice2 != 2) // looping for incorrect input
            {
                cout << "Please input either 1 or 2" << endl;
                cin >> choice2;
            }
            Success(choice);
        }

    }
    else
    {
        while (killer > 0 && you > 0)
        {
            cout << "What do you do? [1] Punch ---- [2] Kick" << endl;
            cin >> choice2;
            while (choice2 != 1 && choice2 != 2)
            {
                cout << "Please input either 1 or 2" << endl;
                cin >> choice2;
            }
            if (choice2 == 1) Success(4);
            else if (choice2 == 2) Success(5); // Kick is more effective
            
        }
    }
    return;
}
