#pragma once
#include "Character.h"

class HowlerMonkey : public Character
{
public:
	HowlerMonkey();
	void activateSpecialAbility() const override;
	void monkeyEvolution() override;
	~HowlerMonkey() = default;
private:
};

