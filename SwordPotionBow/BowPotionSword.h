
#pragma once
#include <iostream>

class ITake { virtual void use() = 0; };

class IAttack { virtual void attack() = 0; };

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
	Player& use(std::shared_ptr<ITake>takable_item);
	Player& attack(std::shared_ptr<IAttack>attack_item);
};