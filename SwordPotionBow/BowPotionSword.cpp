#include "BowPotionSword.h"

// Добавлены флаги для проверки состояния предметов
Bow::Bow(std::string name) : name{ name }, can_take{ true }, health{ 60 } {}

Potion::Potion(std::string name) : name{ name }, can_take{ true }, health{ 30 } {}

Sword::Sword(std::string name) : name{ name }, can_take{ true }, health{ 95 } {}

void Bow::getStatus() const
{
    std::cout << name << ", с текущим здоровьем: " << health;
}

//void Player::getStatus() const
//{
//    std::cout << name;
//}

void Sword::getStatus() const
{
    std::cout << name << ", с текущим здоровьем: " << health << std::endl;
}

void Potion::getStatus() const
{
    std::cout << name << ", с текущим здоровьем: " << health << std::endl;
}

void Bow::getDamage()
{
    if (health > 0)
    {
        health -= health; // Разрушаем лук 
        if (health < 0) health = 0;
        std::cout << name << ". Китайские духи покинули данный лук." << std::endl;
        can_take = false; // Устанавливаем флаг can_take в false
    }
    else
    {
        std::cout << "\nно обнаруживаете что лук " << name << " уже сломан." << std::endl;
    }
}

void Sword::getDamage()
{
    if (health > 0)
    {
        health -= rand() % 30 + 1; // Наносим случайный урон
        if (health <= 0)
        {
            health = 0;
            can_take = false; // Устанавливаем флаг can_take в false, если меч сломан
        }
    }
    else
    {
        std::cout << "\nно обнаруживаете что меч " << name << " уже сломан." << std::endl;
    }
}

void Potion::getDamage()
{
    if (health > 0)
    {
        health -= rand() % 20 + 1; // Наносим случайный урон
        if (health < 0)
        {
            health = 0;
            can_take = false; // Устанавливаем флаг can_take в false, если зелье разрушено
        }
    }
    else
    {
        std::cout << "\nно обнаруживаете что зелье " << name << " уже сломано." << std::endl;
    }
}

void Bow::use()
{
    if (can_take)
    {
        std::cout << "\nВы подобрали лук варенный из: " << name << " со здоровьем: " << health << std::endl;
    }
    else
    {
        std::cout << "*Вы смотрите на сломанный китайский лук*" << std::endl;
    }
}

void Bow::dealDamage()
{
    if (can_take)
    {
        std::cout << "\nСтреляющим луком на сковороде вы атакуете: ";
    }
    else
    {
        std::cout << "*Нет смысла использовать сломанный лук*" << std::endl;
    }
}

void Sword::use()
{
    if (can_take)
    {
        std::cout << "\nВы подобрали меч из: " << name << " со здоровьем: " << health << std::endl;
    }
    else
    {
        std::cout << "*Вы смотрите на разрушенный меч*" << std::endl;
    }
}

void Sword::dealDamage()
{
    if (can_take)
    {
        std::cout << "Мощным взмахом мечом вы атакуете ";
    }
    else
    {
        std::cout << "Вы просите меч восстановиться... Меч не чиниться" << std::endl;
    }
}

void Potion::use()
{
    if (can_take)
    {
        std::cout << "\nВы подобрали зелье из: " << name << " со здоровьем: " << health << std::endl;
    }
    else
    {
        std::cout << "*Вы смотрите на осколки*" << std::endl;
    }
}

void Potion::dealDamage()
{
    if (can_take)
    {
        std::cout << "Используя зельеварку: " << name << ", вы атакуете здоровье игрока" << std::endl;
    }
    else
    {
        std::cout << "*Зелье не работает, оно сломано.*" << std::endl;
    }
}

Player::Player() : name{ "sanya" } {}
Player::Player(std::string name) : name{ name } {}

void Player::use()
{
    std::cout << "\nИгрок с именем " << name << " не одобряет ваши действия и не подбирается" << std::endl;
}

Player& Player::take(std::shared_ptr<ITake> takable_item)
{
    takable_item->use();
    return *this;
}

Player& Player::damage(std::shared_ptr<IDealDamage> attack_item, std::shared_ptr<IGetDamage> get_dmg_item)
{
    if (attack_item && attack_item->canTake()) // Проверяем, можно ли использовать предмет
    {
        attack_item->dealDamage();
    }
    else
    {
        std::cout << "Сломанный предмет не может нанести урон." << std::endl;
    }

    if (get_dmg_item && get_dmg_item->canTake())
    {
        get_dmg_item->getDamage();
        get_dmg_item->getStatus();
    }

    return *this;
}

//void Player::dealDamage()
//{
//    std::cout << "тут пока ничего нет" << std::endl;
//}
//
//
//void Player::canTake() const
//{
//    std::cout << "Вы берете самого себя в руки" << std::endl;
//}