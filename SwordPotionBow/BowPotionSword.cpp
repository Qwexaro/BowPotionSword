#include "BowPotionSword.h"

Bow::Bow(std::string name) : name{name}{}

Potion::Potion(std::string name) : name{ name }, is_pomegrate{static_cast<bool>(rand()%2)} {}

Sword::Sword(std::string name) : name{name}{}

void Bow::use()
{
	std::cout << "\n�� ��������� ��� �������� ��: " << name << std::endl;
}

void Bow::dealDamage() 
{
	std::cout << "\n�� ��������: " << name << std::endl;
}

void Sword::use()
{
	std::cout << "\n�� ��������� ���: " << name << std::endl;
}

void Sword::dealDamage()
{
	std::cout << "\n������ ������� ����� �� ��������: " << name << std::endl;
}

void Potion::use()
{
	std::cout << "\n����� �������� ��: " << name << std::endl;
}

void Potion::dealDamage()
{
	std::cout << "\n���������� �������������� ��: " << name << ", �� ���������: " << std::endl;
}

Player::Player() : health_player{100} {}

void Player::use()
{
	std::cout << "\n����� �� ��������� "<< getHealth() << " �� �������� ���� �������� � �� �����������" << std::endl;
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
	std::cout << "��� ���� ������ ���" << std::endl;
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