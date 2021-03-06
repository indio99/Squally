#pragma once

#include "Scenes/Platformer/Inventory/Items/Recipes/Weapons/Axes/AxeRecipe.h"

class FrostAxePlans : public AxeRecipe
{
public:
	static FrostAxePlans* create();

	Item* craft() override;
	Item* clone() override;
	std::string getItemName() override;
	LocalizedString* getString() override;
	std::string getIconResource() override;
	std::string getCraftedItemIconResource() override;
	std::string getSerializationKey() override;

	static const std::string SaveKey;

protected:
	FrostAxePlans();
	virtual ~FrostAxePlans();
	
	std::vector<std::tuple<Item*, int>> getReagentsInternal() override;

private:
	typedef AxeRecipe super;
};
