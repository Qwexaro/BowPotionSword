#include "BowPotionSword.h"

Bow::Bow(std::string name) : name{name}{}

Potion::Potion(std::string name) : name{ name }, is_pomegrate{static_cast<bool>(rand()%2)} {}

Sword::Sword(std::string name) : name{name}{}

void Bow::use()
{
	std::cout << "\nВы подобрали лук варенный из: " << name << std::endl;
}

void Bow::dealDamage() 
{
	std::cout << "\nВы атакуете: " << name << std::endl;
}

void Sword::use()
{
	std::cout << "\nВы подобрали меч: " << name << std::endl;
}

void Sword::dealDamage()
{
	std::cout << "\nМощным взмахом мечом вы атакуете: " << name << std::endl;
}

void Potion::use()
{
	std::cout << "\nЗелье варенное из: " << name << std::endl;
}

void Potion::dealDamage()
{
	std::cout << "\nЗельеварка активировалась на: " << name << ", со здоровьем: " << std::endl;
}

Player::Player() : health_player{100} {}

void Player::use()
{
	std::cout << "\nИгрок со здоровьем "<< getHealth() << " не одобряет ваши действия и не подбирается" << std::endl;
}

Player& Player::take(std::shared_ptr<ITake>takable_item)
{
	takable_item->use(); return *this;
}

Player& Player::damage(std::shared_ptr<IDealDamage>attack_item)
{
	attack_item->dealDamage(); return *this;
}

int Player::getHealth() const
{
	return health_player;
}

void Player::dealDamage()
{
	std::cout << "тут пока ничего нет" << std::endl;
}

Player& Player::takeDamageOfEnemy(std::shared_ptr<ITakeDamage> dmg)
{
	dmg->takeDamage(); return *this;
}

//Player& Player::setHealth(int _damage)
//{
//	if (getHealth() > 0) health -= _damage;
//	if (getHealth() < 0) health = 0;
//	return *this;
//}