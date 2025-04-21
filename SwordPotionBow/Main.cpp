#include "BowPotionSword.h"

int main()
{
	Player player;
	
	std::shared_ptr<Bow>bow1 = std::make_shared<Bow>("Golden");

	player.take(bow1);

	return 0;
}