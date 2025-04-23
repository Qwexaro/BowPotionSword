#include "BowPotionSword.h"

int main()
{
	// Матушка земля
	system("chcp 1251");
	srand(static_cast<int>(time(0)));
	Player player;
	
	std::shared_ptr<Bow>bow1 = std::make_shared<Bow>("Золотой");
	std::shared_ptr<Sword>sword1 = std::make_shared<Sword>("Платиновый");
	std::shared_ptr<Potion>potion1 = std::make_shared<Potion>("Невидимый");
	
	std::shared_ptr<Bow>bow2 = std::make_shared<Bow>("Вражий золтой");
	std::shared_ptr<Sword>sword2 = std::make_shared<Sword>("Вражий стар платинум");
	std::shared_ptr<Potion>potion2 = std::make_shared<Potion>("Вражья невидимость");

	player.take(bow1);
	player.take(sword1);
	player.take(potion1);

	player.damage(bow2);
	player.damage(sword2);
	player.damage(potion2);

	return 0;
}