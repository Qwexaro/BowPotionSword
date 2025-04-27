#include "BowPotionSword.h"

int main()
{
	system("chcp 1251");
	srand(static_cast<int>(time(0)));
	Player player;

	std::shared_ptr<Player>enemy = std::make_shared<Player>("Vadim");
	std::shared_ptr<Bow>bow1 = std::make_shared<Bow>("Wind");
	std::shared_ptr<Sword>sword1 = std::make_shared<Sword>("Sword Star Platinum");
	std::shared_ptr<Potion>potion1 = std::make_shared<Potion>("Energ");

	player.take(bow1);
	player.take(sword1);
	player.take(potion1);

	player.damage(bow1, sword1);
	player.damage(sword1, bow1);
	player.damage(potion1, potion1);


	player.damage(bow1, sword1);
	player.damage(sword1, bow1);
	player.damage(potion1, potion1);

	player.damage(bow1, sword1);
	player.damage(sword1, bow1);
	player.damage(potion1, potion1);

	player.take(enemy);

}