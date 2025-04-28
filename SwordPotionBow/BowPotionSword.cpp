#include "BowPotionSword.h"

Bow::Bow(std::string name) : name{name}{}

Potion::Potion(std::string name) : name{ name } {}

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
	std::cout << "\nЛук из "<< name << " сломался." << std::endl;
}

void Sword::getDamage()
{
	std::cout << "\nМечь из "<< name <<  " сломался." << std::endl;
}

void Potion::getDamage()
{
	std::cout << "\nЗелье из "<< name << " разлетелось на осколки.";
}

void Bow::take()
{
	std::cout << "\nВы подобрали лук варенный из: " << name << std::endl;
}

void Bow::dealDamage()
{
	std::cout << "\nЖаря лук на сковороде вы атакуете: ";
}

void Sword::take()
{
	std::cout << "\nВы подобрали меч: " << name << std::endl;
}

void Sword::dealDamage()
{
	std::cout << "\nМощным взмахом мечом вы атакуете: ";
}

void Potion::take()
{
	std::cout << "\nЗелье варенное из: " << name << std::endl;
}

void Potion::dealDamage()
{
	std::cout << "\nЗельеварка из " << name << " активировалась на : ";
}

Player::Player() : name{"Sanya"}, health_player{rand()%100+1} {}

void Player::take()
{
	std::cout << "\nИгрок с именем " << name << " и здоровьем " 
		<< getHealth() << " не одобряет ваши действия и не подбирается" << std::endl;
}

Player& Player::take(std::shared_ptr<ITake>takable_item)
{
	takable_item->take(); return *this;
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
	std::cout << "\nтут пока ничего нет" << std::endl;
}

void Player::getDamage()
{
	std::cout << "\nВы убили игрока" << std::endl;
}