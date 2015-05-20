#ifndef _SKILLS_H_
#define _SKILLS_H_

#include <iostream>

class Player;
class Entity;


class Skill
{
private:
	std::string name; 
	std::string type; //Type of skill
	int min_dmg; //Damage/Amount of heal done
	int max_dmg;
	double ex_dmg; //Extra damage output!
	double acc; //Accuracy


public:
	Skill(string nam, string typ, double ex, double ac);
	Skill(string nam, string typ, int min, int max, double ac);
	Skill(std::string file_name);

	int randNumber();
	int calc_dmg(player* p);

	string getName();

	bool isHit();
	void use_skill(player* p, Entity* e);
	void use_skill(player* p);
};



#endif