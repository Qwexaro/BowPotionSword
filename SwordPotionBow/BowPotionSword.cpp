#include "BowPotionSword.h"

Bow::Bow(std::string name) : name{name}{}

Potion::Potion(std::string name) : name{ name }, is_pomegrate{static_cast<bool>(rand()%2)} {}

Sword::Sword(std::string name) : name{name}{}

void Bow::getStatus() const
{
	std::cout << name;
}

void Player::getStatus() const
{
	std::cout << name;
}

void Sword::getStatus() const
{
	std::cout << name;
}

void Potion::getStatus() const
{
	std::cout << name;
}

void Bow::getDamage()
{
	std::cout << "\nлук сломался";
}

void Sword::getDamage()
{
	std::cout << "\nМечь сломался.";
}

void Potion::getDamage()
{
	std::cout << "\nЗелье разлетелось на осколки.";
}

void Bow::use()
{
	std::cout << "\nВы подобрали лук варенный из: " << name << std::endl;
}

void Bow::dealDamage()
{
	std::cout << "\nВы атакуете: ";
}

void Sword::use()
{
	std::cout << "\nВы подобрали меч: " << name << std::endl;
}

void Sword::dealDamage()
{
	std::cout << "\nМощным взмахом мечом вы атакуете: ";
}

void Potion::use()
{
	std::cout << "\nЗелье варенное из: " << name << std::endl;
}

void Potion::dealDamage()
{
	std::cout << "\nЗельеварка активировалась на: " << name << std::endl;
}

Player::Player() : name{"sanya"}, health_player{100} {}

void Player::use()
{
	std::cout << "\nИгрок с именем " << name << " и здоровьем " 
		<< getHealth() << " не одобряет ваши действия и не подбирается" << std::endl;
}

Player& Player::take(std::shared_ptr<ITake>takable_item)
{
	takable_item->use(); return *this;
}

Player& Player::damage(std::shared_ptr<IDealDamage> attack_item, std::shared_ptr<IGetDamage> get_dmg_item)
{
	attack_item->dealDamage();
	get_dmg_item->getStatus();
	get_dmg_item->getDamage();
	return *this;
}

int Player::getHealth() const
{
	return health_player;
}

void Player::dealDamage()
{
	std::cout << "тут пока ничего нет" << std::endl;
}

void Player::getDamage()
{
	std::cout << "Вы убили игрока" << std::endl;
}