# Group 4 Engg1340 / Comp2113 Course Project

**Group members:** 

YAP Hazel Pik Yen (3035553393);  
LEE Zhen Zhang (3035666061);

**Description:**
The game is a horror-themed text-based choice game, where the player is presented with several choices at each stage of the game and each choice brings the player to the next stage where they are presented again with choices. These choices as well your luck could mean the difference between winning or losing the game. The end goal of the game is to either escape before or after killing the killer, failing to do so results in the character's death.

During the game, the player will given a scenario alongside a set of choices. For example, if the scenario is "You decide to try to attack.", players may be given the choice of "What do you do? [1] Punch him in the shoulder. ---- [2] Kick him in leg ". The player will then select 1 or 2 as input. 

**Features:**
1. **Selection of a choice may result in random output** *(related to generation of random game sets or events)*
Feature examples:
  i. Choose to “attack killer” will randomly result in either “successful attack by player” or “successful attack by killer/attacker” based on dice roll. 
  ii. There is a combination game that generates a random number between 0-9999 for the player to guess to obtain a useful item.
  iii. An example of randomness during the game story is that the player can choose to rush out of the basement door where there is a 1 in 6 chance where the killer is not present behind the door, giving the player a higher chance to escape.
  
2. **Use of structure tag to store all possible event/scenarios** *(related to data structures for storing game status)
Feature examples:
  i. Use of struct to store the current position and items a player has obtained throughout the game.
  ii. Variable stored in struct is string position, string has_axe and string has_key.

3. **Constant update of structure specification after each choice** *(Dynamic memory management)*
  i. Every time the player reaches a new major checkpoint, a new struct input is appended onto a vector.
  
4. **Option to save file** (related to file input/output *(e.g., for loading/saving game status)*
  i. Whenever the player chooses to quit the game, the data of the latest vector input will be appended into a save text file.
  ii. When the player chooses to continue a saved game, the data of vector input in the save text file will be recalled to track the progress of the game and the appropriate function will be called.
  
5. **Each major stage of the game is separated into multiple program files** *(Program codes in multiple files)*
  i. The header file and the function files are seperated into different files. A makefile is used to compile them together before the start of the game.
  
Execution and Compilation Instructions
  i. Copy all of the code files into a folder.
  ii. Run terminal in the folder.
  iii. Run compilation of the files using command "make game".
  iv. Run the game using the command "./game".
  v. Player can start playing the game.
  vi. If game instructions is required, insert command "3" at main menu of the game. (3 - Help)
  vii. Once the player finishes the game, using command "make clean" to clean all object and text files. 

