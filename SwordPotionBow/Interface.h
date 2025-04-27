#pragma once

class ITake {
public:
    virtual void use() = 0;
};

class IDealDamage {
public:
    virtual void dealDamage() = 0;
    virtual bool canTake() const = 0;
};

class IGetDamage {
public:
    virtual void getDamage() = 0;
    virtual bool canTake() const = 0;
    virtual void getStatus() const = 0;
};
