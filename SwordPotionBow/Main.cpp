#include "BowPotionSword.h"

int main()
{
	// ������� �����
	system("chcp 1251");
	srand(static_cast<int>(time(0)));
	Player player;
	
	std::shared_ptr<Bow>bow1 = std::make_shared<Bow>("�������");
	std::shared_ptr<Sword>sword1 = std::make_shared<Sword>("����������");
	std::shared_ptr<Potion>potion1 = std::make_shared<Potion>("���������");
	
	std::shared_ptr<Bow>bow2 = std::make_shared<Bow>("������ ������");
	std::shared_ptr<Sword>sword2 = std::make_shared<Sword>("������ ���� ��������");
	std::shared_ptr<Potion>potion2 = std::make_shared<Potion>("������ �����������");

	player.take(bow1);
	player.take(sword1);
	player.take(potion1);

	player.damage(bow2);
	player.damage(sword2);
	player.damage(potion2);

	return 0;
}