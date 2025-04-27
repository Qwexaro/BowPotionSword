#pragma once

class ITake { public: virtual void use() = 0; };

class IAttack { public: virtual void attack() = 0; };

class IGetAttack { public: virtual void getAttack() = 0; };