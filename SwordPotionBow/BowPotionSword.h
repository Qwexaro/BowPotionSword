#pragma once

#include <iostream>
#include "Interface.h"

class Bow : public ITake, public IAttack
{
	std::string name;
public:
	Bow(std::string name);
	void use() override;
	void attack() override;
};


class Sword : public ITake, public IAttack
{
	std::string name;
public:
	Sword(std::string name);
	void use() override;
	void attack() override;
};


class Potion : public ITake, public IAttack
{
	std::string name;
public:
	Potion(std::string name);
	void use() override;
	void attack() override;
};


class Player
{
	std::string name;
public:
	Player& take(std::shared_ptr<ITake>takable_item);
	Player& damage(std::shared_ptr<IAttack>attack_item);
};