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

// FUNCTION 4 (ESCAPE)
// Key Hint --------------
void keyHint(int no){
  vector<save_info>::iterator itr = si.end() - 1; // iterator set at most recent vector input
  if (no == 1){
      (*itr).has_key= "1"; // edits the most recent vector input
      has_key = "1";
      cout << endl;
      cout<<"KEY ACQUIRED\n"<<"You found a yellow key with a shoe keychain attached to it."<<endl;
      cout << endl;
      }
  else if (no == 2){
      (*itr).has_key= "2";
      has_key = "2";
      cout << endl;
      cout<<"KEY ACQUIRED\n"<<"You found a black key with a tire keychain attached to it."<<endl;
      cout << endl;
      }
  else if (no == 3){
      (*itr).has_key= "3";
      has_key = "3";
      cout << endl;
      cout<<"KEY ACQUIRED\n"<<"You found a blue key with a fork keychain attached to it."<<endl;
      cout << endl;
      }
  return;
}
void escOutcomeFunc(int choice, string answer){
    if (choice== stoi(answer)){
        cout << "You run through the room heading straight for the first door you see.\n";
        cout << "You try opening the door but it's locked shut. Luckily, you remember you have a key.\n";
        cout << "You try to unlock the door with key. To your delight, it opens. You run out to your safety.\n";
        endingFunc();
    }
    else{
        int choice_again;
        while (choice_again != stoi(answer)){ // loop for wrong answer
            cout << "You run through the room heading straight for the first door you see.\n";
            cout << "You try opening the door but it's locked shut. Luckily, you remember you have a key.\n" ;   
            cout << "Slotting the key in, you twist and turn but your efforts were to no avail, it doesn't unlock."<<endl;
            if (killer > 0){
                cout << "In panic, you try to turn around to find another door."<<endl;
                cout << "At the doorway you had just walked through stood a man with knife in his hand." <<endl;
                you-=3;
                cout << "The man lunges fowards and the last thing you see is the reflection of your eyes on the blade of the knife."<<endl;
                endingFunc();
            }
            else{
               cout << "What do you do? [1] Go back to the Living Room" <<endl;
               cin >> choice;
               while (choice != 1)
                {
                cout << "Please input either 1 or 2" << endl;
                cin >> choice;
                }               
               if (choice==1){
                   cout << "Back again in the living room, you are faced with three doorways.\n";
                   cout << "Through the black doorway, you see the entrance.\n";
                   cout << "Through the yellow doorway in front of you, you see the garage.\n";
                   cout << "Through the blue doorway on your right, you catch a glimpse of a yellow spoon.\n";
                   cout << "What do you do? [1] Go through the entrance ---- [2] Go to the garage ---- [3] Go to the kitchen\n" <<endl;
                   cin >> choice_again;
               }
                else if (choice==2){
                   cout << "Thank you for playing";
                   cout << endl;
                   cout << "GAME END"<<endl;
                   exit(1);}
            }
        }
        escOutcomeFunc(choice_again,answer);
    }
}

void escapeFunc(){
    int choice;
    cout << "Through the black doorway on your left, you catch a glimpse of a blue sock.\n";
    cout << "Through the yellow doorway in front of you, you catch a glimpse of the hood of a black car.\n";
    cout << "Through the blue doorway on your right, you catch a glimpse of a yellow spoon.\n";
    cout << "What do you do? [1] Go left ---- [2] Go straight ---- [3] Go right" <<endl;
    cin >> choice;
    while (choice != 1 && choice !=2 && choice !=3)
            {
            cout << "Please input either 1 , 2 or 3" << endl;
            cin >> choice;
            }
    escOutcomeFunc(choice,has_key);
}   
