#pragma once
#include "Character.h"
#include<iostream>

class AnubisBaboon : public Character
{
public:
	AnubisBaboon();
	void activateSpecialAbility()const override;
	void monkeyEvolution() override;
	~AnubisBaboon() = default;
private:

};

