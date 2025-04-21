#include "BowPotionSword.h"

Bow::Bow(std::string name) : name{name}{}


void Bow::use()
{
	std::cout << "You selected bow: " << name;
}

void Bow::attack() 
{
	std::cout << "You is attacked of bow: " << name;
}

Sword::Sword(std::string name) : name{name}{}

void Sword::use()
{
	std::cout << "You selected sword: " << name;
}

void Sword::attack()
{
	std::cout << "You is attacked of sword: " << name;
}

Potion::Potion(std::string name) : name{name}{}

void Potion::use()
{
	std::cout << "You selected potion: " << name;
}

void Potion::attack()
{
	std::cout << "You is attacked of potion: " << name;
}

Player& Player::take(std::shared_ptr<ITake>takable_item)
{
	takable_item->use(); return *this;
}

Player& Player::damage(std::shared_ptr<IAttack>attack_item)
{
	attack_item->attack(); return *this;
}