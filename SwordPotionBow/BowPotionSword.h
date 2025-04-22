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
	bool is_pomegrate;
public:
	Potion(std::string name);
	void use() override;
	void attack() override;
};


class Player
{
	std::string name;
	int health;
public:
	Player();
	int getHealth() const;
	Player& setHealth(int _damage);
	Player& take(std::shared_ptr<ITake>takable_item);
	Player& damage(std::shared_ptr<IAttack>attack_item);
};