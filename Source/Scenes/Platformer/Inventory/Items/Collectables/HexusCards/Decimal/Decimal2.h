#pragma once

#include "Scenes/Platformer/Inventory/Items/Collectables/HexusCards/HexusCard.h"

class LocalizedString;

class Decimal2 : public HexusCard
{
public:
	static Decimal2* create();

	Item* clone() override;
	std::string getItemName() override;
	LocalizedString* getString() override;
	std::string getIconResource() override;
	std::string getSerializationKey() override;

	static const std::string SaveKeyDecimal2;

protected:
	Decimal2();
	~Decimal2();

private:
	typedef HexusCard super;
};
