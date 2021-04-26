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
void readfile()     //File input
{
    ifstream save_file;

    save_file.open("mysavefile.txt");
    if (save_file.fail())
    {
        cout << "Failed to access save file" << endl;
        cout << "Starting game" << endl;
        startgame();
    }

    string ln1,ln2,ln3;

    getline(save_file,ln1); // reads the three lines from the savefile
    getline(save_file,ln2);
    getline(save_file,ln3);

    save_info s;
    s.position = ln1;
    s.has_axe = ln2;
    s.has_key = ln3;

    has_key = ln3;

    if (ln2 == "Yes")
    {
        has_axe = true;
    }

    

    si.push_back(s);

    switch (stoi(ln1)) // immediately initiates game based on position in savefile
    {
        case 1:
            startgame();
            break;

        case 2:
            func1(1);
            break;

        case 3:
            func1(2);
            break;

        case 4:
            func1_2(1);
            break;

        case 5:
            func1_2(0);
            break;

        case 6:
            func2(1);
            break;

        case 7:
            func2(2);
            break;

        case 8:
            hideFunc();
            break;
    }
}
void savefile()     // File Output
{
    ofstream save_file;

    save_file.open("mysavefile.txt");
    if (save_file.fail()) exit(1);

    vector<save_info>::iterator itr = si.end() - 1; // sets iterator at the last input in the vector
    save_file << (*itr).position << endl; // adds data into savefile
    save_file << (*itr).has_axe << endl;
    save_file << (*itr).has_key << endl;

    save_file.close();
    cout << "File Saved!" << endl;

    return;
}
