#include "BowPotionSword.h"

int main()
{
	system("chcp 1251");
	
	srand(time(int(0)));

	Player player("Jotaro Tokisky");

	std::shared_ptr<Player>ptr_player = std::make_shared<Player>("Vadim");

	std::shared_ptr<Sword>sword_vadima = std::make_shared<Sword>("Vadimsky Sword");
	std::shared_ptr<Sword>sword_jotaro = std::make_shared<Sword>("Sword Jotaro");


	std::shared_ptr<Bow>bow1 = std::make_shared<Bow>("Da");
	player.getStatus();

	player.take(ptr_player);
	player.take(sword_jotaro);
	player.take(sword_vadima);

	player.damage(sword_jotaro, sword_vadima);
	
	return 0;
}