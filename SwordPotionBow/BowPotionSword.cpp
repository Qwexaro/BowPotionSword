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
	std::cout << "\n��� ��������";
}

void Sword::getDamage()
{
	std::cout << "\n���� ��������.";
}

void Potion::getDamage()
{
	std::cout << "\n����� ����������� �� �������.";
}

void Bow::use()
{
	std::cout << "\n�� ��������� ��� �������� ��: " << name << std::endl;
}

void Bow::dealDamage()
{
	std::cout << "\n�� ��������: ";
}

void Sword::use()
{
	std::cout << "\n�� ��������� ���: " << name << std::endl;
}

void Sword::dealDamage()
{
	std::cout << "\n������ ������� ����� �� ��������: ";
}

void Potion::use()
{
	std::cout << "\n����� �������� ��: " << name << std::endl;
}

void Potion::dealDamage()
{
	std::cout << "\n���������� �������������� ��: " << name << std::endl;
}

Player::Player() : name{"sanya"}, health_player{100} {}

void Player::use()
{
	std::cout << "\n����� � ������ " << name << " � ��������� " 
		<< getHealth() << " �� �������� ���� �������� � �� �����������" << std::endl;
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
	std::cout << "��� ���� ������ ���" << std::endl;
}

void Player::getDamage()
{
	std::cout << "�� ����� ������" << std::endl;
}