#include "BowPotionSword.h"

Bow::Bow(std::string name) : name{name}{}

Potion::Potion(std::string name) : name{ name }, is_pomegrate{static_cast<bool>(rand()%2)} {}

Sword::Sword(std::string name) : name{name}{}

void Bow::use()
{
	std::cout << "\nYou selected bow: " << name << std::endl;
}

void Bow::attack() 
{
	std::cout << "\nYou is attacked of bow: " << name << std::endl;
}

void Sword::use()
{
	std::cout << "\nYou selected sword: " << name << std::endl;
}

void Sword::attack()
{
	std::cout << "\nYou is attacked of sword: " << name << std::endl;
}

void Potion::use()
{
	std::cout << "\nYou selected potion: " << name << std::endl;
}

void Potion::attack()
{
	std::cout << "\nYou is attacked of potion: " << name << ", helth: " << std::endl;
}

Player::Player() : health{100} {}

Player& Player::take(std::shared_ptr<ITake>takable_item)
{
	takable_item->use(); return *this;
}

Player& Player::damage(std::shared_ptr<IAttack>attack_item)
{
	attack_item->attack(); return *this;
}

int Player::getHealth() const
{
	return health;
}

Player& Player::setHealth(int _damage)
{
	if (getHealth() > 0) health -= _damage;
	if (getHealth() < 0) health = 0;
	return *this;
}