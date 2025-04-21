#include <iostream>

class ITake 
{
	public: virtual void use() = 0;
};

class IThrow
{
	public: virtual void throwIt() = 0;
};

class QuestNote : public ITake
{
	std::string content;
public:
	QuestNote(std::string content) : content{content}{}
	void use() override
	{
		std::cout << "Вы взяли записку: " << content << std::endl;
	}	
};

class Stone : public ITake, public IThrow
{
	std::string material;
public:
	Stone(std::string material) : material{ material } {}
	void use() override
	{
		std::cout << "Вы взяли материал из: " << material << std::endl;
	}
	void throwIt() override
	{
		std::cout << "Вы бросили камень из: " << material << std::endl;
	}
};

class Player
{
	std::string name;
public:
	Player& take(std::shared_ptr<ITake>takable_item)
	{
		takable_item->use(); return *this;
	}
	Player& throwItem(std::shared_ptr<IThrow>throble_item)
	{
		throble_item->throwIt(); return *this;
	}
};

int main()
{
	system("chcp 1251");
	Player player;
	std::shared_ptr<QuestNote>note1 = std::make_shared<QuestNote>("Дима идет за тобой.");
	std::shared_ptr<Stone>stone1 = std::make_shared<Stone>("хлебушка");
	player.take(note1);
	player.take(stone1);
	player.throwItem(stone1);

	return 0;
}