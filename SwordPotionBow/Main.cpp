#include "BowPotionSword.h"

int main()
{
	srand(static_cast<int>(time(0)));
	Player player1, player2;
	
	std::shared_ptr<Bow>bow1 = std::make_shared<Bow>("Golden");
	std::shared_ptr<Sword>sword1 = std::make_shared<Sword>("Platinum");
	std::shared_ptr<Potion>potion1 = std::make_shared<Potion>("Invisible");
	
	std::shared_ptr<Bow>bow2 = std::make_shared<Bow>("Enemy Golden");
	std::shared_ptr<Sword>sword2 = std::make_shared<Sword>("Enemy Platinum");
	std::shared_ptr<Potion>potion2 = std::make_shared<Potion>("Enemy Invisible");

	std::cout << "Player1 with health: " << player1.getHealth() << std::endl;
	std::cout << "Player2 with health: " << player2.getHealth() << std::endl;

	player1.take(bow1);
	player1.take(sword1);
	player1.take(potion1);

	player1.damage(bow2);
	player1.damage(sword2);
	player1.damage(potion2);

	return 0;
}