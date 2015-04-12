#include "stdafx.h"

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>
#include <cstring>



//Gotta move these later or fix up menu
//Shop demo_shop;
string x = "Player 1";
string y = "Rica";
string line = "--------------------------------------------------------------------------------";
player* play = new player(x, "Game Master", 300, 1, 0, 0);
player* invtest = new player(x, "Game Master", 10, 1, 0, 0);
map* map1 = new map(10);
Town town1 = Town();
Entity* enemy = new Entity(y, 10, 1, 0, 5, 20);
Entity* enemy2 = new Entity("Fox", 10, 1, 0, 2, 10);
Combat_System battle_demo = Combat_System(play);
Scene scene;


using namespace std;

int debug();

string getFileContents (std::ifstream& File)
{
    string Lines = "";        //All lines

    if (File)                      //Check if everything is good
    {
	while (File.good ())
	{
	    string TempLine;                  //Temp line
	    getline (File , TempLine);        //Get temp line
	    TempLine += "\n";                      //Add newline character

	    Lines += TempLine;                     //Add newline
	}
	return Lines;
    }
    else                           //Return error
    {
	return "ERROR File does not exist.";
    }
}

int main()
{

    srand(time(0));
    string inputName = "title2.txt";
    cout << endl;
    ifstream file;
    file.open(inputName.c_str());
    if (!file.is_open())
    {
        cout << "Error opening " << inputName << endl;
        return 1;
    }
    string Art = getFileContents(file);
    cout << Art << endl;

	while(1)
	{
		cout << "                                1. New Game \n";
		cout << "                                2. Load Game \n";
		cout << "                                3. Options \n";
		cout << "                                4. Credits \n";

		int input = 0;
		cin >> input;
		if (input == 1)
		{
			std::cout << "\n\n\n";
			Consumable* potion = new Consumable("Potion", "Potion", 20, 10);
			play->add_con(potion);
			play->set_min_dmg(20);
			play->set_max_dmg(90);
			play->setmoney(500);
			scene.scene_001(play);
			battle_demo.runBattle(enemy2);
			scene.scene_003(play);
			town1.run(play);
			return 0;
			//menu();
		}
		else if (input == 2)
		{
			//map1->run(play,);
			Store s;
			string file = "all_items.txt";
			s.fillStore(file);
			//s.run(play);
			return 0;
		}
		else if (input == 3)
		{
			return 0;
		}
		else if (input == 4)
		{
			std::cout << "Cheshire's Game" << std::endl;
			std::cout << "David Zhang - President" << std::endl;
			std::cout << "Michaella Sheng - Vice President" << std::endl;
			std::cout << "Everyone else: Minions" << std::endl;
			std::cout << "1 Rica was harmed in the making of this game." << std::endl;
			std::cout << "\n\n\n\n\n" << std::endl;
		}
	}
    return 0;
}

int debug()
{
    //DEBUG STUFF HERE
	return 1;
}