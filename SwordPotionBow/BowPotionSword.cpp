#include "BowPotionSword.h"

Bow::Bow(std::string name) : name{ name }, health{60} {}

Potion::Potion(std::string name) : name{ name }, health{30} {}

Sword::Sword(std::string name) : name{ name }, health{95} {}


void Bow::getStatus() const
{
	std::cout << name << ", с текущим здоровьем: " << health;
}


void Player::getStatus() const
{
	std::cout << name;
}


void Sword::getStatus() const
{
	std::cout << name << ", с текущим здоровьем: " << health;
}

void Potion::getStatus() const
{
	std::cout << name << ", с текущим здоровьем: " << health;
}

void Bow::getDamage()
{
	// лук заколдован китайцами

	if (health > 0) 
	{
		health -= health;
		if (health < 0) health = 0;
		std::cout << "Китайские духи покинули данный лук."; 
	} 
	else
	{
		std::cout << "\nно обнаруживаете что лук " << name << " уже сломан.";
	}
}

void Sword::getDamage()
{
	if (health > 0)
	{
		health -= rand()%30+1;
		if (health < 0) health = 0;
	}
	else
	{
		std::cout << "\nно обнаруживаете что меч " << name << " уже сломан.";
	}
}

void Potion::getDamage()
{
	if (health > 0)
	{
		health -= rand() % 20 + 1;
		if (health < 0) health = 0;
	}
	else
	{
		std::cout << "\nно обнаруживаете что меч " << name << " уже сломан.";
	}
}

void Bow::use()
{
	std::cout << "\nВы подобрали лук варенный из: " << name << " со здоровьем: " << health << std::endl;
}

void Bow::dealDamage()
{
	std::cout << "\nСтреляющим луком на сковороде вы атакуете: ";
}

void Sword::use()
{
	std::cout << "\nВы подобрали меч из: " << name << " со здоровьем: " << health << std::endl;
}

void Sword::dealDamage()
{
	std::cout << "Мощным взмахом мечом вы атакуете: ";
}

void Potion::use()
{
	std::cout << "\nВы подобрали зелье из: " << name << " со здоровьем: " << health << std::endl;
}

void Potion::dealDamage()
{
	std::cout << "Используя зельеварку: " << name << ", вы атакуете здоровье игрока: ";
}

Player::Player() : name{"sanya"} {}
Player::Player(std::string name) : name{name}{}

void Player::use()
{
	std::cout << "\nИгрок с именем " << name << " не одобряет ваши действия и не подбирается" << std::endl;
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

void Player::dealDamage()
{
	std::cout << "тут пока ничего нет" << std::endl;
}