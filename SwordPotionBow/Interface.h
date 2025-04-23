#pragma once

class ITake { public: virtual void use() = 0; };

class ITakeDamage { public: virtual void takeDamage() = 0; };

class IDealDamage { public: virtual void dealDamage() = 0; };

class IHealth { public: virtual void health() = 0; };