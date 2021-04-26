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
//INTER FUNCTION --------------------------------------------------------------------------------------------------
void func1_2(int success)
{
    if (success == 1)
    {
        save_info s;
        has_axe = true;
        s.position = "4";
        s.has_axe = "Yes";
        s.has_key = has_key;
        si.push_back(s) ;

        cout << "In the box, you see an axe on top of a shirt. The shirt is stained with blood, a large red patch on the left sleeve." << endl;
        cout << "As you pick up the axe, you hear strong and loud footsteps outside the door." << endl;
        cout << endl;
        cout << "What do you do next?" << endl;
        cout << " [1] Open the door ---- [2] Hide under the stairs ---- [3] Quit Game" << endl;

        int tmp_choice;
        cin >> tmp_choice;
        while (tmp_choice != 1 && tmp_choice != 2 && tmp_choice != 3)
        {
            cout << "Please input either 1 , 2 or 3" << endl;
            cin >> tmp_choice;
        }

        func2(tmp_choice);

        return;
    }
    else // leads to seperate set of events when failed to win minigame
    {
        save_info s;
        has_axe = false;
        s.position = "5";
        s.has_axe = "No";
        s.has_key = has_key;
        si.push_back(s) ;
        cout << "You hear strong and loud footsteps outside the door." << endl;
        cout << endl;
        cout << "What do you do next?" << endl;
        cout << " [1] Open the door ---- [2] Hide behind the door ---- [3] Quit Game" << endl;

        int tmp_choice;
        cin >> tmp_choice;
        while (tmp_choice != 1 && tmp_choice != 2 && tmp_choice != 3) // loops when input is invalid
        {
            cout << "Please input either 1 , 2 or 3" << endl;
            cin >> tmp_choice;
        }
        func2(tmp_choice);


        return;
    }
}
