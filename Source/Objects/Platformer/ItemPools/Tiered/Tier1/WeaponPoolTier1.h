#pragma once

#include "Engine/Inventory/MinMaxPool.h"

class WeaponPoolTier1 : public MinMaxPool
{
public:
	static WeaponPoolTier1* create(SampleMethod sampleMethod, int min = 1, int max = 1);

protected:
	WeaponPoolTier1(SampleMethod sampleMethod, int min, int max);
	virtual ~WeaponPoolTier1();

private:
	typedef MinMaxPool super;
};
