#include "BowPotionSword.h"

Bow::Bow(std::string name) : name{ name }, can_take{true}, health{60} {}

Potion::Potion(std::string name) : name{ name }, can_take{true}, health{30} {}

Sword::Sword(std::string name) : name{ name }, can_take{true}, health{95} {}

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
	std::cout << name << ", с текущим здоровьем: " << health << std::endl;
}

void Potion::getStatus() const
{
	std::cout << name << ", с текущим здоровьем: " << health << std::endl;
}

void Bow::getDamage()
{
	// лук заколдован китайцами
	if (health > 0) 
	{
		health -= health;
		if (health < 0) health = 0;
		std::cout << name << ". Китайские духи покинули данный лук." << std::endl;
		can_take = false;
	} 
	else
	{
		std::cout << "\nно обнаруживаете что лук " << name << " уже сломан." << std::endl;
	}
}

void Sword::getDamage()
{
	if (health > 0)
	{
		health -= rand()%30+1;
		if (health <= 0)
		{
			health = 0;
			can_take = false;
		}
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
		if (health < 0)
		{
			health = 0;
			can_take = false;
		}
	}
	else
	{
		std::cout << "\nно обнаруживаете что меч " << name << " уже сломан.";
	}
}

void Bow::use()
{
	if (can_take == true)
	{
		std::cout << "\nВы подобрали лук варенный из: " << name << " со здоровьем: " << health << std::endl;
	}
	else
	{
		std::cout << "*Вы смотрите на сломанный китайский лук*" << std::endl;
	}
}

void Bow::dealDamage()
{
	std::cout << "\nСтреляющим луком на сковороде вы атакуете: ";
}

void Sword::use()
{
	if (can_take == true)
	{
		std::cout << "\nВы подобрали меч из: " << name << " со здоровьем: " << health << std::endl;
	}
	else
	{
		std::cout << "*Вы смотрите на разрушенный меч*" << std::endl;
	}
}

void Sword::dealDamage()
{
	if (can_take == true) std::cout << "Мощным взмахом мечом вы атакуете ";
	else std::cout << "Вы просите меч восстановиться... Меч не чиниться";
}

void Potion::use()
{
	if (can_take == true)
	{
		std::cout << "\nВы подобрали зелье из: " << name << " со здоровьем: " << health << std::endl;
	}
	else
	{
		std::cout << "*Вы смотримте на осколки*" << std::endl;
	}
}

void Potion::dealDamage()
{
	std::cout << "Используя зельеварку: " << name << ", вы атакуете здоровье игрока";
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
	get_dmg_item->getDamage();
	get_dmg_item->getStatus();
	return *this;
}

void Player::dealDamage()
{
	std::cout << "тут пока ничего нет" << std::endl;
}