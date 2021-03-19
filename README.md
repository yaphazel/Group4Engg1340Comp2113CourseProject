# Group 4 Engg1340 / Comp2113 Course Project

**Group members:** 

YAP Hazel Pik Yen (3035553393);  
LEE Zhen Zhang (3035666061);

**Description:**
The game is a horror-themed text-based choice game, where the player is presented with several choices at each stage of the game and each choice brings the player to the next stage where they are presented again with choices. These choices as well your luck could mean the difference between winning or losing the game. The end goal of the game is to either escape or kill the killer, failing to do so results in the characters death.

**Features:**
1. **Selection of a choice may result in random output** *(related to generation of random game sets or events)*
i.e. Choose to “attack killer” will randomly result in either “successful kill” or “unsuccessful kill” based on dice roll. (srand()%6 + 1)
2. **Use of structure tag to store all possible event/scenarios** *(related to data structures for storing game status & Dynamic memory management)*
i.e bool pick_up_axe ; bool open_door; 
3. **Constant update of structure specification after each choice** *(related to data structures for storing game status & Dynamic memory management)*
I.e Every time the player inputs a choice, structure copy (strcpy) is updated.
4. **Option to save file** (related to file input/output *(e.g., for loading/saving game status)*
I.e Player’s last status will be stored so that they can quit and return to the same session and have their choices remembered.
5. **Each major stage of the game is separated into multiple program files** *(Program codes in multiple files)*
I.e Each final outcome of the game (Die, Escape etc.) will have their own program file.

