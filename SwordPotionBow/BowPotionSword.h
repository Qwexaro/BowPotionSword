#pragma once

#include <iostream>
#include <ctime>
#include "Interface.h"

class Bow : public ITake, public IDealDamage, public IGetDamage
{
	std::string name;
	int health;
	bool can_take;
public:
	Bow(std::string name);
	void use() override;
	void dealDamage() override;
	void getDamage() override;
	void getStatus() const override;
};


class Sword : public ITake, public IDealDamage, public IGetDamage
{
	std::string name;
	int health;
	bool can_take;
public:
	Sword(std::string name);
	void use() override;
	void dealDamage() override;
	void getDamage() override;
	void getStatus() const override;
};


class Potion : public ITake, public IDealDamage, public IGetDamage
{
	std::string name;
	int health;
	bool can_take;
public:
	Potion(std::string name);
	void use() override;
	void dealDamage() override;
	void getDamage() override;
	void getStatus() const override;
};


class Player : public ITake, public IDealDamage
{
	std::string name;
public:
	Player();
	Player(std::string name);
	void use() override;
	void dealDamage() override;
	void getStatus() const;

	Player& take(std::shared_ptr<ITake> takable_item);
	Player& damage(std::shared_ptr<IDealDamage> attack_item, std::shared_ptr<IGetDamage> get_dmg_item);
};