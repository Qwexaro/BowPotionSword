#pragma once

class ITake { public: virtual void use() = 0; };

class IDealDamage { public: virtual void dealDamage() = 0; };

class IGetDamage { public: virtual void getDamage() = 0;  public: virtual void getStatus() const = 0; };