#pragma once

#include "DynamicObject.h"

class Bomb : public DynamicObject
{
public:

	static const uint16_t BombCost = 10; // стоимость бомбы в очках

	void Draw() const override;
	//-------
	virtual void __fastcall accept(Visitor& v) override
	{
		v.log(this);
	}
	//----------------
private:

};

