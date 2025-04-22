#pragma once

#include <iostream>
#include <ctime>
#include "Interface.h"

class Bow : public ITake, public IAttack
{
	std::string name;
	int health;
public:
	Bow(std::string name);
	void use() override;
	void attack() override;
	int getHealth();
};


class Sword : public ITake, public IAttack
{
	std::string name;
	int health;
public:
	Sword(std::string name);
	int getHealth();
	void use() override;
	void attack() override;
};


class Potion : public ITake, public IAttack
{
	std::string name;
	int health;
public:
	Potion(std::string name);
	void use() override;
	void attack() override;
	int getHealth();
};


class Player
{
	std::string name;
	int health;
public:
	Player();
	int getHealth();
	Player& take(std::shared_ptr<ITake>takable_item);
	Player& damage(std::shared_ptr<IAttack>attack_item);
};