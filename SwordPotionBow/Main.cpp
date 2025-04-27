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

	player.damage(bow1, sword2);
	player.damage(sword1, bow2);
	player.damage(potion1, potion2);

	// player.take(sword1).damage(player2); не подбирает а держит
	// sword.damage(player2); триггеры?
	// player.damage(Sword(player2)); по факту попало под меч

	return 0;
}