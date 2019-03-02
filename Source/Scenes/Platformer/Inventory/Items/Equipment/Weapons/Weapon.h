#pragma once

#include "Scenes/Platformer/Inventory/Items/Equipment/Equipable.h"

class LocalizedString;

class Weapon : public Equipable
{
public:
	int getMinAttack();
	int getMaxAttack();

protected:
	Weapon(int minAttack, int maxAttack);
	virtual ~Weapon();

private:
	typedef Equipable super;

	int minAttack;
	int maxAttack;
};