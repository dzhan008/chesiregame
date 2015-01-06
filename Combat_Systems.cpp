//Single battles done, need to finish multiple battle. Not sure about small things, need to meet up before that's finished.

#include <iostream>
#include <stdlib.h>

using namespace std;
#include "Combat_System.h"

//Default constructor, probably will never have to use
Combat_System::Combat_System(){
    turn = 0;
    vector<entity> enemies;
    entity enemy;
    player play;
}

//Main constructor, saves the player object
Combat_System::Combat_System(Player p){
    turn = 0;
    vector<entity> enemies;
    entity enemy;
    player = p;
}

int randNumber(){
    return rand % 100 + 1;
}

//True if defending
bool calculateEnemyChoice(entity enemy){
    if(enemy.getHP() > 10){
        if(randNumber() > 80){
            return false;
        }
        else{
            return true;
        }
    }
    else{
        if(randNumber() > 60){
            return false;
        }
        else{
            return true;
        }
    }
}

//Private helper function, asks player what they want to do
//Returns 0, 1, 2 or 3 depending on if they attack, defend, use an item, or run
int Combat_System::promptChoices(){
    int i = -1;
    int prompt;
    while(i = -1){
        cout << "Enter the number of the move you want to make: "<< endl;
        cout << "1: Attack";
        cout << "2: Defend";
        cout << "3: Use an item";
        cout << "4: Run";
        cin >> prompt;
        if(prompt == 1){
            return 0;
        }
        if(prompt == 2){
            return 1;
        }
        if(prompt == 3){
            return 2;
        }
        if(prompt == 4){
            return 3;
        }
        cout << "You have not selected one of the four options." << endl;
    }
}

int promptEnemyChoice(){
    int choice;
    cout << "Which enemy number would you like to attack?: " << endl;
    for(int i = 0; i < enemies.size(); i++){
        cout << "Enemy " << i+1 << ": " << enemies.at(i).getName();
    }
    cin >> choice;
    if(choice >= 1 || choice <= enemies.size()){
        return choice - 1;
    }
    else{
        cout << "Invalid choice, please try again.";
        promptEnemyChoice();
    }
}

double Combat_System::calculateAccuracy(){
    return 0;
}

int Combat_System::calculateDamage(bool defend){
    if(defend){
        return randNumber() / 40;
    }
    else{
        return randNumber() / 10;
    }
}

int calculateTurn(){
    return 0;
}

void runBatte(entity enemy){
    int optionChoice;
    bool eChoice;
    turn = calculateTurn();
    while(player.getHP() > 0 && enemy.getHealth() > 0){
        eChoice = calculateEnemyChoice(enemy);
        optionChoice = promptChoices();
        if(turn == 0){
            if(optionChoice == 0){
                enemy.loseHP(calculateDamage(eChoice));
            }
            if(optionChoice == 2){
                //Access inventory
            }
            if(optionChoice == 3){
                //Prompt run away
            }
            turn = 1;
        }
        else{
            if(!eChoice){
                if(optionChoice == 0){
                    player.loseHP(calculateDamage(false));
                }
                else{
                    player.loseHP(calculateDamage(true));
                }
            }
            turn = 0;
        }
    }
    if(player.getHP() > 0){
        player.setexp(player.getexp() + enemy.getexp());
    }
    else{
        cout << "Game Over.";
    }
}

/*void runBattle(vector<Monster> enemy){
    int optionChoice;
    int eChoice;
    int attack;
    int battleSize = enemy.size();
    turn = calculateTurn();
    while(player.getHP() > 0 && enemy.size() > 0){
        if(turn = 0){
            optionChoice = promptChoices();
            if(battleSize > 1){
                promptEnemyChoice();
                //Implement Multi Battle
            }
            else{
                if(optionChoice == 0){
                    
                }
            }
        }
        else{
            if(battleSize > 1){
                for(int i = 0; i < battleSize; i++){
                    
                }
            }
            else{
                
            }
        }
}*/