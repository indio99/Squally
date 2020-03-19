#pragma once

#include "Scenes/Platformer/Inventory/Items/Recipes/Weapons/Swords/SwordRecipe.h"

class DreadmournPlans : public SwordRecipe
{
public:
	static DreadmournPlans* create();

	Item* craft() override;
	Item* clone() override;
	std::string getItemName() override;
	LocalizedString* getString() override;
	std::string getIconResource() override;
	std::string getCraftedItemIconResource() override;
	std::string getSerializationKey() override;

	static const std::string SaveKey;

protected:
	DreadmournPlans();
	virtual ~DreadmournPlans();
	
	std::vector<std::tuple<Item*, int>> getReagentsInternal() override;

private:
	typedef SwordRecipe super;
};
