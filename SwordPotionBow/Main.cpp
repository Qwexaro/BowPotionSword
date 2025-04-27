#include "BowPotionSword.h"

int main()
{

	system("chcp 1251");
	srand(static_cast<int>(time(0)));
	Player player;
	
	std::shared_ptr<Player>enemy = std::make_shared<Player>();
	std::shared_ptr<Bow>bow1 = std::make_shared<Bow>("�������");
	std::shared_ptr<Sword>sword1 = std::make_shared<Sword>("����������");
	std::shared_ptr<Potion>potion1 = std::make_shared<Potion>("���������");
	
	std::shared_ptr<Bow>bow2 = std::make_shared<Bow>("������ �������");
	std::shared_ptr<Sword>sword2 = std::make_shared<Sword>("������ ���� ��������");
	std::shared_ptr<Potion>potion2 = std::make_shared<Potion>("������ �����������");

	player.take(bow1);
	player.take(sword1);
	player.take(potion1);

	player.damage(bow1, sword2);
	player.damage(sword1, bow2);
	player.damage(potion1, potion2);

	player.take(enemy);
	player.damage(sword1, enemy);

	return 0;
}