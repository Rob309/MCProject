#pragma once
#include "Vector2.h"
#include "iostream"
#include "Player.h"
#include "Arena.h"
#include "Tile.h"
#include "ConstantValues.h"

class Cast {
public:
	static GameObject* Raycast(Vector2 origin, Vector2 direction, float maxDistance);
	
};