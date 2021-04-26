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
// COMBINATION MINIGAME ----------------------------------------------------------------------------------------
bool comb_minigame()
{
    cout << "It seems that the combination passcode is a four digit number from 0 to 9999. " << endl;
    cout << "Try to guess the passcode, you have 15 attempts." << endl;
    cout << "The range will narrow as you guess." << endl;
    srand (time(NULL));
    int rndvalue = rand()%9999, inp; // generates a value between 0 and 9999
    int count = 0 , upperbnd = 9999 , lowerbnd = 0;

    while (count < 15)
    {
        cout << "You have " << 15 - count << " tries left!." << endl;
        cout << "Type a number between " << lowerbnd << " and " << upperbnd << "." << endl;
        cin >> inp;

        if (inp == rndvalue)
        {
            count++;
            cout << "Great! You managed to unlock the combination lock after " << count << " tries!." << endl;
            cout << "AXE ACQUIRED"<<endl;
            return 1;
        }
        else
        {
            if (inp < lowerbnd || inp > upperbnd)
            {
                cout << "Thats out of the range! Try again!" << endl;
            }
            else if (inp > lowerbnd && inp < rndvalue) 
            {
                lowerbnd = inp; // reduces the range after each guess
                count++;
            }
            else
            {
                upperbnd = inp;
                count++;
            }
        }

     }

     cout << "You failed to unlock it!" << endl;
     return 0;


}
