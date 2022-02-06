#pragma once

#include <stdint.h>

#include "DestroyableGroundObject.h"

class House : public DestroyableGroundObject
{
public:

	//---
	char look[7][14];
	//---


	bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	//void Draw() const override;

	virtual void Draw() const override;
private:

	const uint16_t score = 40;
};

class HouseBuilderA :public House {
private:
public:
	HouseBuilderA();
	friend class House;
	void Draw() const override;
};