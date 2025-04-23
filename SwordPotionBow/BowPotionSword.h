#pragma once

#include <iostream>
#include "Interface.h"

class Bow : public ITake, public IDealDamage
{
	std::string name;
public:
	Bow(std::string name);
	void use() override;
	void dealDamage() override;
};


class Sword : public ITake, public IDealDamage
{
	std::string name;

public:
	Sword(std::string name);
	void use() override;
	void dealDamage() override;
};


class Potion : public ITake, public IDealDamage
{
	std::string name;
	bool is_pomegrate;
public:
	Potion(std::string name);
	void use() override;
	void dealDamage() override;
};


class Player : public ITake, public IDealDamage
{
	std::string name;
	int health_player;
public:
	Player();
	void use() override;
	void dealDamage() override;
	Player& take(std::shared_ptr<ITake> takable_item);
	Player& damage(std::shared_ptr<IDealDamage> attack_item);

	int getHealth() const;
};