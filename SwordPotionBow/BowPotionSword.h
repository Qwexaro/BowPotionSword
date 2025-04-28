#pragma once

#include <iostream>
#include "Interface.h"

class Bow : public ITake, public IDealDamage, public IGetDamage
{
	std::string name;
public:
	Bow(std::string name);
	void take() override;
	void dealDamage() override;
	void getDamage() override;
	void getStatus() const override;
};


class Sword : public ITake, public IDealDamage, public IGetDamage
{
	std::string name;

public:
	Sword(std::string name);
	void take() override;
	void dealDamage() override;
	void getDamage() override;
	void getStatus() const override;
};


class Potion : public ITake, public IDealDamage, public IGetDamage
{
	std::string name;
public:
	Potion(std::string name);
	void take() override;
	void dealDamage() override;
	void getDamage() override;
	void getStatus() const override;
};


class Player : public ITake, public IDealDamage, public IGetDamage
{
	std::string name;
	int health_player;
public:
	Player();
	void take() override;
	void dealDamage() override;
	void getDamage() override;
	void getStatus() const override;

	Player& take(std::shared_ptr<ITake> takable_item);
	Player& damage(std::shared_ptr<IDealDamage> attack_item, std::shared_ptr<IGetDamage> get_dmg_item);

	int getHealth() const;
};